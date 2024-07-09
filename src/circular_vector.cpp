#include "circular_vector.hpp"
#include <exception>

template <typename T> CircularVector<T>::CircularVector(int length, int bias) {
  _length = length;
  _base = new T[_length];
  _bias = bias;
}

template <typename T> CircularVector<T>::~CircularVector() {
  delete _base;
}

template <typename T> int CircularVector<T>::size() {
  return _length;
}

template <typename T> int CircularVector<T>::count() {
  return _count;
}

template <typename T> T *CircularVector<T>::get(int index) {
  try {
    return &_base[(index + _bias) % _length];
  } catch (std::exception_ptr) {
    return nullptr;
  }
}

template <typename T> void CircularVector<T>::insert_start(T element) {
  if (_count == _length) return;
  _bias = (_bias - 1) % _length;

  _base[_bias] = element;
  _count++;
}

template <typename T> void CircularVector<T>::insert_end(T element) {
  if (_count == _length) return;

  auto index = (_count + _bias) % _length;
  _base[index] = element;
  _count++;
}

template <typename T> void CircularVector<T>::remove_start() { 
  if (_count == 0) return;
  _count--;
  _base[_bias] = 0;
  _bias = (_bias + 1) % _length;
}

template <typename T> void CircularVector<T>::remove_end() { 
  if (_count == 0) return;

  auto index = (_bias + _count - 1) % _length;
  _base[index] = 0;
  _count--;
}
