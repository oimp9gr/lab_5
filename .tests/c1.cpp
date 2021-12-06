#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"
#include "../solutions/c1.h"

#include <vector>
#include <string>
#include <set>
#include <stdexcept>

using namespace std;

TEST_CASE("c1: Example", "[task:c1]") {
    ChessPiece rook(PieceType::ROOK, "E5");
    REQUIRE_FALSE(rook.TryMove("C4"));
    REQUIRE_FALSE(!rook.TryMove("F5"));
    REQUIRE(rook.GetCoordinates() == "F5");
    auto vector_result = rook.GetPossibleMoves();
    set<string> expected = {"E5", "D5", "C5", "B5", "A5", "F4", "F3", "F2", "F1", "F6", "F7", "F8", "G5", "H5"};
    set<string> result(vector_result.begin(), vector_result.end());
    REQUIRE(expected == result);
}

TEST_CASE("c1: Coordinates of pieces near border", "[task:c1]") {
    SECTION("Rook near border") {
        ChessPiece rook(PieceType::ROOK, "A1");
        set<string> expected = {"A2", "A3", "A4", "A5", "A6", "A7", "A8", "B1", "C1", "D1", "E1", "F1", "G1", "H1"};
        auto vector_result = rook.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        REQUIRE(expected == result);
    }

    SECTION("King near border") {
        ChessPiece king(PieceType::KING, "A1");
        set<string> expected = {"A2", "B1", "B2"};
        auto vector_result = king.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        REQUIRE(expected == result);
    }

    SECTION("Knight near border") {
        ChessPiece knight(PieceType::KNIGHT, "A1");
        set<string> expected = {"B3", "C2"};
        auto vector_result = knight.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        REQUIRE(expected == result);
    }
}

TEST_CASE("c1: Exception throwing and handling", "[task:c1]") {
    SECTION("Exception throwing") {
        SECTION("Rook") {
            ChessPiece rook(PieceType::ROOK, "A1");
            REQUIRE_THROWS_AS(rook.Move("B2"), std::invalid_argument);
            REQUIRE_THROWS_AS(rook.Move("B8"), std::invalid_argument);
            REQUIRE_THROWS_AS(rook.Move("C8"), std::invalid_argument);
        }

        SECTION("Knight") {
            ChessPiece knight(PieceType::KNIGHT, "A1");
            REQUIRE_THROWS_AS(knight.Move("C3"), std::invalid_argument);
            REQUIRE_THROWS_AS(knight.Move("B4"), std::invalid_argument);
            REQUIRE_THROWS_AS(knight.Move("C1"), std::invalid_argument);
        }

        SECTION("King") {
            ChessPiece king(PieceType::KING, "A1");
            REQUIRE_THROWS_AS(king.Move("A3"), std::invalid_argument);
            REQUIRE_THROWS_AS(king.Move("C1"), std::invalid_argument);
            REQUIRE_THROWS_AS(king.Move("B3"), std::invalid_argument);
        }
    }

    SECTION("Exception handling") {
        bool actual;
        SECTION("Rook") {
            ChessPiece rook(PieceType::ROOK, "A1");
            actual = false;
            REQUIRE_NOTHROW(actual |= rook.TryMove("B2"));
            REQUIRE_NOTHROW(actual |= rook.TryMove("B8"));
            REQUIRE_NOTHROW(actual |= rook.TryMove("C8"));
            REQUIRE_FALSE(actual);
        }

        SECTION("Knight") {
            ChessPiece knight(PieceType::KNIGHT, "A1");
            actual = false;
            REQUIRE_NOTHROW(actual |= knight.TryMove("C3"));
            REQUIRE_NOTHROW(actual |= knight.TryMove("B4"));
            REQUIRE_NOTHROW(actual |= knight.TryMove("C1"));
            REQUIRE_FALSE(actual);
        }

        SECTION("King") {
            ChessPiece king(PieceType::KING, "A1");
            actual = false;
            REQUIRE_NOTHROW(actual |= king.TryMove("A3"));
            REQUIRE_NOTHROW(actual |= king.TryMove("C1"));
            REQUIRE_NOTHROW(actual |= king.TryMove("B3"));
        }
    }
}

TEST_CASE("c1: Test moving using Move and TryMove methods", "[task:c1]") {
    SECTION("Moving rook") {
        ChessPiece rook(PieceType::ROOK, "A1");
        rook.Move("D1");
        REQUIRE(rook.GetCoordinates() == "D1");
        rook.Move("D8");
        REQUIRE(rook.GetCoordinates() == "D8");
        rook.Move("C8");
        REQUIRE(rook.GetCoordinates() == "C8");
        auto vector_result = rook.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        set<string> expected = {"B8", "A8", "D8", "E8", "F8", "G8", "H8", "C1", "C2", "C3", "C4", "C5", "C6", "C7"};
        REQUIRE(expected == result);
    }

    SECTION("Moving king") {
        ChessPiece king(PieceType::KING, "C4");
        king.Move("D4");
        REQUIRE(king.GetCoordinates() == "D4");
        king.Move("D3");
        REQUIRE(king.GetCoordinates() == "D3");
        king.Move("E3");
        REQUIRE(king.GetCoordinates() == "E3");
        king.Move("F4");
        REQUIRE(king.GetCoordinates() == "F4");
        auto vector_result = king.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        set<string> expected = {"E3", "E4", "E5", "F3", "F5", "G3", "G4", "G5"};
        REQUIRE(expected == result);
    }

    SECTION("Moving knight") {
        ChessPiece knight(PieceType::KNIGHT, "A1");
        knight.Move("B3");
        REQUIRE(knight.GetCoordinates() == "B3");
        knight.Move("D2");
        REQUIRE(knight.GetCoordinates() == "D2");
        knight.Move("E4");
        REQUIRE(knight.GetCoordinates() == "E4");
        knight.Move("C5");
        REQUIRE(knight.GetCoordinates() == "C5");
        auto vector_result = knight.GetPossibleMoves();
        set<string> result(vector_result.begin(), vector_result.end());
        set<string> expected = {"A6", "A4", "B3", "B7", "D3", "D7", "E4", "E6"};
        REQUIRE(expected == result);
    }
}