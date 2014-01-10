/* playing with strings */

#include <iostream>

using namespace std;

int main() {
    /* creating a new string */
    string s("a new string with UTF-8 character ñ\n");

    /* finding the size of a string */
    string::size_type length;
    length = s.size();

    /* converting a string to a char* */
    const char* c;
    c = s.c_str();

    /* creating a char array with the exactly length of the string */
    const char* newc;
    newc = new char[length];

    /* printing a string */
    cout << s; /* << operator supports either string or */
    cout << c; /* const char* directly */

    return 0;
}
