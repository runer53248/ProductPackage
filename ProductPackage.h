/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */
#pragma once

#include <string>

struct ProductPackage
{
    std::string name = "DEFAULT";
    int x = 1; //package
    int w = 1; //package per layer
    int p = 1; //layers per pallet
};

struct PackingData
{
    int x; //package
    int w; //package per layer
    int p; //layers per pallet

    PackingData(int x, int w, int p) : x(x), w(w), p(p) {}
    bool operator==(const PackingData &) const = default;
};
