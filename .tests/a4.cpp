#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "util.h"

#include <string>
#include <ostream>
#include <sstream>
#include <stdexcept>

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

#include "../solutions/a4.h"

using namespace std;

TEST_CASE("a4: Test forbidden includes", "[task:a4]") {
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

string to_string(const Matrix &matr) {
    stringstream ss;
    ss << matr;
    return ss.str();
}

Matrix create_matrix(const string &str) {
    Matrix matr;
    stringstream ss(str);
    ss >> matr;
    return matr;
}

TEST_CASE("a4: Example", "[task:a4]") {
    Matrix matr = create_matrix("3 3 1 2 3 4 5 6 7 8 9");
    Matrix expected = create_matrix("3 3 30 36 42 66 81 96 102 126 150");

    Matrix result = matr *= matr;

    string actual = util::trim(to_string(result));
    REQUIRE(actual == util::trim(to_string(expected)));

    REQUIRE_NOTHROW(matr[2][2] = 42);
    REQUIRE(matr[2][2] == 42); // 42
}

TEST_CASE("a4: Test multiplication", "[task:a4]") {
    SECTION("Square matrices") {
        SECTION("1x1 matrix") {
            Matrix lhs = create_matrix("1 1 1");
            Matrix rhs = create_matrix("1 1 -1");
            Matrix actual = lhs * rhs;
            Matrix expected = create_matrix("1 1 -1");
            REQUIRE(util::trim(to_string(actual)) == util::trim(to_string(expected)));
        }

        SECTION("2x2 with negative numbers") {
            Matrix lhs = create_matrix("2 2 -83 -86 -77 -15");
            Matrix rhs = create_matrix("2 2 93 35 86 92");
            Matrix actual = lhs * rhs;
            Matrix expected = create_matrix("2 2 -15115 -10817 -8451 -4075");
            REQUIRE(util::trim(to_string(actual)) == util::trim(to_string(expected)));
        }

        SECTION("10x10") {
            Matrix lhs = create_matrix("10 10\n"
                                       "83 86 77 15 93 35 86 92 49 21\n"
                                       "62 27 90 59 63 26 40 26 72 36\n"
                                       "11 68 67 29 82 30 62 23 67 35\n"
                                       "29 2 22 58 69 67 93 56 11 42\n"
                                       "29 73 21 19 84 37 98 24 15 70\n"
                                       "13 26 91 80 56 73 62 70 96 81\n"
                                       "5 25 84 27 36 5 46 29 13 57\n"
                                       "24 95 82 45 14 67 34 64 43 50\n"
                                       "87 8 76 78 88 84 3 51 54 99\n"
                                       "32 60 76 68 39 12 26 86 94 39");
            Matrix rhs = create_matrix("10 10\n"
                                       "95 70 34 78 67 1 97 2 17 92\n"
                                       "52 56 1 80 86 41 65 89 44 19\n"
                                       "40 29 31 17 97 71 81 75 9 27\n"
                                       "67 56 97 53 86 65 6 83 19 24\n"
                                       "28 71 32 29 3 19 70 68 8 15\n"
                                       "40 49 96 23 18 45 46 51 21 55\n"
                                       "79 88 64 28 41 50 93 0 34 64\n"
                                       "24 14 87 56 43 91 27 65 59 36\n"
                                       "32 51 37 28 75 7 74 21 58 95\n"
                                       "29 37 35 93 18 28 43 11 28 29");
            Matrix actual = lhs * rhs;
            Matrix expected = create_matrix("10 10\n"
                                            "31625 34149 29142 29845 34160 26996 43099 30189 19434 29109\n"
                                            "24783 26401 23906 22018 29743 19639 32317 23382 13301 23818\n"
                                            "21309 25927 20509 20197 25550 18991 31058 23899 13950 19865\n"
                                            "22498 25293 28637 19366 18452 20768 25766 19142 12120 19643\n"
                                            "23324 27883 21158 23771 20245 18158 30837 19951 13282 18964\n"
                                            "28074 31367 36294 28061 34506 29499 36323 30793 19759 28879\n"
                                            "14551 15725 14993 14985 18287 16284 20300 16264 8472 11542\n"
                                            "23635 24106 25783 25588 31121 25172 29699 28370 16526 21217\n"
                                            "28831 30869 33860 30995 30521 24274 35516 28866 15480 28049\n"
                                            "23585 24698 26489 25402 33373 24465 30223 28005 18226 23834");
            REQUIRE(util::trim(to_string(actual)) == util::trim(to_string(expected)));
        }
    }

    SECTION("Non-square matrices") {
        SECTION("2x1 mult 1x2") {
            Matrix lhs = create_matrix("2 1 3 4");
            Matrix rhs = create_matrix("1 2 7 9");
            Matrix actual = lhs * rhs;
            Matrix expected = create_matrix("2 2 21 27 28 36");
            REQUIRE(util::trim(to_string(actual)) == util::trim(to_string(expected)));
        }

        SECTION("13x8 mult 8x9") {
            Matrix lhs = create_matrix("13 8\n"
                                       "83 86 77 15 93 35 86 92\n"
                                       "49 21 62 27 90 59 63 26\n"
                                       "40 26 72 36 11 68 67 29\n"
                                       "82 30 62 23 67 35 29 2\n"
                                       "22 58 69 67 93 56 11 42\n"
                                       "29 73 21 19 84 37 98 24\n"
                                       "15 70 13 26 91 80 56 73\n"
                                       "62 70 96 81 5 25 84 27\n"
                                       "36 5 46 29 13 57 24 95\n"
                                       "82 45 14 67 34 64 43 50\n"
                                       "87 8 76 78 88 84 3 51\n"
                                       "54 99 32 60 76 68 39 12\n"
                                       "26 86 94 39 95 70 34 78");
            Matrix rhs = create_matrix("8 9\n"
                                       "67 1 97 2 17 92 52 56 1\n"
                                       "80 86 41 65 89 44 19 40 29\n"
                                       "31 17 97 71 81 75 9 27 67\n"
                                       "56 97 53 86 65 6 83 19 24\n"
                                       "28 71 32 29 3 19 70 68 8\n"
                                       "15 40 49 96 23 18 45 46 51\n"
                                       "21 55 79 88 64 28 41 50 93\n"
                                       "0 34 64 24 14 87 56 43 91");
            Matrix actual = lhs * rhs;
            Matrix expected = create_matrix("13 9\n"
                                            "20603 26104 37214 28346 24153 30094 24651 26642 26995\n"
                                            "13125 18627 25471 22629 15502 17042 18740 18873 17414\n"
                                            "11743 15164 24671 23417 17457 16272 14411 14381 18908\n"
                                            "14114 13767 22695 16397 13471 16541 14867 15605 10858\n"
                                            "15680 23558 24033 24524 18339 16890 20261 17944 16380\n"
                                            "14463 22157 22629 23116 17637 14663 17568 18818 17866\n"
                                            "13388 24001 22892 24738 15947 16679 20739 20292 20199\n"
                                            "19545 22464 32238 29041 26669 21716 18572 17254 22052\n"
                                            "7585 11814 20881 16398 10884 17366 14567 12800 17847\n"
                                            "16095 19728 25529 21959 15914 18328 20629 17599 16018\n"
                                            "16980 21140 30706 24902 16519 22229 24753 20917 17191\n"
                                            "19857 25601 25194 26427 20677 16888 20608 19750 15304\n"
                                            "18144 26870 31381 30009 23408 24263 22631 22909 24344");
            REQUIRE(util::trim(to_string(actual)) == util::trim(to_string(expected)));
        }
    }

    SECTION("Test throwing because of wrong dimensions") {
        SECTION("2x1 mult 2x1") {
            Matrix lhs = create_matrix("2 1 3 4");
            Matrix rhs = create_matrix("2 1 7 9");
            REQUIRE_THROWS_AS(lhs * rhs, std::invalid_argument);
        }

        SECTION("4x2 mult 3x4") {
            Matrix lhs = create_matrix("4 2 1 2 3 4 5 6 7 8");
            Matrix rhs = create_matrix("3 4 1 2 3 4 5 6 7 8 10 11 12");
            REQUIRE_THROWS_AS(lhs * rhs, std::invalid_argument);
        }
    }
}

TEST_CASE("a4: Test operator []", "[task:a4]") {
    SECTION("Test mutable value from []") {
        Matrix matr = create_matrix("4 2 1 2 3 4 5 6 7 8");
        matr[0][0] = 150;
        matr[3][1] = -42;
        REQUIRE(matr[0][0] == 150);
        REQUIRE(matr[3][1] == -42);
    }

    SECTION("Test const []") {
        const Matrix matr = create_matrix("4 2 1 2 3 4 5 6 7 8");
        REQUIRE_NOTHROW(matr[0][0]);
        REQUIRE(matr[0][0] == 1);
    }
}