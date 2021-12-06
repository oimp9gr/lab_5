#pragma once

#include <vector>
#include <string>
#include <numeric>
#include <regex>

namespace util {
using namespace std;

class ForbiddenString {
public:
    ForbiddenString() {
        throw std::logic_error("std::string and char usage is forbidden");
    }

    ForbiddenString(const char *) {
        throw std::logic_error("std::string and char usage is forbidden");
    }
};

template<class T>
class ForbiddenVector {
public:
    ForbiddenVector() {
        throw std::logic_error("std::vector usage is forbidden");
    }
};

class ForbiddenOnlyString {
public:
    ForbiddenOnlyString() {
        throw std::logic_error("std::string usage is forbidden");
    }
};

template<class T>
class MyVector : public vector<T> {
public:
    using std::vector<T>::vector;
    using std::vector<T>::operator=;
    MyVector() = default;
    MyVector(MyVector const &) = default;
    MyVector(MyVector &&) = default;
    MyVector &operator=(MyVector const &) = default;
    MyVector &operator=(MyVector &&) = default;
    MyVector(std::initializer_list<T> il) {
        for (auto v : il) {
            this->push_back(v);
        }
    }
};

class MyString : public string {
public:
    string &GetString() {
        return *this;
    }
};

class ForbiddenStack {
public:
    ForbiddenStack() {
        throw std::logic_error("std::stack usage is forbidden");
    }

    ForbiddenStack(const char *) {
        throw std::logic_error("std::stack usage is forbidden");
    }
};

template<class T=int>
class ForbiddenQueue {
public:
    ForbiddenQueue() {
        throw std::logic_error("std::queue usage is forbidden");
    }
};

class ForbiddenList {
public:
    ForbiddenList() {
        throw std::logic_error("std::list usage is forbidden");
    }

    ForbiddenList(const char *) {
        throw std::logic_error("std::list usage is forbidden");
    }
};


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