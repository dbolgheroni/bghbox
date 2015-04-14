#include <iostream>

// using namespace std;

class Parent {
public:
  static const int x = 1;
};

class Child : public Parent {
public:
  static const int y = 2;
};

int main() {
  //Parent test;
  Child test;

  std::cout << test.x << std::endl;
  std::cout << test.y << std::endl;
}
