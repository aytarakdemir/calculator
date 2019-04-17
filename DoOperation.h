#ifndef DO_OPERATION_H
#define DO_OPERATION_H

#include <string>

class DoOperation
{
    std::string postfix;
public:
    DoOperation(std::string in):postfix(in){}
    void perform();
};

void DoOperation::perform()
{
    // TODO: Fix code repeat.
    // TODO: Performs opeartions on chars, cast them to ints.
    for (size_t i = 0; i < postfix.length(); i++)
    {
        int temp;
        if (postfix[i] == '+')
        {
            temp = postfix[i - 2] + postfix[i - 1];
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp);
            i = i - 2;
        }
        if (postfix[i] == '-')
        {
            temp = postfix[i - 2] - postfix[i - 1];
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp);
            i = i - 2;
        }
        if (postfix[i] == '*')
        {
            temp = postfix[i - 2] * postfix[i - 1];
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp);
            i = i - 2;
        }
        if (postfix[i] == '/')
        {
            temp = postfix[i - 2] / postfix[i - 1];
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp);
            i = i - 2;
        }
    }
    std::cout << postfix << std::endl;
}

#endif
