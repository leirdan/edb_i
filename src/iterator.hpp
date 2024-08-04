#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "node.hpp"

template <typename T>
class Iterator
{
private:
    Node<T> *_current;

public:
    Iterator(Node<T> *node)
    {
        _current = node;
    };
    Node<T> *getCurrent();
    bool has_next();
    void next();
};

template <typename T>
Node<T> *Iterator<T>::getCurrent()
{
    return this->_current;
}

template <typename T>
void Iterator<T>::next()
{
    _current = _current->get_next();
}

template <typename T>
bool Iterator<T>::has_next()
{
    return this->_current->get_next() != nullptr;
}

#endif