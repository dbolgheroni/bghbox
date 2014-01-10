/* operator overloading */

#include <iostream>

using namespace std;

class Int {
public:
    int number;

    Int(int n) {
        number = n;
    }

};

int operator*(Int lhs, Int rhs) {
    return lhs.number + rhs.number;
}

int main() {
    //Int a(2);
    Int a = 2; // assignment operator
    Int b(3);
    
    //a = b;
    cout << a * b << endl;

    // string
    string foo("bar");
    // string foo = "bar"; // assignment operator
    cout << foo << endl;

    return 0;
}
