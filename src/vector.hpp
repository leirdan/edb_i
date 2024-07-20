#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <exception>

template <typename T>
class Vector
{
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

template <typename T>
Vector<T>::Vector(int length)
{
  _length = length;
  _base = new T[_length];
}

template <typename T>
Vector<T>::~Vector()
{
  delete _base;
}

template <typename T>
int Vector<T>::size()
{
  return _length;
}

template <typename T>
int Vector<T>::count()
{
  return _count;
}

template <typename T>
T *Vector<T>::get(int index)
{
  return &_base[index];
}

template <typename T>
void Vector<T>::insert(int index, T element)
{
  if (index >= _length)
    return;

  // Para realocar os elementos devemos começar do final do vetor para não apagar os elementos.
  for (int i = _length - 1; i > index; i--)
  {
    _base[i] = _base[i - 1];
  }
  _base[index] = element;
  _count++;
}

template <typename T>
void Vector<T>::remove(int index)
{
  if (_count == 0)
    return;

  // Para realocar os elementos devemos partir de onde ocorreu a remoção.
  _base[index] = nullptr;
  for (int i = index; i <= _length - 1; i++)
  {
    _base[i] = _base[i + 1];
  }
  _count--;
}

#endif
