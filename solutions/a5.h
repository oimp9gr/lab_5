#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <utility>

using std::string;
using std::map;

map<string, int> GetFrequencies(const string &text) {
    string new_text;
    for (char el : text) {
        if ((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z')) {
            el = toupper(el);
            new_text += el;
        }
    }

    string three_gram;
    map<string, int> result;
    for (size_t i = 2; i < new_text.size(); ++i) {
        three_gram = new_text.substr(i - 2, 3);
        result[three_gram]++;
    }
    return result;
}
