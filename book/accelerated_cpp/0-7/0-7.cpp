/* 0-7 
 * 
 * No. The preprocessor doesn't understand nested comments, so, as the
 * first end-comment delimiter is reached, the comment ends and the rest
 * of the line is treated as normal statments.
 *
 * P.S.: WON'T COMPILE!
 */

#include <iostream>

int main()
{
    /* This is a comment that extends over several lines
       because it uses /* and */ as its starting and ending delimiters */
    std:cout << "Does this work?" << std::endl;
    return 0;
}
