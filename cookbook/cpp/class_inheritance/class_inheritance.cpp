#include <iostream>

// using namespace std;

class Parent {
public:
  static const int n = 1;
};

class Child : public Parent {
public:
  static const int n = 2;
};

int main() {
  // Parent test;
  Child test;

  std::cout << test.n << std::endl;
}


