#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void append(const T& data);
    void prepend(const T& data);
    bool insert(const T& data, int index);
    bool replace(const T& data, int index);
    bool remove(const T& value);
    T removeByIndex(int index);
    T get(int index) const;
    int size() const;
    void displayForward() const;
    void displayBackward() const;

private:
    Node* head;
    Node* tail;
    int count;
};

#include "doubly_linked_list.tpp"

#endif
