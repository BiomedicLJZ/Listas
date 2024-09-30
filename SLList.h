#ifndef SLLIST_H
#define SLLIST_H

#include <iostream>
#include <initializer_list>

template<typename T>
class SLList {
public:
    struct Node {
        T data;
        Node* next;

        explicit Node(const T& data, Node* next = nullptr)
                : data(data), next(next) {}
    };

    class iterator {
    public:
        explicit iterator(Node *node = nullptr) : node(node) {}

        T& operator*() {
            return node->data;
        }

        iterator& operator++() {
            if (node) {
                node = node->next;
            }
            return *this;
        }

        bool operator==(const iterator& other) const {
            return node == other.node;
        }

        bool operator!=(const iterator& other) const {
            return node != other.node;
        }

        Node* getNode() const {
            return node;
        }

    private:
        Node* node;
    };

    SLList() : head(nullptr), tail(nullptr) {}

    SLList(std::initializer_list<T> list): head(nullptr), tail(nullptr) {
        for(const T& data : list) {
            push_back(data);
        }
    }

    ~SLList() {
        clear();
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator();
    }

    void push_front(const T& data) {
        Node* newNode = new Node(data, head);
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }
    void insert(const T& data, size_t position) {
        if (position == 0) {
            push_front(data);
        } else {
            auto it = begin();
            for (size_t i = 0; i < position - 1 && it != end(); ++i) {
                ++it;
            }
            if (it != end()) {
                Node* newNode = new Node(data, it.getNode()->next);
                it.getNode()->next = newNode;
                if (newNode->next == nullptr) {
                    tail = newNode;
                }
            }
        }
    }

    void erase(size_t position) {
        if (position == 0) {
            pop_front();
        } else {
            Node* temp = head;
            for (size_t i = 0; i < position - 1 && temp->next != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp->next != nullptr) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                if (nodeToDelete == tail) {
                    tail = temp;
                }
                delete nodeToDelete;
            }
        }
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    void pop_back() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    Node* tail;
};

#endif // SLLIST_H
