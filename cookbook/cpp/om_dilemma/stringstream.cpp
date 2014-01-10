#include <iostream>
#include <fstream>
#include <sstream>

typedef char *XML;
using namespace std;

int main() {
    stringstream response;
    char *buf;

    struct myTest {
        XML omResponse;
    };

    struct myTest *om;
    response << "açúcar";

    buf = (char*)response.str().c_str();
    om->omResponse = buf;

    cout << om->omResponse << endl;
    return 0;
}
