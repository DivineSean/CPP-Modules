#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){flag = false;}

PmergeMe::PmergeMe(int ac, char **av) :flag(false)
{
	int i = 1;
	while(i < ac)
	{
		if (!parssing(av[i]))
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	Filling_Pair_v();
	Filling_Pair_d();
	Ford_Johnson_Algorithm();
}

void	PmergeMe::Filling_Pair_d()
{
	size_t i = 0;
	size_t len = d.size();
	if (len % 2 == 1)
	{
		len -= 1;
		flag = true;
	}
	while(i < len)
	{
		Pair_d.push_back(std::make_pair(d[i], d[i + 1]));
		i += 2;
	}
	if (flag == true)
		Pair_d.push_back(std::make_pair(d[i], -1));
	return;
}

void	PmergeMe::Filling_Pair_v()
{
	size_t i = 0;
	size_t len = v.size();
	if (len % 2 == 1)
	{
		len -= 1;
		flag = true;
	}
	while(i < len)
	{
		Pair_v.push_back(std::make_pair(v[i], v[i + 1]));
		i += 2;
	}
	if (flag == true)
		Pair_v.push_back(std::make_pair(v[i], -1));
	return;
}

void	sort_pairs(std::vector< std::pair<int, int> > &Pair_v, bool flag)
{
	std::vector< std::pair<int, int> >::iterator len = Pair_v.end();

	if (flag == true)
		len -= 1;
	sort(Pair_v.begin(), len);
	return;
}

void	sort_pairs_d(std::deque< std::pair<int, int> > &Pair_d, bool flag)
{
	std::deque< std::pair<int, int> >::iterator len = Pair_d.end();

	if (flag == true)
		len -= 1;
	sort(Pair_d.begin(), len);
	return;		
}

void	Merge_vectors(std::vector< std::pair<int, int> > &Pair_v, bool flag)
{
	size_t i = 0;
	size_t len = Pair_v.size();

	if (flag == true)
		len -= 1;
	while(i < len)
	{
		if (Pair_v[i].first < Pair_v[i].second)
		{
			int tmp = Pair_v[i].first;
			Pair_v[i].first = Pair_v[i].second;
			Pair_v[i].second = tmp;
		}
		i++;
	}
	sort_pairs(Pair_v, flag);
}

void	Merge_deques(std::deque< std::pair<int, int> > &Pair_d, bool flag)
{
	size_t i = 0;
	size_t len = Pair_d.size();

	if (flag == true)
		len -= 1;
	while(i < len)
	{
		if (Pair_d[i].first < Pair_d[i].second)
		{
			int tmp = Pair_d[i].first;
			Pair_d[i].first = Pair_d[i].second;
			Pair_d[i].second = tmp;
		}
		i++;
	}
	sort_pairs_d(Pair_d, flag);
}

void	PmergeMe::MergeInsert_SortV()
{
	Merge_vectors(Pair_v, flag);
	Insert_SortingV();
	return;
}

void	PmergeMe::MergeInsert_SortD()
{
	Merge_deques(Pair_d, flag);
	Insert_SortingD();
	return;
}

void	PmergeMe::Filling_deques(std::deque<int> &B)
{
	size_t i = 0;
	size_t len = Pair_d.size();

	d.clear();
	if (flag == true)
		len -= 1;
	while(i < len)
	{
		d.push_back(Pair_d[i].first);
		B.push_back(Pair_d[i].second);
		i++;
	}
	if (flag == true)
		B.push_back(Pair_d[i].first);
	return;
}

void	PmergeMe::Filling_Vectors(std::vector<int> &B)
{
	size_t i = 0;
	size_t len = Pair_v.size();

	v.clear();
	if (flag == true)
		len -= 1;
	while(i < len)
	{
		v.push_back(Pair_v[i].first);
		B.push_back(Pair_v[i].second);
		i++;
	}
	if (flag == true)
		B.push_back(Pair_v[i].first);
	return;
}

std::vector<int> JacobFormula(size_t n)
{
	//J(n) = J(n - 1) + 2J(n - 2)
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	if (n <= 2)
		return jacob;
	for (size_t i = 2; i <= n; i++)
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
	return jacob;
}

std::deque<int> JacobFormulaD(size_t n)
{
	//J(n) = J(n - 1) + 2J(n - 2)
	std::deque<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	if (n <= 2)
		return jacob;
	for (size_t i = 2; i <= n; i++)
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
	return jacob;
}

void jacobsthal_numbersV(size_t n, std::vector<int> &jacob)
{
	jacob = JacobFormula(n);
	if (n <=2)
		return ;
	std::vector<int> tmp;
	tmp = jacob;
	jacob.clear();
	for (size_t i = 0; i < tmp.size(); i++)
	{
		int a = tmp[i];
		int b = tmp[i+1];
		while(b > a)
			jacob.push_back(b--);
		if (jacob.size() >= n)
			break;
	}
	for (size_t i = 0; i < jacob.size(); i++)
		jacob[i] -= 1;
}

void jacobsthal_numbersD(size_t n, std::deque<int> &jacob)
{
	jacob = JacobFormulaD(n);
	if (n <=2)
		return ;
	std::deque<int> tmp;
	tmp = jacob;
	jacob.clear();
	for (size_t i = 0; i < tmp.size(); i++)
	{
		int a = tmp[i];
		int b = tmp[i+1];
		while(b > a)
			jacob.push_back(b--);
		if (jacob.size() >= n)
			break;
	}
	for (size_t i = 0; i < jacob.size(); i++)
		jacob[i] -= 1;
}

void	PmergeMe::Insert_SortingV()
{
	std::vector<int> B;

	std::vector<int> jacobs;

	Filling_Vectors(B);
	jacobsthal_numbersV(B.size(), jacobs);
	v.insert(v.begin(), B[0]);
	size_t j = 1;
	while(j < jacobs.size())
	{
		if ((jacobs[j] < (int)B.size()))
		{
			std::vector<int> ::iterator it = std::lower_bound(v.begin(), v.end(), B[jacobs[j]]);
			v.insert(it, B[jacobs[j]]);
		}
		j++;
	}
	B.clear();
	return;
}

void	PmergeMe::Insert_SortingD()
{
	std::deque<int> B;

	std::deque<int> jacobs;

	Filling_deques(B);
	jacobsthal_numbersD(B.size(), jacobs);
	d.insert(d.begin(), B[0]);
	size_t j = 1;
	while(j < jacobs.size())
	{
		if ((jacobs[j] < (int)B.size()))
		{
			std::deque<int> ::iterator it = std::lower_bound(d.begin(), d.end(), B[jacobs[j]]);
			d.insert(it, B[jacobs[j]]);
		}
		j++;
	}
	B.clear();
	return;
}

void	PmergeMe::Ford_Johnson_Algorithm()
{
	printing("Before");
	clock_t v_time = clock();
	MergeInsert_SortV();
	clock_t v_time_ = clock();
	MergeInsert_SortD();
	clock_t d_time = clock();
	printing("After");
	std::cout << "Time to process a range of  " << v.size() << " elements with std::vector : " << (double)(v_time_ - v_time) << " us" << std::endl;
	std::cout << "Time to process a range of  " << d.size() << " elements with std::deque : " << (double)(d_time - v_time_) << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

bool	is_digit(std::string str)
{
	size_t i = 0;
	if (str.empty())
		return false;
	while(str[i])
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

void	PmergeMe::printing(std::string call)
{
	size_t i = 0;
	if (call == "Before")
		std::cout << "Before: ";
	else
		std::cout << "After:  ";
	while(i < d.size() - 1)
	{
		std::cout << d[i] << " ";
		i++;
	}
	std::cout << d[i] <<  std::endl;
}

bool	PmergeMe::parssing(std::string av)
{
	if (av.empty())
		return false;
	if (isspace(av[0]) || isspace(av[av.size() - 1]))
		return false;
	std::istringstream ss(av);
	std::string str;
	long long nb = 0;
	while(getline(ss, str, ' '))
	{
		if (!(str.size() <= 10 && is_digit(str) && (nb = std::strtod(str.c_str(), NULL)) < INT_MAX))
			return false;
		v.push_back(nb);
		d.push_back(nb);
	}
	return true;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
		this->v = copy.v;
	return (*this);
}

PmergeMe::~PmergeMe(){}