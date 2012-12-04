#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ostringstream oss;
    string mystr;
    const char* mychar;

    oss << "sample string";
    mystr = oss.str();
    mychar = mystr.c_str();

    cout << mystr << endl;
    cout << oss << endl;
    printf("%s\n", mychar);

    return 0;
}
