#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
private:
    T _data;
    Node<T> *_next;

public:
    Node<T>(T data, Node<T> *next);
    T get_data();
    Node<T> *get_next();
};

template <typename T>
T Node<T>::get_data()
{
    return _data;
}

template <typename T>
Node<T> *Node<T>::get_next()
{
    return _next;
}

template <typename T>
Node<T>::Node<T>(T data, Node<T> *next)
{
    _data = data;
    _next = next;
}

#endif
