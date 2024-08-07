// 3.1-compilazione_separata.cpp : Defines the entry point for the application.
//

#include "3.1-compilazione_separata.h"

int main() {
  Vector v(5);

  for (int i = 0; i != v.size(); ++i)
    v[i] = i;

  double sum = 0;
  for (int i = 0; i != v.size(); ++i) {
    sum += std::sqrt(v[i]);
  }
  v.print();
  std::cout << std::endl;
  std::cout << sum;
  return 0;
}
