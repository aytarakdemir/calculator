#include <iostream>
#include <string>
#include <regex>
#include <stack>

/** 1. Take string input
 *  2. Convert infix to postfix
 *     a. Check the parantheses
 *     b. ???
 *     c. Profit
 *  3. Do the operation
 *
 *
 * class for converting infix->postfix
 * class for doing the operation
 */

class PostfixConverter
{
    std::string postfix;
public:
    PostfixConverter(std::string);
    bool checkParantheses();
    bool checkCharacters();
    bool doConversion();
};

PostfixConverter::PostfixConverter(std::string input)
{
    postfix = input;
}

// Checks if the parantheses are in the correct order.
bool PostfixConverter::checkParantheses()
{
    std::stack <char> parant_stack;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '(')
        {
            parant_stack.push('+');
        }
        if (postfix[i] == ')')
        {
            parant_stack.pop();
        }
    }
    if (parant_stack.empty()) return true;
    else                      return false;
}

/** Checks if the characters are valid and there aren't any '[digit](',
   ')[digit]', '[operator])' or '([operator]' strings in the input.
 *  Problem: Long ass regex
 *  Problem: You cannot write in the form (-[digit])
 * 
 */
bool PostfixConverter::checkCharacters()
{
    std::regex reg1("([[:d:]]|\\(|\\)|\\+|-|/|\\*)*([[:d:]]\\(|\\)[[:d:]]|"
    "(\\+|-|\\*|/)\\)|\\((\\+|-|\\*|/)|(\\+|-|\\*|/)(\\+|-|\\*|/))([[:d:]]"
    "|\\(|\\)|\\+|-|/|\\*)*");
    if (regex_match(postfix, reg1)) return false;

    std::regex reg2("([[:d:]]|\\(|\\)|\\+|-|/|\\*)*");
    if (regex_match(postfix, reg2)) return true;
    else                            return false;
}


class DoOperation
{

};

int main()
{
    std::string input;
    std::getline(std::cin, input);


    PostfixConverter convert(input);
    std::cout << convert.checkParantheses() << std::endl;
    std::cout << convert.checkCharacters();
}
