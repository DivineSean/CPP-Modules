#pragma once
# include <stack>
# include <iostream>
# include <sstream>
# include <climits>
class RPN
{
    private:
        std::stack<int> num;
    public:
        RPN();
        RPN(const RPN &copy);
        void    FillingStack(std::string av);
        RPN &operator=(const RPN &copy);
        ~RPN();
};