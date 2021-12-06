#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/a3.h"

#include <string>
#include <fstream>

using namespace std;

vector<string> GetResult(string test) {
    string input_file = "input.txt";
    string output_file = "sorted.txt";
    ofstream f0(input_file);
    f0 << test;
    f0.close();

    ReadAndSort();

    ifstream f1(output_file);
    vector<string> actual;
    string tmp;
    while (getline(f1, tmp)) {
        actual.push_back(tmp);
    }
    f1.close();
    return actual;
}

TEST_CASE("a3: Example", "[task:a3]") {
    vector<string> expected = {"audi a5 2020 white 5000",
        "audi a6 2020 black 50000",
        "audi a4 2020 red 50000",
        "audi a7 2019 black 100000"};
    string test = "audi a4 2020 red 50000\n"
                  "audi a5 2020 white 5000\n"
                  "audi a6 2020 black 50000\n"
                  "audi a7 2019 black 100000";
    auto actual = GetResult(test);
    REQUIRE(expected == actual);
}

TEST_CASE("a3: Test by components", "[task:a3]") {
    SECTION("By mark") {
        string test = "d a1 2020 red 5000\n"
                      "b a1 2020 red 5000\n"
                      "c a1 2020 red 5000\n"
                      "a a1 2020 red 5000";
        vector<string> expected = {"a a1 2020 red 5000",
            "b a1 2020 red 5000",
            "c a1 2020 red 5000",
            "d a1 2020 red 5000"};
        auto actual = GetResult(test);
        REQUIRE(expected == actual);
    }

    SECTION("By model") {
        string test = "a a1 2020 red 5000\n"
                      "a a4 2020 red 5000\n"
                      "a a2 2020 red 5000\n"
                      "a a3 2020 red 5000";
        vector<string> expected = {"a a1 2020 red 5000",
            "a a2 2020 red 5000",
            "a a3 2020 red 5000",
            "a a4 2020 red 5000"};
        auto actual = GetResult(test);
        REQUIRE(expected == actual);
    }

    SECTION("By year") {
        string test = "a a1 2017 red 5000\n"
                      "a a1 2015 red 5000\n"
                      "a a1 2021 red 5000\n"
                      "a a1 2020 red 5000";
        vector<string> expected = {"a a1 2021 red 5000",
            "a a1 2020 red 5000",
            "a a1 2017 red 5000",
            "a a1 2015 red 5000"};
        auto actual = GetResult(test);
        REQUIRE(expected == actual);
    }

    SECTION("By color") {
        string test = "a a1 2020 white 5000\n"
                      "a a1 2020 red 5000\n"
                      "a a1 2020 gray 5000\n"
                      "a a1 2020 green 5000";
        vector<string> expected = {"a a1 2020 gray 5000",
            "a a1 2020 green 5000",
            "a a1 2020 red 5000",
            "a a1 2020 white 5000"};
        auto actual = GetResult(test);
        REQUIRE(expected == actual);
    }

    SECTION("By mileage") {
        string test = "a a1 2020 white 100\n"
                      "a a1 2020 white 101\n"
                      "a a1 2020 white 5000\n"
                      "a a1 2020 white 10000";
        vector<string> expected = {"a a1 2020 white 100",
            "a a1 2020 white 101",
            "a a1 2020 white 5000",
            "a a1 2020 white 10000"};
        auto actual = GetResult(test);
        REQUIRE(expected == actual);
    }
}

TEST_CASE("a3: Different components all together", "[task:a3]") {
    vector<string> expected = {"a a3 6 red 50",
        "a a4 6 red 50",
        "a a1 5 black 5",
        "a a2 5 black 5",
        "a a2 5 red 5",
        "a a2 5 white 5",
        "a a1 3 white 5",
        "a a3 3 white 50",
        "a a3 3 black 100",
        "a a2 2 black 50",
        "a a1 1 white 100",
        "aa a1 3 red 100",
        "aa a2 2 white 5",
        "aa a1 1 white 5",
        "bb a2 7 black 5",
        "bb a3 7 white 50",
        "bb a2 6 black 5",
        "bb a1 5 black 100",
        "bb a1 4 black 100",
        "bb a1 4 red 100",
        "bb a1 4 white 100",
        "bb a3 3 white 5",
        "bb a3 3 red 100",
        "bb a2 2 black 50",
        "bb a2 2 white 100",
        "bb a1 1 red 5",
        "bb a1 1 black 50",
        "c a2 2 red 50",
        "c a3 1 red 5",
        "c a3 1 white 5",
        "c a3 1 red 100",
        "cc a1 3 red 5",
        "cc a3 1 red 100",
        "cc a4 1 red 100",
        "cc a5 1 red 100",
        "cc a6 1 red 100"};
    string test = "a a3 6 red 50\n"
                  "a a4 6 red 50\n"
                  "a a3 3 black 100\n"
                  "a a1 3 white 5\n"
                  "a a2 2 black 50\n"
                  "a a1 1 white 100\n"
                  "a a2 5 white 5\n"
                  "a a2 5 red 5\n"
                  "a a2 5 black 5\n"
                  "a a1 5 black 5\n"
                  "a a3 3 white 50\n"
                  "aa a1 3 red 100\n"
                  "aa a2 2 white 5\n"
                  "aa a1 1 white 5\n"
                  "bb a2 7 black 5\n"
                  "bb a3 7 white 50\n"
                  "bb a2 6 black 5\n"
                  "bb a1 5 black 100\n"
                  "bb a1 4 red 100\n"
                  "bb a1 4 black 100\n"
                  "bb a1 4 white 100\n"
                  "bb a3 3 white 5\n"
                  "bb a3 3 red 100\n"
                  "bb a2 2 black 50\n"
                  "bb a2 2 white 100\n"
                  "bb a1 1 red 5\n"
                  "bb a1 1 black 50\n"
                  "c a2 2 red 50\n"
                  "c a3 1 red 5\n"
                  "c a3 1 white 5\n"
                  "c a3 1 red 100\n"
                  "cc a1 3 red 5\n"
                  "cc a3 1 red 100\n"
                  "cc a4 1 red 100\n"
                  "cc a5 1 red 100\n"
                  "cc a6 1 red 100";
    auto actual = GetResult(test);
    REQUIRE(expected == actual);
}