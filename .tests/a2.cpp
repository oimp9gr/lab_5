#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include <stdexcept>

#define stack ForbiddenStack

#include "../solutions/a2.h"

using namespace std;

TEST_CASE("a2: Example", "[task:a2]") {
    Stack st;
    st.Push(10);
    st.Push(8);
    REQUIRE(util::trim(st.Print()) == "8 10");
    REQUIRE(st.Pop() == 8);
    REQUIRE(util::trim(st.Print()) == "10");
}

TEST_CASE("a2: Empty", "[task:a2]") {
    Stack st;
    REQUIRE_THROWS_AS(st.Pop(), std::out_of_range);
    st.Push(3);
    st.Pop();
    REQUIRE_THROWS_AS(st.Pop(), std::out_of_range);
}

TEST_CASE("a2: Ten pushbacks and popbacks", "[task:a2]") {
    Stack st;
    for (int i = 0; i < 10; ++i) {
        st.Push(i);
    }

    REQUIRE(util::trim(st.Print()) == "9 8 7 6 5 4 3 2 1 0");

    for (int i = 9; i >= 0; --i) {
        REQUIRE(st.Pop() == i);
    }
}