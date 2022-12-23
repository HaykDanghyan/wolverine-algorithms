#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

template <typename T>
class forward_list {
public:
    forward_list();
    forward_list(const forward_list<T>&);
    forward_list(forward_list<T>&&);
    forward_list(size_t);
    forward_list(size_t, const T&);
    forward_list(std::initializer_list<T>);

    forward_list<T>& operator=(const forward_list<T>&);
    forward_list<T>& operator=(forward_list<T>&&);

    void push_front(const T&);
    void pop_front();

    void insert(size_t, const T&);
    void erase(const T&);
    void swap(forward_list<T>&);
    void merge(const forward_list<T>&);
    size_t size() const;

public:
    friend std::ostream& operator<<(std::ostream& os, const forward_list<T>& rhs) {
        for (ListNode* start = rhs.head; start != nullptr; start = start->next) {
            os << start->val << "  ";
        }
        return os;
    }


    friend bool operator==(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        auto h1 = lhs.head;
        auto h2 = rhs.head;
        while (h1) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }

    friend bool operator!=(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        return lhs.size() < rhs.size();
    }

    friend bool operator>(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        return lhs.size() > rhs.size();
    }

    friend bool operator<=(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        return (lhs < rhs) || (lhs == rhs);
    }

    friend bool operator>=(const forward_list<T>& lhs, const forward_list<T>& rhs) {
        return (lhs > rhs) || (lhs == rhs);
    }

private:
    struct ListNode {
        ListNode(T v = T(), ListNode* n = nullptr) : val(v), next(n) {}
        ListNode* next;
        T val;  
    };
    ListNode* head;

private:
    ListNode* merge_helper(ListNode*, ListNode*);
};
#include "forward-list.hpp"
#endif // FORWARD_LIST_H