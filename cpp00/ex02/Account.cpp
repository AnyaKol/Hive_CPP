/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:56:34 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 17:25:01 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) {}

Account::Account( int initial_deposit )
: _accountIndex(Account::_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount );
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout <<  "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount() << ";deposit:";

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << deposit	
		<< ";amount:" << this->checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount() << ";withdrawal:";

	if (withdrawal > this->checkAmount()) {
		std::cout << "refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	std::cout << withdrawal	
		<< ";amount:" << this->checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	time;
	std:: tm	tm;

	std::time(&time);
	localtime_r(&time, &tm);
	std::cout << "[" << tm.tm_year + 1900;
	if (tm.tm_mon < 9)
		std::cout << "0";
	std::cout << tm.tm_mon + 1 << tm.tm_mday << "_";
	if (tm.tm_hour < 10)
		std::cout << "0";
	std::cout << tm.tm_hour;
	if (tm.tm_min < 10)
		std::cout << "0";
	std::cout << tm.tm_min;
	if (tm.tm_sec < 10)
		std::cout << "0";
	std::cout << tm.tm_sec << "] ";
}
