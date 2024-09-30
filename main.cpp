#include "DLList.h"
#include <iostream>

int main() {
    // Create a doubly linked list of integers
    DLList<int> list;

    std::cout << "Testing push_front and push_back:\n";
    list.push_front(10);  // List: 10
    list.push_back(20);   // List: 10 20
    list.push_front(5);   // List: 5 10 20
    list.push_back(25);   // List: 5 10 20 25
    list.print();         // Expected Output: 5 10 20 25

    std::cout << "\nTesting pop_front and pop_back:\n";
    list.pop_front();     // List: 10 20 25
    list.pop_back();      // List: 10 20
    list.print();         // Expected Output: 10 20

    std::cout << "\nTesting insert at various positions:\n";
    list.insert(1, 15);   // List: 10 15 20
    list.insert(0, 5);    // List: 5 10 15 20
    list.insert(4, 25);   // List: 5 10 15 20 25
    list.print();         // Expected Output: 5 10 15 20 25

    std::cout << "\nTesting erase from various positions:\n";
    list.erase(0);        // List: 10 15 20 25 (Erase first element)
    list.erase(2);        // List: 10 15 25 (Erase element at index 2)
    list.erase(2);        // List: 10 15 (Erase last element)
    list.print();         // Expected Output: 10 15

    std::cout << "\nTesting iterator capabilities (forward iteration):\n";
    DLList<int>::iterator it = list.begin();
    while (it != list.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;  // Expected Output: 10 15

    std::cout << "\nTesting iterator capabilities (reverse iteration):\n";
    it = list.end();  // Set to past-the-end iterator
    --it;  // Move back to the last valid element
    while (it != list.begin()) {
        std::cout << *it << " ";
        --it;
    }
    std::cout << *it << std::endl;  // Expected Output: 15 10

    std::cout << "\nTesting print_reverse:\n";
    list.print_reverse();  // Expected Output: 15 10

    std::cout << "\nTesting clear function:\n";
    list.clear();          // Clear the entire list
    list.print();          // Expected Output: (no output, empty list)

    std::cout << "\nTesting with strings:\n";
    DLList<std::string> strList;
    strList.push_back("Hello");
    strList.push_front("World");
    strList.push_back("!");
    strList.print();       // Expected Output: World Hello !

    std::cout << "\nTesting clear on the string list:\n";
    strList.clear();
    strList.print();       // Expected Output: (no output, empty list)
                           //

    DLList listaNueva = {1,2,3,4,5,6,7,8,9,10}

    return 0;
}
