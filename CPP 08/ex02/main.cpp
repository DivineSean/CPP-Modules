#include "MutantStack.hpp"
#include <vector>
#include <list>
#include <algorithm>
int main()
{
    std::cout << "**Testing Vector**" << std::endl;
    MutantStack<int, std::vector<int> > l;
    l.push(5);
    l.push(17);
    std::cout << l.top() << std::endl;
    l.pop();
    std::cout << l.size() << std::endl;
    l.push(3);
    l.push(5);
    l.push(737);
    l.push(0);
    MutantStack<int, std::vector<int> >::iterator i = l.begin();
    MutantStack<int, std::vector<int> >::iterator e = l.end();
    ++i;
    --i;
    while (i != e)
    {
        std::cout << *i << std::endl;
        ++i;
    }
    std::cout << "**Testing list**" << std::endl;
    MutantStack<int, std::list<int> > m;
    m.push(5);
    m.push(17);
    std::cout << m.top() << std::endl;
    m.pop();
    std::cout << m.size() << std::endl;
    m.push(3);
    m.push(5);
    m.push(737);
    m.push(0);
    MutantStack<int, std::list<int> >::iterator its = m.begin();
    MutantStack<int, std::list<int> >::iterator ites = m.end();
    ++its;
    --its;
    while (its != ites)
    {
        std::cout << *its << std::endl;
        ++its;
    }
    std::cout << "**Testing Subject Main**" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}