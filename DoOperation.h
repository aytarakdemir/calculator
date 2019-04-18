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
    // Problem: 1+3*2+1 returns 17
    for (size_t i = 0; i < postfix.length(); i++)
    {
        int temp;
        if (postfix[i] == '+')
        {
            temp = (postfix[i - 2] - '0') + (postfix[i - 1] - '0');
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp + '0');
            i = i - 2;
        }
        if (postfix[i] == '-')
        {
            temp = (postfix[i - 2] - '0') - (postfix[i - 1] - '0');
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp + '0');
            i = i - 2;
        }
        if (postfix[i] == '*')
        {
            temp = (postfix[i - 2] - '0') * (postfix[i - 1] - '0');
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp + '0');
            i = i - 2;
        }
        if (postfix[i] == '/')
        {
            temp = (postfix[i - 2] - '0') / (postfix[i - 1] - '0');
            postfix.erase(i - 2, 3);
            postfix.insert(i - 2, 1, temp + '0');
            i = i - 2;
        }
    }
    std::cout << postfix << std::endl;
}

#endif
