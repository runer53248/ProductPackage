/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */
#pragma once

#include <compare>
#include <array>

struct NumberPack{
    using INTERNAL_TYPE = int;
    
    INTERNAL_TYPE n;//units
    INTERNAL_TYPE x;//pack
    INTERNAL_TYPE w;//layer
    INTERNAL_TYPE p;//pallet
    
    NumberPack operator+(const NumberPack& v)const;
    NumberPack operator-(const NumberPack& v)const;
    NumberPack operator+(const INTERNAL_TYPE v)const;
    NumberPack operator-(const INTERNAL_TYPE v)const;
    bool operator==(const NumberPack&) const = default;
    std::strong_ordering operator<=>(const NumberPack& that) const;
};
