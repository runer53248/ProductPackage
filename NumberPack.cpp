/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */

#include "NumberPack.h"

NumberPack NumberPack::operator+(const NumberPack& v)const {
    auto result = NumberPack{
        n + v.n,
        x + v.x,
        w + v.w,
        p + v.p};
    return result;
}

NumberPack NumberPack::operator-(const NumberPack& v)const {
    auto result = NumberPack{
        n - v.n,
        x - v.x,
        w - v.w,
        p - v.p};
    return result;
}

NumberPack NumberPack::operator+(const INTERNAL_TYPE v) const {
    auto result = NumberPack{
        n + v,
        x,
        w,
        p};
    return result;
}

NumberPack NumberPack::operator-(const INTERNAL_TYPE v) const {
    auto result = NumberPack{
        n - v,
        x,
        w,
        p};
    return result;
}

std::strong_ordering NumberPack::operator<=>(const NumberPack& that) const {
    if (const auto cmp = p <=> that.p; cmp != 0)
        return cmp;
    if (const auto cmp = w <=> that.w; cmp != 0)
        return cmp;
    if (const auto cmp = x <=> that.x; cmp != 0)
        return cmp;
    return n <=> that.n;
}