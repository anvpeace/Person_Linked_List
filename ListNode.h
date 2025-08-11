#ifndef LISTNODE_H
#define LISTNODE_H
// #include <iostream>
// using namespace std;

template <typename T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    ListNode(T data) : data(data), next(nullptr) {}
};
#endif