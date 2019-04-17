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
    for (size_t i = 0; i < postfix.length(); i++)
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
 *
 */
bool PostfixConverter::checkCharacters()
{
    std::regex reg1("([[:d:]]|\\(|\\)|\\+|-|/|\\*)*([[:d:]]\\(|\\)[[:d:]]|"
    "(\\+|-|\\*|/)\\)|\\((\\*|/)|(\\+|-|\\*|/)(\\+|-|\\*|/))([[:d:]]"
    "|\\(|\\)|\\+|-|/|\\*)*");
    if (regex_match(postfix, reg1)) return false;

    std::regex reg2("([[:d:]]|\\(|\\)|\\+|-|/|\\*)*");
    if (regex_match(postfix, reg2)) return true;
    else                            return false;
}

/* Converts infix to postfix.
 * TODO: Return value should be string.
 * TODO: 2*(4+5)+2 example operation, there is no '*'. Fix it.
 *
 */
bool PostfixConverter::doConversion()
{
    std::string out;
    std::stack <char> oper;

    for (size_t i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
        {
            out.push_back(postfix[i]);
        }
        if (postfix[i] == '+' ||
            postfix[i] == '-' ||
            postfix[i] == '(')
        {
            oper.push(postfix[i]);
        }
        if (postfix[i] == '*' ||
            postfix[i] == '/')
        {
            oper.push(postfix[i]);
            if (postfix[i + 1] != '(')
            {
                i++;
                out.push_back(postfix[i]);
                out.push_back(oper.top());
                oper.pop();
            }
        }
        if (postfix[i] == ')')
        {
            while (oper.top() != '(')
            {
                out.push_back(oper.top());
                oper.pop();
            }
            oper.pop();
        }
    }
    while (!oper.empty())
    {
        out.push_back(oper.top());
        oper.pop();
        std::cout << out;
        return true;
    }
}

class DoOperation
{

};

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
