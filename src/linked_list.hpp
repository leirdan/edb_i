#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "node.hpp"

template <typename T>
class LinkedList
{
private:
    Node<T> *first;
    int count;
    int size;

public:
    T *get(int index);
    T *get_first();
    T *get_last();
};

template <typename T>
T *LinkedList<T>::get(int index)
{
    auto it = new Iterator<T>(first);

    for (int i = 0; i < index && i < size; i++)
    {
        it->next();
    }
    return it->current;
}

template <typename T>
T *LinkedList<T>::get_last()
{
    auto it = new Iterator<T>(first);
    while (it->current->get_next())
    {
        it->current->next();
    }
    return it->current;
}
#endif