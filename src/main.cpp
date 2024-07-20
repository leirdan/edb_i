#include "circular_vector.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
  int choice;

  std::cout << "What data structure you wanna create?\n";
  std::cout << "1 - Vector\n";
  std::cout << "2 - Circular Vector\n";
  std::cout << "3 - Linked List\n";
  std::cin >> choice;

  switch (choice)
  {
  case 1:
  {
    int v_length, v_operation;
    std::cout << "Insert vector's length: ";
    std::cin >> v_length;

    Vector<int> *vector = new Vector<int>(v_length);

    std::cout << "Insert vector's elements: ";
    int aux;
    for (int i = 0; i < vector->size(); i++)
    {
      std::cin >> aux;
      vector->insert(i, aux);
    }

    std::cout << "This is your vector now: ";
    for (int i = 0; i < vector->size(); i++)
    {
      std::cout << *vector->get(i) << " ";
    }

    break;
  }

  case 2:
  {
    int cv_length, cv_bias;
    std::cout << "Insert circular vector's length: ";
    std::cin >> cv_length;
    std::cout << "Insert circular vector's start: ";
    std::cin >> cv_bias;

    CircularVector<int> *c_vector = new CircularVector<int>(cv_length, cv_bias);
    std::cout << "Insert the first " << cv_length - cv_bias << " elements: ";

    int cv_aux;
    for (int i = cv_bias; i < cv_length; i++)
    {
      std::cin >> cv_aux;
      c_vector->insert_end(cv_aux);
    }

    std::cout << "This is your vector now: ";
    for (int i = 0; i < c_vector->size(); i++)
    {
      std::cout << *c_vector->get(i) << " ";
    }

    break;
  }
  case 3:
  {
    int length;
    std::cout << "Insert your list's length: ";
    std::cin >> length;
    std::cout << "Insert your elements: ";
    

  }
  }

  return 0;
}
