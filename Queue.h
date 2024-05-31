#ifndef QUEUE_H
#define QUEUE_H

#include "DLList.h"

template <typename T>
class Queue : public DLList<T> {
public:
    void enqueue(const T& data) {
        this->push_back(data);
    }

    void dequeue() {
        this->pop_front();
    }

    T& front() {
        return this->begin()->data;
    }

    const T& front() const {
        return this->begin()->data;
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

#endif // QUEUE_H
