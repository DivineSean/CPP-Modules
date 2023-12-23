#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    static int i;
    _accountIndex = i++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbAccounts = _accountIndex + 1;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << (_accountIndex);
    std::cout << ";amount:" << _amount << ";closed" << std::endl;
}

int    Account::checkAmount( void ) const
{
    return _amount;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
    return;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;

    _nbDeposits = 1;
    _totalNbDeposits += _nbDeposits;
    _totalAmount += deposit;
    p_amount = _amount;
    _amount += deposit;
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    p_amount = _amount;
    if (_amount >= withdrawal)
    {
        _nbWithdrawals = 1;
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
    }
    _totalNbWithdrawals += _nbWithdrawals;
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount;
    if (_nbWithdrawals)
    {
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (1);
    }
    else
        std::cout << ";withdrawal:" << "refused" << std::endl;
    return 0;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t result = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&result);
    std::cout << std::put_time(timeInfo, "[%Y%m%d_%H%M%S] ");
}