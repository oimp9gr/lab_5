#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b3.h"

using namespace std;

#define list util::ForbiddenList

TEST_CASE("b3: Example", "[task:b3]") {
    List lst;
    lst.PushBack(10);
    lst.PushFront(8);
    lst.Insert(1, 9);
    string actual = util::trim(lst.Print());
    REQUIRE(actual == "8 9 10");
}

TEST_CASE("b3: Test PushBack and PopFront", "[task:b3]") {
    List lst;
    for (size_t i = 0; i < 10; ++i) {
        lst.PushBack(i);
    }
    auto string_representation = util::trim(lst.Print());
    REQUIRE(string_representation == "0 1 2 3 4 5 6 7 8 9");
    for (size_t i = 0; i < 10; ++i) {
        REQUIRE(lst.PopFront() == i);
    }
}

TEST_CASE("b3: Test PushFront and PopBack", "[task:b3]") {
    List lst;
    for (size_t i = 0; i < 10; ++i) {
        lst.PushFront(i);
    }
    auto string_representation = util::trim(lst.Print());
    REQUIRE(string_representation == "9 8 7 6 5 4 3 2 1 0");
    for (size_t i = 0; i < 10; ++i) {
        REQUIRE(lst.PopBack() == i);
    }
    REQUIRE(util::trim(lst.Print()) == "");
}

TEST_CASE("b3: Test Insert", "[task:b3]") {
    SECTION("Insert in first and last position") {
        List lst;
        lst.Insert(0, 100);
        lst.Insert(1, 200);
        REQUIRE(util::trim(lst.Print()) == "100 200");
    }

    SECTION("Many inserts in random positions") {
        List lst;
        for (size_t i = 0; i < 100; ++i) {
            REQUIRE_NOTHROW(lst.Insert(i ? int(rand() % i) : 0, i));
        }
    }

    SECTION("Test insert in wrong position throws an exception") {
        List lst;
        REQUIRE_THROWS_AS(lst.Insert(1, 0), std::out_of_range);
        lst.PushBack(10);
        lst.PushBack(20);
        lst.PushBack(30);
        REQUIRE_THROWS_AS(lst.Insert(5, 40), std::out_of_range);
    }
}

TEST_CASE("b3: Test Erase", "[task:b3]") {
    SECTION("Test erase from first and last positions") {
        List lst;
        lst.PushBack(10);
        REQUIRE_NOTHROW(lst.Erase(10));
        REQUIRE(util::trim(lst.Print()) == "");
        lst.PushBack(10);
        lst.PushBack(20);
        lst.PushBack(30);
        REQUIRE_NOTHROW(lst.Erase(30));
        REQUIRE(util::trim(lst.Print()) == "10 20");
    }

    SECTION("Test many deletions") {
        List lst;
        for (size_t i = 0; i < 20; ++i) {
            lst.Insert(i ? int(rand() % i) : 0, i);
        }
        for (int i = 19; i >= 0; --i) {
            lst.Erase(i);
        }
        REQUIRE(util::trim(lst.Print()) == "");
    }

    SECTION("Test return value") {
        List lst;
        lst.PushBack(10);
        REQUIRE(lst.Erase(10) == true);
        REQUIRE(lst.Erase(10) == false);
    }
}