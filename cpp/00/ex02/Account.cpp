#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"amount:"<<_amount<<';'<<"created"<<std::endl;
}

Account::Account( void )
{
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"amount:"<<_amount<<';'<<"created"<<std::endl;
}

Account::~Account( void ) 
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"amount:"<<_amount<<';'<<"closed"<<std::endl;
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
	std::cout<<"accounts:"<<_nbAccounts<<';'<<"total:"<<_totalAmount<<';';
	std::cout<<"deposits:"<<_totalNbDeposits<<';'<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"p_amount:"<<p_amount<<';';
	std::cout<<"deposit:"<<deposit<<';'<<"amount:"<<_amount<<';';
	std::cout<<"nb_deposits:"<<_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex<<';'<<"p_amount:"<<p_amount<<';';
		std::cout<<"withdrawal:refused"<<std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"p_amount:"<<p_amount<<';';
	std::cout<<"withdrawal:"<<withdrawal<<';'<<"amount:"<<_amount<<';';
	std::cout<<"nb_withdrawals:"<<_nbWithdrawals<<std::endl;	
	return true;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<';'<<"amount:"<<_amount<<';';
	std::cout<<"deposits"<<_nbDeposits<<';'<<"withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t timer = time(NULL);
	struct tm *t = localtime(&timer);
	std::cout << '[' << t->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1; 
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mday;
	std::cout << '_'; 
	std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_sec;
	std::cout << ']'<<' ';
}