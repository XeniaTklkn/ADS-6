// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    TPQueue() : head(nullptr) {}

    void push(const T& val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr || val.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next != nullptr && cur->next->data.prior >= val.prior) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
    T pop() {
        Node* tmp = head;
        T result = head->data;
        head = head->next;
        delete tmp;
        return result;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
