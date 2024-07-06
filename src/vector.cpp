#include "vector.hpp"
#include <exception>

template <typename T> Vector<T>::Vector(int length) {
  _length = length;
  _base = new T[_length];
}

template <typename T> Vector<T>::~Vector() {
  delete _base;
}

template <typename T> int Vector<T>::size() {
  return _length;
}

template <typename T> int Vector<T>::count() {
  return _count;
}

template <typename T> T *Vector<T>::get(int index) {
  try {
    return &_base[index];
  } catch (std::exception_ptr) {
    return nullptr;
  }
}

template <typename T> void Vector<T>::insert(int index, T element) {
  if (index >= _length) return;
  
  // Para realocar os elementos devemos começar do final do vetor para não apagar os elementos. 
  for (int i = _length - 1; i > index; i--) { 
    _base[i] = _base[i - 1];
  }
  _base[index] = element;
  _count++;
}

template <typename T> void Vector<T>::remove(int index) { 
  if (_count == 0) return;

  // Para realocar os elementos devemos partir de onde ocorreu a remoção. 
  _base[index] = NULL;
  for (int i = index; i <= _length - 1; i++) {
    _base[i] = _base[i + 1];
  }
  _count--;
  
}
