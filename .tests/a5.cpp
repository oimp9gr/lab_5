#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include <string>
#include <ostream>
#include <sstream>

#include "../solutions/a5.h"

using namespace std;

TEST_CASE("a5: Example", "[task:a5]") {
    SECTION("Case 1") {
        auto actual = GetFrequencies("aaa");
        map<string, int> expected = {{"AAA", 1}};
        REQUIRE(actual == expected);
    }

    SECTION("Case 2") {
        auto actual = GetFrequencies("aaabbb");
        map<string, int> expected = {{"AAA", 1}, {"AAB", 1}, {"ABB", 1}, {"BBB", 1}};
        REQUIRE(actual == expected);
    }

    SECTION("Case 3") {
        auto actual = GetFrequencies("aba!,. b.a");
        map<string, int> expected = {{"ABA", 2}, {"BAB", 1}};
        REQUIRE(actual == expected);
    }
}

TEST_CASE("a5: Different delimiter", "[task:a5]") {
    SECTION("Spaces") {
        auto actual = GetFrequencies("   a    a\na\t   ");
        map<string, int> expected = {{"AAA", 1}};
        REQUIRE(actual == expected);
    }

    SECTION("Punctuation") {
        auto actual = GetFrequencies("a-+.,{}}/(\'a\"a=b\"b\'b)");
        map<string, int> expected = {{"AAA", 1}, {"AAB", 1}, {"ABB", 1}, {"BBB", 1}};
        REQUIRE(actual == expected);
    }

    SECTION("Digits") {
        auto actual = GetFrequencies("a1b2a34b567a89");
        map<string, int> expected = {{"ABA", 2}, {"BAB", 1}};
        REQUIRE(actual == expected);
    }
}

TEST_CASE("a5: Big letters", "[task:a5]") {
    auto actual = GetFrequencies("AaAaA");
    map<string, int> expected = {{"AAA", 3}};
    REQUIRE(actual == expected);
}
