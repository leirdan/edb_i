#include <iostream>
#include "vector.hpp"

int main() { 
  int choice;

  std::cout << "What data structure you wanna create?\n";
  std::cout << "1 - Vector\n";
  std::cin >> choice; 

  switch (choice) { 
    case 1: 
      int length, operation;
      std::cout << "Insert vector's length: ";
      std::cin >> length;

      Vector<int> *vector = new Vector<int>(length);

      std::cout << "Insert vector's elements: ";  
      int aux;
      for (int i = 0; i < vector->size(); i++) { 
        std::cin >> aux; 
        vector->insert(i, aux);
      }

      std::cout << "This is your vector now: ";
      for (int i = 0; i < vector->size(); i++) {
        std::cout << *vector->get(i) << " ";
      }
      break; 
  }

  return 0;
}
