#include <stdexcept>
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::append(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

template <typename T>
void DoublyLinkedList<T>::prepend(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

template <typename T>
bool DoublyLinkedList<T>::insert(const T& data, int index) {
    if (index < 0 || index > count) return false;
    
    if (index == 0) {
        prepend(data);
        return true;
    }
    if (index == count) {
        append(data);
        return true;
    }
    
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    Node* newNode = new Node(data);
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    count++;
    return true;
}

template <typename T>
bool DoublyLinkedList<T>::replace(const T& data, int index) {
    if (index < 0 || index >= count) return false;
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = data;
    return true;
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;
            
            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;
            
            delete current;
            count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
T DoublyLinkedList<T>::removeByIndex(int index) {
    if (index < 0 || index >= count) 
        throw std::out_of_range("Index out of range");
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    
    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;
    
    T data = current->data;
    delete current;
    count--;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) 
        throw std::out_of_range("Index out of range");
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
int DoublyLinkedList<T>::size() const {
    return count;
}

template <typename T>
void DoublyLinkedList<T>::displayForward() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template <typename T>
void DoublyLinkedList<T>::displayBackward() const {
    Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << "\n";
}
