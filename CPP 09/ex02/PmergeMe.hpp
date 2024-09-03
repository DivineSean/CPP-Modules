#pragma once

# include <iostream>
# include <vector>
# include <sstream>
# include <ctime>
# include <deque>
class PmergeMe
{
    private:
        std::vector< std::pair<int, int> > Pair_v;
        std::vector<int>                   v;
        std::deque< std::pair<int, int> > Pair_d;
        std::deque<int>                    d;
        bool                               flag;
        PmergeMe();
    public:
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe &copy);
        bool    parssing(std::string av);
        void    Ford_Johnson_Algorithm();
        void    printing(std::string call);
        void    Filling_Pair_v();
        void    Filling_Pair_d();
        void    MergeInsert_SortV();
        void    MergeInsert_SortD();
        void    Filling_Vectors(std::vector<int> &B);
        void    Filling_deques(std::deque<int> &B);
        void    Insert_SortingV();
        void    Insert_SortingD();
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
};