#include <iostream>

template <typename Object>

Object sum2numbers(Object a, Object b){
    return a + b;
}

template <typename Object>
struct Node {
    Object data;
    Node *next;
};

int main() {
    std::cout << sum2numbers(5, 10) << std::endl;
    std::cout << sum2numbers(5.5, 10.5) << std::endl;

    Node<int> *n1 = new Node<int>;
    n1->data = 5;
    Node<float> *n2 = new Node<float>;
    n2->data = 5.5;
    Node<double> *n3 = new Node<double>;
    n3->data = 5.5;
    return 0;
}
