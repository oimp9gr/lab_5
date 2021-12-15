#pragma once

#include <vector>
#include <string>
#include <numeric>
#include <regex>

namespace util {
using namespace std;

std::string ltrim(const std::string &s) {
    return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string &s) {
    return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string &s) {
    return ltrim(rtrim(s));
}

void ResizeMatrix(vector<vector<int>> &matrix, size_t row_new_size, size_t column_new_size = -1) {
    if (column_new_size == static_cast<size_t>(-1)) {
        column_new_size = row_new_size;
    }
    matrix.resize(row_new_size);
    for (auto &row: matrix) {
        row.resize(column_new_size);
    }
}

void FillMatrixIota(vector<vector<int>> &matrix, int start = 0) {
    for (auto &row: matrix) {
        iota(row.begin(), row.end(), start);
    }
}

string GenerateStringFromAlphabet(const vector<char> &alphabet, size_t size) {
    string result;
    for (size_t i = 0; i < size; ++i) {
        result += alphabet[rand() % alphabet.size()];
    }
    return result;
}

}