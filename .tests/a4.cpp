#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a4.h"

using namespace std;

TEST_CASE("a4: Example", "[task:a4]") {
    REQUIRE(isValidParentheses("()[]{}") == true);
    REQUIRE(isValidParentheses("(]") == false);
    REQUIRE(isValidParentheses("([)]") == false);
    REQUIRE(isValidParentheses("{[]}") == true);
}

TEST_CASE("a4: Check balanced", "[task:a4]") {
    REQUIRE(isValidParentheses("()") == true);
    REQUIRE(isValidParentheses("[]") == true);
    REQUIRE(isValidParentheses("{}") == true);
    REQUIRE(isValidParentheses("{[{({{[]}})}]}") == true);
    REQUIRE(isValidParentheses("[()]{}{[()()]()}") == true);
}

TEST_CASE("a4: Check unbalanced", "[task:a4]") {
    SECTION("Single parentheses") {
        REQUIRE(isValidParentheses("(") == false);
        REQUIRE(isValidParentheses("[") == false);
        REQUIRE(isValidParentheses("{") == false);
        REQUIRE(isValidParentheses(")") == false);
        REQUIRE(isValidParentheses("]") == false);
        REQUIRE(isValidParentheses("}") == false);
    }

    SECTION("Double parentheses") {
        REQUIRE(isValidParentheses("[}") == false);
        REQUIRE(isValidParentheses("(}") == false);
        REQUIRE(isValidParentheses("(]") == false);
        REQUIRE(isValidParentheses("{]") == false);
        REQUIRE(isValidParentheses("{)") == false);
        REQUIRE(isValidParentheses("[)") == false);
    }

    SECTION("No wrong sequences") {
        REQUIRE(isValidParentheses("{()]") == false);
        REQUIRE(isValidParentheses("[()}") == false);
        REQUIRE(isValidParentheses("{[[]]]") == false);
    }

    SECTION("Complicated") {
        REQUIRE(isValidParentheses("{([]([)[]])}") == false);
        REQUIRE(isValidParentheses("{{({{[]}})}]}") == false);
        REQUIRE(isValidParentheses("[()]{{[()()]()}") == false);
    }
}
