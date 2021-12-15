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

#include "../solutions/a2.h"

using namespace std;

TEST_CASE("a2: Test forbidden includes", "[task:a2]") {
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

TEST_CASE("a2: Example", "[task:a2]") {
    Matrix matr(3, 3);
    stringstream in("3 3 1 2 3 4 5 6 7 8 9");
    in >> matr;
    stringstream out;
    out << matr;
    string actual = util::trim(out.str());
    REQUIRE(actual == "1 2 3\n4 5 6\n7 8 9");
    Matrix matr1;
    matr1 = matr;
    REQUIRE(matr1 == matr);
}

TEST_CASE("a2: Test operator >>", "[task:a2]") {
    SECTION("Height = 3, width = 1") {
        Matrix matr;
        stringstream in("3 1 1 2 3");
        in >> matr;
        stringstream out;
        out << matr;
        string actual = util::trim(out.str());
        REQUIRE(actual == "1\n2\n3");
    }

    SECTION("Height = 1, width = 3") {
        Matrix matr;
        stringstream in("1 3 1 2 3");
        in >> matr;
        stringstream out;
        out << matr;
        string actual = util::trim(out.str());
        REQUIRE(actual == "1 2 3");
    }
}

TEST_CASE("a2: Test operator =", "[task:a2]") {
    Matrix matr, matr1;
    stringstream in("2 3 1 2 3 4 5 6"), out;
    in >> matr;

    matr1 = matr;

    out << matr1;
    string actual = util::trim(out.str());
    REQUIRE(actual == "1 2 3\n4 5 6");
}

TEST_CASE("a2: Test operator ==", "[task:a2]") {
    SECTION("Test true") {
        Matrix matr(8,5), matr1(8, 5);
        REQUIRE(matr == matr1);

        stringstream ss("2 3 1 2 3 4 5 6");
        ss >> matr;
        stringstream ss1("2 3 1 2 3 4 5 6");
        ss1 >> matr1;
        REQUIRE(matr == matr1);
    }

    SECTION("Test false") {
        Matrix matr(8,5), matr1(9, 5);
        REQUIRE_FALSE(matr == matr1);

        stringstream ss("2 3 1 2 3 4 5 9");
        ss >> matr;
        stringstream ss1("2 3 1 2 3 4 5 6");
        ss1 >> matr1;
        REQUIRE_FALSE(matr == matr1);

        stringstream ss2("2 2 1 2 3 4");
        ss2 >> matr;
        stringstream ss3("2 2 2 2 3 4");
        ss3 >> matr1;
        REQUIRE_FALSE(matr == matr1);

        stringstream ss4("1 2 1 2");
        ss4 >> matr;
        stringstream ss5("2 2 2 2 3 4");
        ss5 >> matr1;
        REQUIRE_FALSE(matr == matr1);
    }
}