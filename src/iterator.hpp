#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "node.hpp"

template <typename T>
class Iterator
{
private:
    Node<T> *_current;

public:
    Iterator(Node<T> *node);
    void next();
};

template <typename T>
void Iterator<T>::next()
{
    current = current->get_next();
}

template <typename T>
Iterator<T>::Iterator<T>(Node<T> *node)
{
    current = node;
}

#endif