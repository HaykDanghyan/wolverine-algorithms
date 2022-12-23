#include "forward-list.h"

template <typename T>
forward_list<T>::forward_list() : head(nullptr) {}

template <typename T>
forward_list<T>::forward_list(const forward_list<T>& rhs) {
    if(rhs.head == nullptr) {
        return;
    }
    head = new ListNode(rhs.head->val);
    ListNode* curr1 = rhs.head->next;
    ListNode* curr2 = head;
    while (curr1 != nullptr) {
        curr2->next = new ListNode(curr1->val);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
}

template <typename T>
forward_list<T>::forward_list(forward_list<T>&& rhs) {
    head = rhs.head;
    rhs.head = nullptr;
}

template <typename T>
forward_list<T>::forward_list(size_t count) {
    head = new ListNode();
    ListNode* curr = head;
    for (int i = 0; i < count - 1; ++i) {
        curr->next = new ListNode();
        curr = curr->next;
    }
}

template <typename T>
forward_list<T>::forward_list(size_t count, const T& value) {
    head = new ListNode(value);
    ListNode* curr = head;
    for (int i = 0; i < count - 1; ++i) {
        curr->next = new ListNode(value);
        curr = curr->next;
    }
}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> init) {  
    auto it = init.begin();
    head = new ListNode(*it);
    ++it;
    ListNode* curr = head;
    for (; it != init.end(); ++it) {
        curr->next = new ListNode(*it);
        curr = curr->next;
    }
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(const forward_list<T>& rhs) {
    if (this != &rhs) {
        if (head) {
            delete head;
            head = nullptr;
        }
        if(rhs.head == nullptr) {
            return *this;
        }
        head = new ListNode(rhs.head->val);
        ListNode* curr1 = rhs.head->next;
        ListNode* curr2 = head;
        while (curr1 != nullptr) {
            curr2->next = new ListNode(curr1->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    return *this;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(forward_list<T>&& rhs) {
    if (this != &rhs) {
        head = rhs.head;
        rhs.head = nullptr;
    }
    return *this;
}

template <typename T>
void forward_list<T>::push_front(const T& val) {
    ListNode* new_node = new ListNode(val, head);
    head = new_node;
}

template <typename T>
void forward_list<T>::pop_front() {
    ListNode* deleted = head;
    head = head->next;
    delete deleted;
    deleted = nullptr;
}

template <typename T>
void forward_list<T>::insert(size_t idx, const T& value) {
    if (idx == 0) {
        push_front(value);
    }
    ListNode* tmp = new ListNode(head->val);
    ListNode* curr = tmp;
    while (--idx) {
        head = head->next;
        curr->next = new ListNode(head->val);
        curr = curr->next;
    }
    curr->next = new ListNode(value);
    curr = curr->next;
    head = head->next;
    while (head) {
        curr->next = new ListNode(head->val);
        curr = curr->next;
        head = head->next;
    }
    head = std::move(tmp);
}

template <typename T>
void forward_list<T>::merge(const forward_list<T>& rhs) {
    ListNode* curr1 = this->head;
    this->head = merge_helper(this->head, rhs.head);
} 

template <typename T>
typename forward_list<T>::ListNode* forward_list<T>::merge_helper(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = merge_helper(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_helper(l1, l2->next);
        return l2;
    }
}

template <typename T>
size_t forward_list<T>::size() const {
    ListNode* curr = head;
    size_t count = 0;
    while (curr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

template <typename T>
void forward_list<T>::swap(forward_list<T>& rhs) {
    using std::swap;
    swap(head, rhs.head);
}

template <typename T>
void forward_list<T>::erase(const T& val) {
    while (head && head->val == val) {
        head = head->next;
    }
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}