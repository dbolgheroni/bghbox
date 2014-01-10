#include <iostream>
#include <fstream>
#include <sstream>

typedef char *XML;
using namespace std;

int main() {
    //char *buf;
    fstream fs;
    streamsize length;

    struct myTest {
        XML omResponse;
    } *om;

    /* */
    fs.open("utf-8.txt");

    /* get length */
    fs.seekg(0, ios::end);
    length = fs.tellg();
    fs.seekg(0, ios::beg);

    cerr << "length = " << length << endl;

    /* allocate memory */
    //char *buf = new char(length + 1);
    char *buf = new char[length];

    /* no ending null-character is appended at the end of the character
     * sequence */
    fs.read(buf, length);
    cerr << "gcount() = " << fs.gcount() << endl;

    buf[8] = '\0';
    for (int i = 0; i < length; i++) {
        printf("buf[%d] = %x\n", i, buf[i]);
        //cout << "buf[" << i << "] = " << buf[i] << endl;
    }

    cout << "buf = " << buf << endl;

    /* cannot reference null pointer! */
    om->omResponse = (char*)buf;
}
