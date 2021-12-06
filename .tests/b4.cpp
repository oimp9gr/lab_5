#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b4.h"

using namespace std;


TEST_CASE("b4: Example", "[task:b4]") {
    MinMaxQueue q;
    q.Push(10);
    q.Push(3);
    q.Push(-5);
    REQUIRE(q.GetMax() == 10);
    REQUIRE(q.GetMin() == -5);
    REQUIRE(q.Pop() == 10);
    REQUIRE(q.GetMax() == 3);
    REQUIRE(q.GetMin() == -5);
}

TEST_CASE("b4: Test many pushes", "[task:b4]") {
    MinMaxQueue q;
    for (int i = 0; i < 100; ++i) {
        q.Push(i);
    }
    REQUIRE(q.GetMax() == 99);
    REQUIRE(q.GetMin() == 0);
}

TEST_CASE("b4: Test many pushes and pops", "[task:b4]") {
    MinMaxQueue q;
    for (int i = 0; i < 10; ++i) {
        q.Push(i);
        REQUIRE(q.GetMax() == i);
        REQUIRE(q.GetMin() == 0);
    }

    for (int i = 1; i < 10; ++i) {
        q.Pop();
        REQUIRE(q.GetMin() == i);
        REQUIRE(q.GetMax() == 9);
    }
    q.Pop();
    for (int i = 0; i < 10; ++i) {
        q.Push(i);
        REQUIRE(q.GetMax() == i);
        REQUIRE(q.GetMin() == 0);
    }

    for (int i = 1; i < 10; ++i) {
        q.Pop();
        REQUIRE(q.GetMin() == i);
        REQUIRE(q.GetMax() == 9);
    }
}

TEST_CASE("b4: Test throwing", "[task:b4]") {
    MinMaxQueue q;
    REQUIRE_THROWS_AS(q.Pop(), std::out_of_range);
    q.Push(1);
    q.Pop();
    REQUIRE_THROWS_AS(q.Pop(), std::out_of_range);
    REQUIRE_THROWS_AS(q.GetMin(), std::out_of_range);
    REQUIRE_THROWS_AS(q.GetMax(), std::out_of_range);
}

TEST_CASE("b4: Stress test", "[task:b4]") {
    MinMaxQueue q;
    int m_max = 1;
    int m_min = 1;
    for (int i = 1; i < 500000; ++i, ++m_max) {
        q.Push(i);
        if (i % 100 == 0) {
            q.Pop();
            m_min++;
        }
        REQUIRE(q.GetMax() == m_max);
        REQUIRE(q.GetMin() == m_min);
    }
}