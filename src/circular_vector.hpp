#ifndef CIRCULAR_VECTOR_HPP
#define CIRCULAR_VECTOR_HPP

template <typename T>
class CircularVector
{
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

template <typename T>
CircularVector<T>::CircularVector(int length, int bias)
{
  _length = length;
  _base = new T[_length];
  _bias = bias;
}

template <typename T>
CircularVector<T>::~CircularVector()
{
  delete _base;
}

template <typename T>
int CircularVector<T>::size()
{
  return _length;
}

template <typename T>
int CircularVector<T>::count()
{
  return _count;
}

template <typename T>
T *CircularVector<T>::get(int index)
{
  return &_base[(index + _bias) % _length];
}

template <typename T>
void CircularVector<T>::insert_start(T element)
{
  if (_count == _length)
    return;
  _bias = (_bias - 1) % _length;

  _base[_bias] = element;
  _count++;
}

template <typename T>
void CircularVector<T>::insert_end(T element)
{
  if (_count == _length)
    return;

  auto index = (_count + _bias) % _length;
  _base[index] = element;
  _count++;
}

template <typename T>
void CircularVector<T>::remove_start()
{
  if (_count == 0)
    return;
  _count--;
  _base[_bias] = 0;
  _bias = (_bias + 1) % _length;
}

template <typename T>
void CircularVector<T>::remove_end()
{
  if (_count == 0)
    return;

  auto index = (_bias + _count - 1) % _length;
  _base[index] = 0;
  _count--;
}

#endif
