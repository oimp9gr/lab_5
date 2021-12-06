#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b2.h"

#include <string>

using namespace std;

TEST_CASE("b2: Example", "[task:b2]") {
    Number n1(4);
    Number n2(2000000000);
    Number n3 = n1.Add(n1);
    REQUIRE(n3.GetData() == 8);
    REQUIRE(n1.GetData() == 8);
    string result = PrintMultiplicationResult(n1, n2);
    REQUIRE(result == "overflow: 16000000000");
}

TEST_CASE("b2: Test operations", "[task:b2]") {
    SECTION("Test Add") {
        SECTION("Simple") {
            Number n1(-10);
            Number n2(12);
            Number n3 = n1.Add(n2);
            REQUIRE(n3.GetData() == 2);
        }

        SECTION("Overflow") {
            Number n1(2000000000);
            REQUIRE_THROWS_AS(n1.Add(n1), Number::Overflow);
            try {
                n1.Add(n1);
            } catch (Number::Overflow value) {
                REQUIRE(value.data == int64_t(4000000000));
            }
        }

        SECTION("Underflow") {
            Number n1(-2000000000);
            REQUIRE_THROWS_AS(n1.Add(n1), Number::Underflow);
            try {
                n1.Add(n1);
            } catch (Number::Underflow value) {
                REQUIRE(value.data == int64_t(-4000000000));
            }
        }
    }

    SECTION("Test Sub") {
        SECTION("Simple") {
            Number n1(-10);
            Number n2(12);
            Number n3 = n1.Sub(n2);
            REQUIRE(n3.GetData() == -22);
        }

        SECTION("Overflow") {
            Number n1(2000000000);
            Number n2(-2000000000);
            REQUIRE_THROWS_AS(n1.Sub(n2), Number::Overflow);
            try {
                n1.Sub(n2);
            } catch (Number::Overflow value) {
                REQUIRE(value.data == int64_t(4000000000));
            }
        }

        SECTION("Underflow") {
            Number n1(-2000000000);
            Number n2(2000000000);
            REQUIRE_THROWS_AS(n1.Sub(n2), Number::Underflow);
            try {
                n1.Sub(n2);
            } catch (Number::Underflow value) {
                REQUIRE(value.data == int64_t(-4000000000));
            }
        }
    }

    SECTION("Test Mult") {
        SECTION("Simple") {
            Number n1(-10);
            Number n2(12);
            Number n3 = n1.Mul(n2);
            REQUIRE(n3.GetData() == -120);
        }

        SECTION("Overflow") {
            Number n1(200000000);
            Number n2(200000000);
            REQUIRE_THROWS_AS(n1.Mul(n2), Number::Overflow);
            try {
                n1.Mul(n2);
            } catch (Number::Overflow value) {
                REQUIRE(value.data == int64_t(40000000000000000));
            }
        }

        SECTION("Underflow") {
            Number n1(-200000000);
            Number n2(200000000);
            REQUIRE_THROWS_AS(n1.Mul(n2), Number::Underflow);
            try {
                n1.Mul(n2);
            } catch (Number::Underflow value) {
                REQUIRE(value.data == int64_t(-40000000000000000));
            }
        }
    }

    SECTION("Test Div") {
        SECTION("Simple") {
            Number n1(-10);
            Number n2(2);
            Number n3 = n1.Div(n2);
            REQUIRE(n3.GetData() == -5);
        }

        SECTION("Zero division") {
            Number n1(20);
            Number n2(0);
            REQUIRE_THROWS_AS(n1.Div(n2), Number::DivideByZero);
        }
    }
}

TEST_CASE("b2: Test PrintMultiplicationResult", "[task:b2]") {
    SECTION("Overflow") {
        Number n1(200000000);
        REQUIRE(PrintMultiplicationResult(n1, n1) == "overflow: 40000000000000000");
    }

    SECTION("Underflow") {
        Number n1(200000000);
        Number n2(-200000000);
        REQUIRE(PrintMultiplicationResult(n1, n2) == "underflow: -40000000000000000");
    }
}