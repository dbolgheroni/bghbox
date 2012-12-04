#include <iostream>
#include "oo.hh"

using namespace std;

/*
 * Test1 Methods
 */
/*
int Test1::getValue(void) {
  return 1;
}
*/

/*
 * Test2 Methods
 */
int Test2::getValue(void) {
  return 2;
}

int main(void) {
  Test2 obj;

  // obj = new Test2();

  cout << "getValue() returned " << obj.getValue() << endl;
  return 0;
}
