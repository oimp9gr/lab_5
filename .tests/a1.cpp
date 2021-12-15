#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include <string>
#include <ostream>

#ifdef _GLIBCXX_VECTOR
#undef _GLIBCXX_VECTOR
#endif

#ifdef _GLIBCXX_DEQUE
#undef _GLIBCXX_DEQUE
#endif

#ifdef _GLIBCXX_QUEUE
#undef _GLIBCXX_QUEUE
#endif

#ifdef _GLIBCXX_ARRAY
#undef _GLIBCXX_ARRAY
#endif

#include "../solutions/a1.h"

using namespace std;

TEST_CASE("a1: Test forbidden includes", "[task:a1]") {
    SECTION("Don't include std::vector") {
#ifdef _GLIBCXX_VECTOR
        REQUIRE(false);
#endif
    }

    SECTION("Don't include std::deque") {
#ifdef _GLIBCXX_DEQUE
        REQUIRE(false);
#endif
    }

    SECTION("Don't include std::queue") {
#ifdef _GLIBCXX_QUEUE
        REQUIRE(false);
#endif
    }

    SECTION("Don't include std::array") {
#ifdef _GLIBCXX_ARRAY
        REQUIRE(false);
#endif
    }
}

TEST_CASE("a1: Example", "[task:a1]") {
    Matrix empty;
    REQUIRE(empty.GetWidth() == 0);
    REQUIRE(empty.GetHeight() == 0);

    Matrix zeroes(2, 2);
    REQUIRE(zeroes.GetWidth() == 2);
    REQUIRE(zeroes.GetHeight() == 2);

    stringstream ss;
    ss << zeroes;
    string actual = util::trim(ss.str());
    REQUIRE(actual == "0 0\n0 0");
}

TEST_CASE("a1: Test const", "[task:a1]") {
    const Matrix empty;
    REQUIRE(empty.GetWidth() == 0);
    REQUIRE(empty.GetHeight() == 0);
}

TEST_CASE("a1: Test operator <<", "[task:a1]") {
    SECTION("Empty matrix") {
        Matrix empty;
        stringstream ss;
        ss << empty;
        string actual = ss.str();
        REQUIRE(actual == "");
    }

    SECTION("Height 3 width 1") {
        Matrix matr(3, 1);
        stringstream ss;
        ss << matr;
        string actual = util::trim(ss.str());
        REQUIRE(actual == "0\n0\n0");
        ss.clear();
    }
    SECTION("Height 1 width 3") {
        Matrix matr1(1, 3);
        stringstream ss;
        ss << matr1;
        string actual = util::trim(ss.str());
        REQUIRE(actual == "0 0 0");
    }
}