/* 0-3
 *
 * $ uname -prs
 * OpenBSD 5.2 amd64
 * $
 *
 * This environment prints 8 (eight) spaces as a tab character.
 */

#include <iostream>

int main() {
    std::cout << "\ttest" << std::endl;
}
