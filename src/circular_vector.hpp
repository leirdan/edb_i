#ifndef CIRCULAR_VECTOR_HPP
#define CIRCULAR_VECTOR_HPP

template <typename T> class CircularVector {
private:
  T *_base;
  int _length;
  int _count;
  int _bias;

public:
  CircularVector(int length, int bias);
  ~CircularVector();
  // Returns the max length of vector.
  int size();
  // Counts how many elements are inside vector.
  int count();
  // Returns an element based on its index
  T *get(int index);
  // Inserts an element on start
  void insert_start(T element);
  // Inserts an element on end
  void insert_end(T element);
  // Removes the element of start
  void remove_start();
  // Removes the element of end
  void remove_end();
};

#include "circular_vector.cpp"

#endif
