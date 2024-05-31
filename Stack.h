#ifndef STACK_H
#define STACK_H

#include "DLList.h"

template <typename T>
class Stack : public DLList<T> {
public:
    void push(const T& data) {
        this->push_back(data);
    }

    void pop() {
        this->pop_back();
    }

    T& top() {
        return this->end()->prev->data;
    }

    const T& top() const {
        return this->end()->prev->data;
    }

    bool empty() const {
        return this->begin() == this->end();
    }

    size_t size() const {
        size_t size = 0;
        for (auto it = this->begin(); it != this->end(); ++it) {
            ++size;
        }
        return size;
    }
};

#endif // STACK_H
