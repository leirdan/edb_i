#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
private:
    T _data;
    Node<T> *_next;

public:
    Node<T>(T data);
    Node<T>(T data, Node<T> *next);
    T get_data();
    Node<T> *get_next();
    void set_next(Node<T> *value);
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
void Node<T>::set_next(Node<T> *value)
{
    _next = value;
}

template <typename T>
Node<T>::Node(T data)
{
    _data = data;
    _next = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node<T> *next)
{
    _data = data;
    _next = next;
}

#endif
