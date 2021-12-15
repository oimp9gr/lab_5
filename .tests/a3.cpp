#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include <string>
#include <ostream>
#include <sstream>

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

#include "../solutions/a3.h"

using namespace std;

TEST_CASE("a3: Test forbidden includes", "[task:a3]") {
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

string to_string(const Matrix&matr) {
    stringstream ss;
    ss << matr;
    return ss.str();
}

TEST_CASE("a3: Example", "[task:a3]") {
    Matrix matr(2, 2);
    matr += 5;
    matr += matr;
    --matr;

    string actual = util::trim(to_string(matr));
    REQUIRE(actual == "9 9\n9 9");

    Matrix matr2 = matr + matr;

    actual = util::trim(to_string(matr2));;
    REQUIRE(actual == "18 18\n18 18");

    actual = util::trim(to_string(matr));
    REQUIRE(actual == "9 9\n9 9");
}

TEST_CASE("a3: Operators +=, -=", "[task:a3]") {
    SECTION("+=") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        stringstream ss1("2 3 3 2 1 3 2 1");
        ss1 >> matr1;
        matr += matr1;
        stringstream ss2("2 3 4 4 4 4 4 4");
        ss2 >> expected;
        REQUIRE(matr == expected);
    }

    SECTION("-=") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        stringstream ss1("2 3 3 2 1 3 2 1");
        ss1 >> matr1;
        matr -= matr1;
        stringstream ss2("2 3 -2 0 2 -2 0 2");
        ss2 >> expected;
        REQUIRE(matr == expected);
    }
}

TEST_CASE("a3: Operators +, - with another matrix", "[task:a3]") {
    SECTION("+") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        stringstream ss1("2 3 3 2 1 3 2 1");
        ss1 >> matr1;
        Matrix actual = matr + matr1;
        stringstream ss2("2 3 4 4 4 4 4 4");
        ss2 >> expected;
        REQUIRE(actual == expected);
    }

    SECTION("-") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        stringstream ss1("2 3 3 2 1 3 2 1");
        ss1 >> matr1;
        Matrix actual = matr - matr1;
        stringstream ss2("2 3 -2 0 2 -2 0 2");
        ss2 >> expected;
        REQUIRE(actual == expected);
    }

    SECTION("Chain") {
        Matrix matr(2, 2), expected;
        matr += 5;
        Matrix actual;
        actual = matr + matr + matr;
        stringstream ss2("2 2 15 15 15 15");
        ss2 >> expected;
        REQUIRE(actual == expected);
    }
}

TEST_CASE("a3: Operators +, - with number", "[task:a3]") {
    SECTION("matrix + number") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        Matrix actual = matr + 5;
        stringstream ss2("2 3 6 7 8 6 7 8");
        ss2 >> expected;
        REQUIRE(actual == expected);
    }

    SECTION("number + matrix") {
        Matrix matr, matr1, expected;
        stringstream ss("2 3 1 2 3 1 2 3");
        ss >> matr;
        Matrix actual = 5 + matr;
        stringstream ss2("2 3 6 7 8 6 7 8");
        ss2 >> expected;
        REQUIRE(actual == expected);
    }
}