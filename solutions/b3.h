#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct ListNode {
    int value;
    ListNode *next = nullptr;
};

class List {
public:
    void PushBack(int value) {
        if (!head) {
            head = new ListNode;
            head->value = value;
            tail = head;
        } else {
            tail->next = new ListNode;
            tail->next->value = value;
            tail = tail->next;
        }
    }

    int PopBack() {
        if (isEmpty())
            throw std::out_of_range("");

        auto prev = head;
        auto cur = head;

        while (cur->next) {
            prev = cur;
            cur = cur->next;
        }
        int value = cur->value;
        if (cur == head) {
            head = nullptr;
            tail = nullptr;
        } else {
            prev->next = nullptr;
        }
        delete cur;
        return value;
    }

    void PushFront(int value) {
        auto *new_head = new ListNode;
        new_head->value = value;
        new_head->next = head;
        head = new_head;
    }

    int PopFront() {
        if (isEmpty())
            throw std::out_of_range("");

        int result = head->value;
        auto tmp_head = head;
        head = head->next;
        delete tmp_head;
        return result;
    }

    bool isEmpty() {
        return !head;
    }

    bool Erase(int value) {
        auto *prev = head;
        auto *cur = head;
        while (cur) {
            if (cur->value == value) {
                if (cur == head) {
                    PopFront();
                } else {
                    prev->next = cur->next;
                    delete cur;
                }
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    void Insert(size_t pos, int value) {
        if (!head && pos) throw std::out_of_range("");
        if (pos == 0) {
            PushFront(value);
            return;
        }
        auto tmp = head;
        size_t i = 1;
        for (; i < pos && tmp->next; ++i) {
            tmp = tmp->next;
        }
        if (i != pos) throw std::out_of_range("");
        auto to_insert = new ListNode;
        to_insert->value = value;
        to_insert->next = tmp->next;
        tmp->next = to_insert;
    }

    ~List() {
        while (head) {
            auto tmp = head->next;
            delete head;
            head = tmp;
        }
    }

    string Print() {
        stringstream result;
        auto tmp = head;
        while (tmp) {
            result << tmp->value << " ";
            tmp = tmp->next;
        }
        return result.str();
    }

private:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
};