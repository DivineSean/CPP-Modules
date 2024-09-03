#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

bool	valid(std::string s)
{
	size_t i = 0;
	while(s[i])
	{
		if (!isdigit(s[i]) && !(s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-'))
			return false;
		i++;
	}
	return true;
}

bool checkAv(std::string av)
{
	size_t i = 0;
	std::string str = av;
	size_t count = 0;

	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	if (!valid(str))
		return false;
	while(str[i])
	{
		while(str[i] && isdigit(str[i]))
		{
			i++;
			count++;
		}
		if (!str[i])
			return false;
		while(str[i] && (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '-'))
			i++;
		if (!(i - count == count - 1))
			return false;
	}
	return true;
}

int	my_operator(int a, int b, char op)
{
	long long nb = 0;
	if (op == '*')
		nb = a * b;
	else if (op == '+')
		nb = a + b;
	else if (op == '-')
		nb = a - b;
	else if (op == '/')
	{
		if (b == 0)
		{
			std::cerr << "We Cannot Devide " << a << " by " << b << "." << std::endl;
			exit(1);
		}
		else
			nb = a / b;
	}
	if (nb > INT_MAX)
	{
		std::cerr << "Large Number great than MAX INT Detected." << " Putting INT MAX By Default." << std::endl;
		nb = INT_MAX;
	}
	else if (nb < INT_MIN)
	{
		std::cerr << "Large Number great than MIN INT Detected." << " Putting INT MIN By Default." << std::endl;
		nb = INT_MIN;
	}
	return nb;
}

bool	parssing(std::string av, std::stack<int> &num)
{
	std::istringstream ss(av);
	std::string str;

	if (av.empty() || !checkAv(av))
		return false;
	if (isspace(av[av.size() - 1]))
		return false;
	while(getline(ss, str, ' '))
	{
		if (str.size() >= 2)
			return false;
		if (!isdigit(str[0]))
		{
			if (num.size() < 2)
				return false;
			int a = num.top();
			num.pop();
			int b = num.top();
			num.pop();
			num.push(my_operator(b, a, str[0]));
		}
		else
			num.push(str[0] - 48);
	}
	if (num.size() != 1)
		return false;
	std::cout << num.top() << std::endl;
	return true;
}

void    RPN::FillingStack(std::string av)
{
	if (!parssing(av, this->num))
		std::cerr << "Error" << std::endl;
	return;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		this->num = copy.num;
	return *this;
}

RPN::~RPN()
{
}