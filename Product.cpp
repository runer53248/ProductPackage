/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */

#include "Product.h"

int Product::getNumber() const noexcept
{
    return value;
}

PackingData Product::getPackingData() const noexcept
{
    return PackingData{product.x, product.w, product.p};
}

std::string Product::print() const
{
    std::string result{};
    result += std::to_string(value);
    result += "\t<\"" + product.name + "\", package = " + std::to_string(product.x) + " units"
    + ", layer = " + std::to_string(product.w) + " packages"
    + ", pallet = " + std::to_string(product.p) + " layers>";
    return result;
}

Product operator+(const Product &p, const int v2)
{
    int resultValue;
    resultValue = p.getNumber() + v2;
    return Product{resultValue, p};
}

Product operator+(const Product &p, const Number &v2)
{
    int resultValue;
    const auto v2last = v2.getHistory().back();
    int v2value = v2last.n;
    int v2xValue = v2last.x;
    int v2wValue = v2last.w;
    int v2pValue = v2last.p;

    resultValue = p.getNumber() + v2value;
    auto packing = p.getPackingData();
    resultValue += v2xValue * packing.x;
    resultValue += v2wValue * packing.w * packing.x;
    resultValue += v2pValue * packing.p * packing.w * packing.x;

    return Product{resultValue, p};
}

Product operator-(const Product &p, const int v2)
{
    int resultValue;
    resultValue = p.getNumber() - v2;
    return Product{resultValue, p};
}

Product operator-(const Product &p, const Number &v2)
{
    int resultValue;
    const auto v2last = v2.getHistory().back();
    int v2value = v2last.n;
    int v2xValue = v2last.x;
    int v2wValue = v2last.w;
    int v2pValue = v2last.p;

    resultValue = p.getNumber() - v2value;
    auto packing = p.getPackingData();
    resultValue -= v2xValue * packing.x;
    resultValue -= v2wValue * packing.w * packing.x;
    resultValue -= v2pValue * packing.p * packing.w * packing.x;
    return Product{resultValue, p};
}

std::ostream &operator<<(std::ostream &os, const Product &num)
{
    os << num.print();
    return os;
}

Product operator""_unit(const char *text, size_t size)
{
    static std::vector<ProductPackage> base{
        {"Kawa 250g", 12, 19, 9},
        {"Kawa 500g", 12, 12, 6},
        {"Napoje 330ml", 24, 9, 11},
        {"Napoje 1l", 6, 21, 4},
        {"Napoje 500ml", 12, 18, 8},
        {"Mleko UHT 1l", 12, 12, 5}};

    for (auto &productPackage : base)
    {
        if (productPackage.name.compare(text) == 0)
        {
            return Product{0, productPackage};
        }
    }
    throw std::logic_error("unknown product");
}