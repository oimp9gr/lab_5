#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/b1.h"

#include <string>

using namespace std;

static const string file = "input.txt";

using util::trim;

string GetActual() {
    ifstream ifs(file);
    string actual, tmp;
    while (getline(ifs, tmp)) {
        actual += tmp + "\n";
    }
    ifs.close();
    actual = trim(actual);
    return actual;
}

TEST_CASE("b1: Example", "[task:b1]") {
    string test = "3 + 5\n"
                  "1 - 3\n"
                  "17 * 9";
    string expected = "3 + 5 = 8\n"
                      "1 - 3 = -2\n"
                      "17 * 9 = 153";
    ofstream of(file);
    of << test;
    of.close();
    MathematicalOperation mo(file);
    mo.Solve();
    string actual = GetActual();
    REQUIRE(expected == actual);
}

TEST_CASE("b1: Big numbers", "[task:b1]") {
    string test = "2000000000 + 2000000000\n"
                  "2000000000 - 2000000000\n"
                  "2000000000 * 2000000000";
    string expected = "2000000000 + 2000000000 = 4000000000\n"
                      "2000000000 - 2000000000 = 0\n"
                      "2000000000 * 2000000000 = 4000000000000000000";
    ofstream of("input.txt");
    of << test;
    of.close();
    MathematicalOperation mo("input.txt");
    mo.Solve();
    string actual = GetActual();
    REQUIRE(expected == actual);
}

TEST_CASE("b1: Negative numbers", "[task:b1]") {
    string test = "-10 + 5\n"
                  "-10 - 5\n"
                  "-10 - -5\n"
                  "-2000000000 * -2000000000\n"
                  "-2000000000 * 2000000000";
    string expected = "-10 + 5 = -5\n"
                      "-10 - 5 = -15\n"
                      "-10 - -5 = -5\n"
                      "-2000000000 * -2000000000 = 4000000000000000000\n"
                      "-2000000000 * 2000000000 = -4000000000000000000";
    ofstream of("input.txt");
    of << test;
    of.close();
    MathematicalOperation mo("input.txt");
    mo.Solve();
    string actual = GetActual();
    REQUIRE(expected == actual);
}

TEST_CASE("b1: Auto generated expressions", "[task:b1]") {
    srand( (unsigned)time(NULL) );
    vector<char>operations = {'+', '-', '*'};
    for (size_t i = 0; i < 100; ++i) {
        int64_t lhs = rand();
        int64_t rhs = rand();
        int64_t result;
        char operation = operations[rand() % 2];

        if (operation == '+') {
            result = lhs + rhs;
        } else if (operation == '-') {
            result = lhs - rhs;
        } else {
            result = lhs * rhs;
        }

        string test_string = to_string(lhs) + " " + operation + " " + to_string(rhs);
        ofstream of(file);
        of << test_string;
        of.close();

        string expected = to_string(lhs) + " " + operation + " " + to_string(rhs) + " = " + to_string(result);

        MathematicalOperation mo(file);
        mo.Solve();

        string actual = GetActual();
        REQUIRE(expected == actual);
    }
}