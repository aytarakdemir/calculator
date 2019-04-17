#include <iostream>
#include <string>
#include <regex>
#include <stack>

#include "PostfixConverter.h"
#include "DoOperation.h"

/** 1. Take string input
 *  2. Convert infix to postfix
 *     a. Check the parantheses
 *     b. Check the characters
 *     c. ???
 *     d. Profit
 *  3. Do the postfix operation
 *
 *
 * Right now it can only perform '+,-,/,*' operations.
 * Write any operation using parantheses and it244
 * prints the result.
 * TODO: Only accepts numbers between 0 - 9.
 *       For example, 25 is interpreted as 2 and 5. Fix it
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
            DoOperation final(convert.doConversion());
            final.perform();
        }
        else if (input == "q") std::cout << "Terminating";
        else std::cout << "Equation is not in the valid form." << std::endl;
    } while  (input != "q");

    return 0;
}
