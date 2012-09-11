/* 1-2
 *
 * No. C++ will see "Hello" as 'const char [6]' and ", world" as
 * 'const char [8]' (different types).
 */

#include <iostream>

int main() {
    const std::string exclam = "!";
    const std::string message = "Hello" + ", world" + exclam;

    return 0;
}
