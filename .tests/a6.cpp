#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include <stdexcept>

using namespace std;

#define queue util::ForbiddenQueue

#include "../solutions/a6.h"


TEST_CASE("a6: Example", "[task:a6]") {
    Queue q;
    string actual, expected;
    q.Push(10);
    q.Push(8);
    actual = util::trim(q.Print());
    expected = "10 8";
    REQUIRE(actual == expected);
    REQUIRE(q.Pop() == 10);
    actual = util::trim(q.Print());
    REQUIRE(actual == "8");
}

TEST_CASE("a6: Print test", "[task:a6]") {
    string actual, expected;
    SECTION("One element") {
        Queue q;
        q.Push(1);
        actual = util::trim(q.Print());
        expected = "1";
        REQUIRE(actual == expected);
    }

    SECTION("Zero elements") {
        Queue q;
        q.Push(1);
        q.Pop();
        actual = util::trim(q.Print());
        expected = "";
        REQUIRE(actual == expected);
    }

    SECTION("Many elements") {
        Queue q;
        expected = "";
        for (int i = 0; i < 10; ++i) {
            expected += to_string(i) + " ";
            q.Push(i);
        }
        expected = util::trim(expected);
        actual = util::trim(q.Print());
        REQUIRE(actual == expected);
    }
}

TEST_CASE("a6: Test throwing", "[task:a6]") {
    Queue q;
    q.Push(100);
    q.Pop();
    REQUIRE_THROWS_AS(q.Pop(), std::out_of_range);
}

TEST_CASE("a6: Stress test", "[task:a6]") {
    Queue q;
    for (int i = 0; i < 500000; ++i) {
        q.Push(i);
    }
    for (int i = 0; i < 500000; ++i) {
        q.Pop();
    }
}