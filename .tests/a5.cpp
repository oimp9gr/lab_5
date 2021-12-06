#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include "../solutions/a5.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> ReadField();
void PrintField();


TEST_CASE("a5: Example", "[task:a5]") {
    PrintField();
    REQUIRE(MakeMark(3, 3) == true);
    REQUIRE(MakeMark(3, 3) == false);
    REQUIRE(MakeMark(1, 2) == true);
    vector<string> expected{".....", ".....", ".X...", "...X.", "....."};
    auto actual = ReadField();
    REQUIRE(expected == actual);
}

TEST_CASE("a5: Wrong coordinates", "[task:a5]") {
    PrintField();
    MakeMark(3, 3);
    REQUIRE(MakeMark(3, 3) == false);
    REQUIRE(MakeMark(3, 10) == false);
    REQUIRE(MakeMark(10, 3) == false);
    REQUIRE(MakeMark(10, 10) == false);
}

TEST_CASE("a5: Check borders", "[task:a5]") {
    SECTION("First  row") {
        PrintField();
        for (size_t i = 0; i < 5; ++i) {
            REQUIRE(MakeMark(i, 0) == true);
        }
        vector<string> expected = {"XXXXX", ".....", ".....", ".....", "....."};
        vector<string> actual = ReadField();
        REQUIRE(expected == actual);
    }

    SECTION("First  column") {
        PrintField();
        for (size_t i = 0; i < 5; ++i) {
            REQUIRE(MakeMark(0, i) == true);
        }
        vector<string> expected = {"X....", "X....", "X....", "X....", "X...."};
        vector<string> actual = ReadField();
        REQUIRE(expected == actual);
    }

    SECTION("Last  row") {
        PrintField();
        for (size_t i = 0; i < 5; ++i) {
            REQUIRE(MakeMark(i, 4) == true);
        }
        vector<string> expected = {".....", ".....", ".....", ".....", "XXXXX"};
        vector<string> actual = ReadField();
        REQUIRE(expected == actual);
    }

    SECTION("Last  row") {
        PrintField();
        for (size_t i = 0; i < 5; ++i) {
            REQUIRE(MakeMark(4, i) == true);
        }
        vector<string> expected = {"....X", "....X", "....X", "....X", "....X"};
        vector<string> actual = ReadField();
        REQUIRE(expected == actual);
    }
}


void PrintField() {
    ofstream f("file.txt");
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            f << '.';
        }
        f << '\n';
    }
}

vector<string> ReadField() {
    ifstream f("file.txt");
    string buffer;
    vector<string> result;
    while (getline(f, buffer)) {
        result.push_back(buffer);
    }
    return result;
}