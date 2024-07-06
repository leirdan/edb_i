#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T> class Vector {
private:
  T *_base;
  int _length;
  int _count;

public:
  Vector(int length);
  ~Vector();
  // Returns the max length of vector.
  int size();
  // Counts how many elements are inside vector.
  int count();
  // Returns an element based on its index
  T *get(int index);
  // Inserts an element on a specified position
  void insert(int index, T element);
  // Removes an element on a specified position
  void remove(int index);
};

#include "vector.cpp"

#endif
