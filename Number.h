/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */
#pragma once

#include <ostream>
#include <assert.h>
#include <vector>
#include "NumberPack.h"
#include <concepts>

struct Number {
public:
    explicit Number(int value, int x = 0, int w = 0, int p = 0) 
    : history{{value, x, w, p}}
    {}
    
    Number(NumberPack nums) 
    : history{nums}
    {}

    Number(std::vector<NumberPack>&& history) 
    : history(std::move(history)) 
    {}

    const std::vector<NumberPack>& getHistory()const {
        return history;
    }
    std::string print()const;

    bool operator==(const Number& that) const;
    std::strong_ordering operator<=>(const Number& that) const;
private:
    std::vector<NumberPack> history{{0, 0, 0, 0}};
};

template<typename T, typename T2>
concept NumberOperatorable = requires(T a, T2 b){
    (std::is_same<T, Number>::value && std::convertible_to<T2, NumberPack::INTERNAL_TYPE>)
    || (std::convertible_to<T, NumberPack::INTERNAL_TYPE> && std::is_same<T2, Number>::value)
    || (std::is_same<T, Number>::value && std::is_same<T2, Number>::value);
};

/*template<typename T, NumberOperatorable<T> T2>
auto operator+(const T &&v, const T2 &&v2){
    
    auto sumNumber = [](const Number &base, const NumberPack::INTERNAL_TYPE value){
        std::vector<NumberPack> hist = base.getHistory();
        const auto vlast = hist.back();
        
        hist.push_back(vlast + value);
        auto result = Number{
            std::move(hist)
        };
        return result;
    };
    
    if constexpr(std::is_same<T, Number>::value){
        if constexpr(std::is_same<T2, Number>::value){
            return sumNumber(v, v2.getHistory().back());
        }else{
            return sumNumber(v, v2);
        }
    }else{
        return sumNumber(v2, v);
    }
}*/

template<typename T>
auto operator+(const Number& v, const T& v2) {
    return v2 + v;
}
Number operator+(const Number& v, const int v2);
Number operator+(const Number& v, const Number& v2);

template<typename T>
auto operator-(const Number& v, const T& v2) {
    return v2 - v;
}
Number operator-(const Number& v, const int v2);
Number operator-(const Number& v, const Number& v2);

std::ostream& operator<<(std::ostream& os, const Number& num);
Number operator""_unit(unsigned long long int value);
Number operator""_package(unsigned long long int value);
Number operator""_layer(unsigned long long int value);
Number operator""_pallet(unsigned long long int value);
