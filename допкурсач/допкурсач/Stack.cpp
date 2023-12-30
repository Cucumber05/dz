#include <iostream>
#include "Stack.h"

Node::Node(int k) {
    key = k;
    p = nullptr;
}

Node::~Node() {
    
}

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::Stack(const Stack& other) {
    top = nullptr; // Инициализация как пустой стек
    size = other.size; // Копирование размера
    if (other.top != nullptr) {
        top = new Node(other.top->key);

        Node* curr = top;
        Node* curr_other = other.top->p;

        while (curr_other != nullptr) {
            curr->p = new Node(curr_other->key);
            curr = curr->p;
            curr_other = curr_other->p;
        }
    }
}

Stack::~Stack() {
    remove();
}

void Stack::push(int k) {
    if (size == max_size) {
        std::cout << "Стек переполнен!" << std::endl;
        return;
    }

    Node* newNode = new Node(k);
    if (top == nullptr) {
        top = newNode;
    }
    else {
        newNode->p = top;
        top = newNode;
    }
    size++;
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Стек пуст!" << std::endl;
    }
    else {
        Node* temp = top;
        top = top->p;
        std::cout << "Удаленный элемент: " << temp->key << std::endl;
        delete temp;
        size--;
    }
}

void Stack::remove() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->p;
        delete temp;
    }
    size = 0;
}

void Stack::print() {
    if (top == nullptr) {
        std::cout << "Стек пуст!" << std::endl;
    }
    else {
        Node* curr = top;
        while (curr != nullptr) {
            std::cout << curr->key << "\n";
            curr = curr->p;
        }
        std::cout << std::endl;
    }
}

int Stack::length() {
    return size;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

//Один доп функционал инверстировать стек
void Stack::reverse() {
    if (top == nullptr || top->p == nullptr) {
        return;
    }

    Node* prev = nullptr;
    Node* curr = top;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->p;
        curr->p = prev;
        prev = curr;
        curr = next;
    }

    top = prev;
}



