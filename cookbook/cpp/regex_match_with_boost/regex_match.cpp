/*
 * compile with
 * $ g++ -o regex_match -I/usr/local/include -L/usr/local/lib -lboost_regex regex_match.cpp
 */

#include <iostream>
#include <boost/regex.hpp>

using namespace std;

// ^[[:alpha:]][[:alnum:]_@-\\]{3,63}$

std::string s, sre;
boost::regex re;

int main()
{
    cout << "regex: ";
    cin >> sre;

    cout << "string: ";
    cin >> s;

    try {
        re.assign(sre);
    } catch(boost::regex_error& e) {
        cout << "not a valid regex" << endl;
    }

    if (boost::regex_match(s, re)) {
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }

    return 0;
}
