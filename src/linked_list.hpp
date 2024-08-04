#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "node.hpp"
#include "iterator.hpp"
#include <iostream>

namespace ed
{
    template <typename T>
    class LinkedList
    {
    private:
        Node<T> *_head;
        int _size;
        Node<T> *insert(Node<T> *previous_node, T new_element)
        {
            // Creates new node
            Node<T> *new_node = new Node<T>(new_element);

            // If there isn't any node before, set this new node as head
            if (previous_node == nullptr)
            {
                new_node->set_next(this->_head);
                this->_head = new_node;
            }
            // If there was a previous node, insert the new node "between" previous and previous-next node
            else
            {
                // previous_node -> new_node -> next_node
                Node<T> *next_node = previous_node->get_next();
                new_node->set_next(next_node);
                previous_node->set_next(new_node);
            }
            this->_size++;
            return new_node;
        }

    public:
        LinkedList<T>()
        {
            _size = 0;
            _head = nullptr;
        };
        void set_head(Node<T> *value) { this->_head = value; }
        bool is_empty();
        int size() { return _size; }
        Node<T> *get(int index);
        Node<T> *get_first();
        Node<T> *get_last();
        /// @brief Adds element on an arbitrary list's position
        void insert_at(T value, int index);
        /// @brief Adds element on start of list
        void insert_start(T value);
        /// @brief Adds element on end of list
        void insert_end(T value);
        void remove_at(int index);
        void remove_start();
        void remove_end();
    };

    template <typename T>
    bool LinkedList<T>::is_empty()
    {
        return this->_count == 0;
    }

    template <typename T>
    Node<T> *LinkedList<T>::get(int index)
    {
        // Creates an iterator to run through list
        Iterator<T> *it = new Iterator<T>(this->_head);

        for (int i = 0; i < index && i < this->_size; i++)
        {
            // Advance to next node
            it->next();
        }
        // Returns the requested node
        return it->getCurrent();
    }

    template <typename T>
    Node<T> *LinkedList<T>::get_first()
    {
        Node<T> *last_node = this->get(0);
        return last_node;
    }

    template <typename T>
    Node<T> *LinkedList<T>::get_last()
    {
        Node<T> *last_node = this->get(this->_size);
        return last_node;
    }

    template <typename T>
    void LinkedList<T>::insert_at(T value, int index)
    {
        if (index == 0)
        {
            this->insert_start(value);
            return;
        }
        Node<T> *previous_node = this->get(index - 1);
        this->insert(previous_node, value);
    }

    template <typename T>
    void LinkedList<T>::insert_start(T value)
    {
        this->insert(nullptr, value);
    }

    template <typename T>
    void LinkedList<T>::insert_end(T value)
    {
        this->insert_at(value, this->_size);
    }

    template <typename T>
    void LinkedList<T>::remove_at(int index)
    {
        if (index == 0)
        {
            this->remove_start();
            return;
        }
        else if (index == this->_size)
        {
            this->remove_end();
            return;
        }

        Node<T> *node_on_index = this->get(index);
        Node<T> *previous_node_on_index = this->get(index - 1);

        previous_node_on_index->set_next(node_on_index->get_next());
        delete node_on_index;
        this->_size--;
    }

    template <typename T>
    void LinkedList<T>::remove_start()
    {
        Node<T> *first_node = this->get(0);
        this->_head = first_node->get_next();

        delete first_node;
        this->_size--;
    }

    template <typename T>
    void LinkedList<T>::remove_end()
    {
        Node<T> *last_node = this->get(this->_size);
        Node<T> *previous_last_node = this->get(this->_size - 1);

        previous_last_node->set_next(nullptr);
        delete last_node;
        this->_size--;
    }
}

#endif
