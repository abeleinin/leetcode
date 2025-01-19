#include "linked_list.h"

template <typename T>
Node<T>::Node(T value)
    : value(value)
    , next(nullptr)
{}

template <typename T>
Node<T>::Node(T value, Node* next)
    : value(value)
    , next(next)
{}
