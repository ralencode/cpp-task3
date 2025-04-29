#include <iostream>
#include <string>
#include "doubly_linked_list.h"

int main() {
    // Integer list demonstration
    DoublyLinkedList<int> intList;
    intList.append(10);
    intList.append(3);
    intList.prepend(5);
    intList.insert(7, 1);
    intList.replace(8, 2);
    intList.removeByIndex(3);
    
    std::cout << "Integer list (" << intList.size() << " elements):\n";
    std::cout << "Forward:  ";
    intList.displayForward();   // 5 7 8
    std::cout << "Backward: ";
    intList.displayBackward();  // 8 7 5
    std::cout << "Element at index 1: " << intList.get(1) << "\n\n";

    // String list demonstration
    DoublyLinkedList<std::string> strList;
    strList.append("world");
    strList.prepend("Hello");
    strList.insert("beautiful", 1);
    strList.insert("wonderful", 1);
    strList.removeByIndex(2);
    
    std::cout << "String list (" << strList.size() << " elements):\n";
    std::cout << "Forward:  ";
    strList.displayForward();   // Hello wonderful world 
    strList.remove("wonderful");
    std::cout << "After removal: ";
    strList.displayForward();    // Hello world

    return 0;
}
