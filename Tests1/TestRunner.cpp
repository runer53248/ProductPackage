
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <fmt/locale.h>
#include <type_traits>

#include "../Product.h"

TEST_CASE("NumberPack: Larger values", "[NumberPack]") {
    NumberPack number = NumberPack{1, 2, 3, 4};
    NumberPack number2 = NumberPack{4, 3, 2, 1};
    //p > w > x > n
    REQUIRE(number > number2);
}

TEST_CASE("Adding and substracting values", "[Number]") {
    Number number = 2_unit + 5_layer + 7 - 8_layer - 2;
    Number number2 = 7_unit - 3_layer;

    REQUIRE(number == number2);
}

TEST_CASE("Equivelent values", "[Number]") {
    Number number = 1_unit + 1_package + 1_layer + 1_pallet;
    Number number2 = 1_unit + 1_package + 1_layer + 1_pallet;
    Number number3 = 1_layer + 1_pallet + 1_unit + 1_package;

    REQUIRE(number == number2);
    REQUIRE(number == number3);
}

TEST_CASE("Number: Larger values", "[Number]") {
    auto number = 1_unit + 1_package + 1_layer + 1_pallet;
    auto number2 = 2_unit + 1_package + 1_layer + 1_pallet;
    auto number3 = 1_unit + 2_package + 1_layer + 1_pallet;
    auto number4 = 1_unit + 1_package + 2_layer + 1_pallet;
    auto number5 = 1_unit + 1_package + 1_layer + 2_pallet;

    auto number6 = 2_unit + 1_package + 2_layer + 3_pallet;
    auto number7 = 1_unit - 1_package + 1_layer + 4_pallet;

    REQUIRE(number < number2);
    REQUIRE(number < number3);
    REQUIRE(number < number4);
    REQUIRE(number < number5);

    REQUIRE(number2 < number6);
    REQUIRE(number3 < number6);

    REQUIRE(number < number7);

    REQUIRE(number4 < number5);
    REQUIRE(number3 < number4);
    REQUIRE(number2 < number3);
    REQUIRE(number6 < number7);
}

TEST_CASE("test2", "[ProductPackage]") {
    auto prodPack = ProductPackage{};
    REQUIRE(prodPack.name.compare("DEFAULT") == 0);
    REQUIRE(prodPack.x == 1);
    REQUIRE(prodPack.w == 1);
    REQUIRE(prodPack.p == 1);
}

TEST_CASE("test3", "[PackingData]") {
    auto packData = PackingData{1,2,3};
    REQUIRE(packData.x == 1);
    REQUIRE(packData.w == 2);
    REQUIRE(packData.p == 3);
}

TEST_CASE("test4", "[Product]") {
    auto product = Product{5, ProductPackage{"Product 1", 12, 8, 10}};
    
    REQUIRE(product.getNumber() == 5);
    REQUIRE(product.getPackingData().x == 12);
    REQUIRE(product.getPackingData().w == 8);
    REQUIRE(product.getPackingData().p == 10);
    REQUIRE(product.getPackingData() == PackingData{12,8,10});
}