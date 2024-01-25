#include <iostream>

#include "Vector.h"
#include <vector>

template<typename T>
void PrintVector(Vector<T>& vec) {
  for (int pos: vec)
    std::cout << pos << '\n';
  std::cout << "----------------------------" << std::endl;
}


int main(int argc, char* argv[]){
  std::vector<int> vec0 = { 1, 1, 1, 1 };
  std::vector<int>::const_iterator; // add
  std::vector<int>::const_reverse_iterator; // add
  std::vector<int>::iterator;
  std::vector<int>::reverse_iterator; // add
  vec0.begin();

  Vector<int> vec;//= { "hey" };//make this work
  vec.emplace_back(1);
  vec.emplace_back(1);
  vec.emplace_back(2);
  vec.emplace_back(3);
  vec.emplace_back(3);
  vec.emplace_back(4);
  vec.emplace_back(5);

  PrintVector(vec);

  std::cin.get();
  return 0;
};
