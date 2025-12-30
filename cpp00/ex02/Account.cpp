/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:37:12 by romukena          #+#    #+#             */
/*   Updated: 2025/12/30 08:31:41 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *local_time = localtime(&now);
	int year = local_time->tm_year + 1900;
	int month = local_time->tm_mon + 1;
	int day = local_time->tm_mday;

	int hour = local_time->tm_hour;
	int minute = local_time->tm_min;
	int second = local_time->tm_sec;

	std::cout <<"[" << year << std::setw(2) << std::setfill('0') << month << std::setw(2) << std::setfill('0') << day << "_" << std::setw(2) << std::setfill('0') << hour << std::setw(2) << std::setfill('0') << minute << std::setw(2) << std::setfill('0') << second << "]" << std::setfill(' ');;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " " << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";" << "deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	int old_amount = Account::_amount;
	Account::_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << " " << "index:" << _accountIndex << ";" << "p_amount:" << old_amount << ";" << "deposit:" << deposit << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;  
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";" << "amount:" << _amount - withdrawal << ";" << "nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		return true;
	}
	
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
	_totalAmount -= _amount;
	_nbAccounts--; 
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " " << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;  
	_nbAccounts++;
	_totalAmount += _amount;
}
