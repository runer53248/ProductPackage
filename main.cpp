/* 
 * Author: Runer53248 <runer53248@gmail.com>
 * Created on 9 lutego 2021, 13:30
 */

#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <fmt/locale.h>
#include <type_traits>
#include "ProductPackage.h"
#include "Number.h"
#include "Product.h"
#include <list>

int main(int argc, char **argv)
{
    //system("chcp 1250>nul");

    //dodawanie i odejmowanie liczb
    std::cout << "2-5+7-8+2     = " << 2_unit - 5 + 7 - 8 + 2 << "\n";
    std::cout << "2-(5+7)-8+2   = " << 2_unit - (5 + 7) - 8 + 2 << "\n";
    std::cout << "2+5+7-8-2     = " << 2_unit + 5 + 7 - 8 - 2 << "\n";
    std::cout << "2+5w+7-8w-2   = " << 2_unit + 5_layer + 7 - 8_layer - 2 << "\n";

    //rodzaje wartości
    std::cout << "1n = " << 1_unit << "\n";
    std::cout << "1x = " << 1_package << "\n";
    std::cout << "1w = " << 1_layer << "\n";
    std::cout << "1p = " << 1_pallet << "\n";
    std::cout << "0n = " << 0_unit << "\n";
    std::cout << "0x = " << 0_package << "\n";
    std::cout << "0w = " << 0_layer << "\n";
    std::cout << "0p = " << 0_pallet << "\n";

    auto number = 1_unit + 1_package + 1_layer + 1_pallet;
    std::cout << "number = 1n+1x+1w+1p =     " << number << "\n";

    number = 1_unit + 1_package - 1_layer + 1_pallet;
    std::cout << "number = 1n+1x-1w+1p =     " << number << "\n";

    auto number2 = 1_unit + 1_layer + 1_pallet + 1_package - 1_layer;
    std::cout << "number2 = 1n+1w+1p+1x-1w = " << number2 << "\n";
    std::cout << "Kawa 500g + number =       " << "Kawa 500g"_unit + number << "\n";
    std::cout << "number + Kawa 500g =       " << number + "Kawa 500g"_unit << "\n";
    std::cout << "Kawa 500g 1x =             " << "Kawa 500g"_unit + 1_package << "\n";
    std::cout << "1p =                       " << 1_pallet << "\n";
    std::cout << "5x+3w  =                   " << 5_package + 3_layer << "\n";
    std::cout << "5w+3x  =                   " << 5_layer + 3_package << "\n";

    auto product = "Kawa 500g"_unit;
    std::cout << "Kawa 500g     =            " << product << "\n";
    std::cout << "Kawa 500g 1p  =            " << product + 1_pallet << "\n";
    std::cout << "Kawa 500g 5w+3x  =         " << product + 5_layer + 3_package << "\n";

    product = "Napoje 500ml"_unit;
    std::cout << "Napoje 500ml 1p =          " << product + 1_pallet << "\n";
    std::cout << "Napoje 500ml (5w+3x) =     " << product + (5_layer + 3_package) << "\n";

    product = "Mleko UHT 1l"_unit;
    std::cout << "1p Mleko UHT 1l =          " << 1_pallet + product << "\n";
    std::cout << "5w+3x Mleko UHT 1l =       " << 5_layer + 3_package + product << "\n";
    std::cout << "(1p - 1w) Mleko UHT 1l =   " << (1_pallet - 1_layer) + product << "\n";

    std::cout << "2n < 2n = " << std::boolalpha << (2_unit < 2_unit) << "\n";
    std::cout << "2n < 3n = " << std::boolalpha << (2_unit < 3_unit) << "\n";

    return 0;
}
