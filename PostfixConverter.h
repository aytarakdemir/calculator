#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <regex>
#include <stack>

class PostfixConverter
{
    std::string postfix;
public:
    PostfixConverter(std::string input):postfix(input){}
    bool checkParantheses();
    bool checkCharacters();
    std::string doConversion();
};

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


/* Converts infix to postfix
   Returns a string of postfix
 */
std::string PostfixConverter::doConversion()
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
            else
            {
                oper.push(postfix[i]);
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
    }
    return out;
}

#endif
