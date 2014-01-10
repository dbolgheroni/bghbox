#include <ios>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/* GOAL: write a stream into a char*. */
int main() {
    char* buf;
    char str[] = "açúcar";
    streamsize length;

    //ifstream i;
    //i.open("input.txt");
    stringstream i;
    i << "açúcar" << endl;
    i << str << endl;

    /* get length */
    i.seekg(0, ios::end);
    length = i.tellg();
    i.seekg(0, ios::beg);

    /* allocate memory */
    buf = new char[length];

    /* read the stream and store into a char* */
    i.read(buf, length);

    /* close stream */
    //i.close();

    /* print */
    cout << buf;

    delete[] buf;

    return 0;
}
