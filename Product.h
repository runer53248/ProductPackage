/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */
#pragma once

#include <ostream>
#include "ProductPackage.h"
#include "Number.h"
#include <assert.h>

struct Product
{
    Product(int value, ProductPackage product) : value(value), product(product) {}
    Product(int value, Product base) : value(value), product(base.product) {}

    [[nodiscard]] int getNumber() const noexcept;
    [[nodiscard]] PackingData getPackingData() const noexcept;
    std::string print() const;

private:
    int value = 0;
    ProductPackage product;
};

Product operator+(const Product &p, const int v2);
Product operator+(const Product &p, const Number &v2);
Product operator-(const Product &p, const int v2);
Product operator-(const Product &p, const Number &v2);

std::ostream &operator<<(std::ostream &os, const Product &num);
Product operator""_unit(const char *text, size_t size);
