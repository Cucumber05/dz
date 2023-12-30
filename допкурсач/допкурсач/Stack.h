#pragma once

class Node {
public:
    int key;
    Node* p;
    Node(int k = 0);
    ~Node();
};

class Stack {
private:
    static const int max_size = 100; // ������������ ������ �����
    Node* top;
    int size; // ������� ������ �����

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    void push(int k);
    void pop();
    void remove();
    void print();
    int length();
    bool isEmpty();
    void reverse();
};
