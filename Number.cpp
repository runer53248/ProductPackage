/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */

#include "Number.h"

std::string Number::print()const{
    std::string result{};
    const auto last = history.back();
    if (last.n) result += std::to_string(last.n) + "n";
    if (last.x) result += std::to_string(last.x) + "x";
    if (last.w) result += std::to_string(last.w) + "w";
    if (last.p) result += std::to_string(last.p) + "p";
    if (!last.n && !last.x && !last.w && !last.p) result += "0";

    result += " (";
    bool first = false;
    for(const auto& hist_unitum: history){
        if(first){
            result += " | ";
        }
        if (hist_unitum.n) result += std::to_string(hist_unitum.n) + "n";
        if (hist_unitum.x) result += std::to_string(hist_unitum.x) + "x";
        if (hist_unitum.w) result += std::to_string(hist_unitum.w) + "w";
        if (hist_unitum.p) result += std::to_string(hist_unitum.p) + "p";
        if (!hist_unitum.n && !hist_unitum.x && !hist_unitum.w && !hist_unitum.p) result += "0";
        first = true;
    }
    result += ")";
    return result;
}

bool Number::operator==(const Number& that) const{
    const auto last = history.back();
    const auto thatlast = that.getHistory().back();
    return (last == thatlast);
}

std::strong_ordering Number::operator<=>(const Number& that) const{
    const auto last = history.back();
    const auto thatlast = that.getHistory().back();
    return last <=> thatlast;
}

Number operator+(const Number& v, const int v2) {
    std::vector<NumberPack> hist = v.getHistory();
    const auto vlast = hist.back();
    hist.push_back(vlast + v2);
    auto result = Number{
        std::move(hist)
    };
    return result;
}

Number operator+(const Number& v, const Number& v2) {
    std::vector<NumberPack> hist = v.getHistory();
    const auto vlast = hist.back();
    auto v2last = v2.getHistory().back();

    hist.push_back(vlast + v2last);
    auto result = Number{
        std::move(hist)
    };
    return result;
}

Number operator-(const Number& v, const int v2){
    std::vector<NumberPack> hist = v.getHistory();
    const auto vlast = hist.back();
    hist.push_back(vlast-v2);
    auto result = Number{
        std::move(hist)
    };
    return result;
}

Number operator-(const Number& v, const Number& v2){
    std::vector<NumberPack> hist = v.getHistory();
    const auto vlast = hist.back();
    auto v2last = v2.getHistory().back();

    hist.push_back(vlast-v2last);
    auto result = Number{
        std::move(hist)
    };
    return result;
}

std::ostream& operator<<(std::ostream& os, const Number& num){
     os << num.print();
     return os;
}

Number operator""_unit(unsigned long long int value) {
    return Number{static_cast<int> (value)};
}

Number operator""_package(unsigned long long int value) {
    return Number{0, static_cast<int> (value)};
}

Number operator""_layer(unsigned long long int value) {
    return Number{0, 0, static_cast<int> (value)};
}

Number operator""_pallet(unsigned long long int value) {
    return Number{0, 0, 0, static_cast<int> (value)};
}