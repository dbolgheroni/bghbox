/* 1-5
 *
 * No. The 'x' variable is out of scope. 
 */

#include <iostream>
#include <string>

/*
int main() {
    { std::string s = "a string";
    { std::string x = s + ", really"; 
      std::cout << s << std::endl; }
      std::cout << x << std::endl;
    }
    return 0;
}
*/

/* program rewrited */
int main() {
    { 
        std::string s = "a string";
        std::string x = s + ", really"; 
        {
            std::cout << s << std::endl;
        }

        std::cout << x << std::endl;
    }

    return 0;
}
