#include <iostream>
#include <string>
#include <regex>
#include <stack>

#include "PostfixConverter.h"

/** 1. Take string input
 *  2. Convert infix to postfix
 *     a. Check the parantheses
 *     b. Check the characters
 *     c. ???
 *     d. Profit
 *  3. Do the operation
 *
 *
 * class for converting infix->postfix
 * class for doing the operation
 */


int main()
{
    std::cout << "##Equation Calculator##"
              << std::endl << "Equation: ";

    std::string input;
    do
    {
        std::getline(std::cin, input);
        PostfixConverter convert(input);
        if (convert.checkCharacters() && convert.checkParantheses())
        {
            convert.doConversion();
        }
        else std::cout << "Equation is not in the valid form." << std::endl;
    } while  (input != "q");

    std::cout << "Terminating";
    return 0;
}
