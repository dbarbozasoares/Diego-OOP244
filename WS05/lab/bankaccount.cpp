	/***********************************************************************
	// OOP244 Workshop #5 Lab (part 1)
	//
	// File  bankaccount.cpp
	// Version v0.8 Oct 21st 2023
	// Author  Jitesh Arora
	// Description
	//
	// Revision History
	// -----------------------------------------------------------
	// Name                 Date            Reason
	***********************************************************************/
	#define _CRT_SECURE_NO_WARNINGS

	#include "bankaccount.h"
	#include <iostream>
	#include <cstring>
	#include <cstdio>

	using namespace std;

	namespace seneca
	{
		// Default Constructor with default arguments
		bankAccount::bankAccount(const char* name, bool checking)
		{
			m_userName[0] = '\0';		// Empty string implies is account is not open 
			setup(name, checking);
		}

		// Open bank account: setup can only be done once!
		bool bankAccount::setup(const char* name, bool checking)
		{
			if (isOpen())					
				return false;
			if (name == nullptr)
				return false;

			strcpy(m_userName, name);	
			m_monthlyTransactions = 0;	
			m_checking = checking;
			m_funds = 0;
			return true;
		}

		void bankAccount::setWithdrawStatus(bool value)
		{
			this->isWithdrawTrans = value;
		}

		void bankAccount::setDepositStatus(bool value) {
			this->isDepositTrans = value;
		}

		void bankAccount::setFeeStatus(bool value) {
			this->isFeeTrans = value;
		}

		// Account is open if user name string is not empty
		bool bankAccount::isOpen() const
		{
			return (m_userName[0] != '\0');
		}

		bankAccount::operator double() const {
			return this->m_funds;
		}

		bankAccount::operator bool() const {
			return isOpen() && (m_funds != 0.0);
		}
		// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

		bankAccount& bankAccount::operator++() {
			if (this->isOpen() && this->m_funds > 0) {
				setFeeStatus(true);
				if (this->m_checking) {
					*this += (this->m_funds * CHEQUING_INTEREST);
				}
				else if(!this->m_checking){
					*this += (this->m_funds * SAVING_INTEREST);
				}
			}
			setFeeStatus(false);
			return *this;
		}

		bankAccount& bankAccount::operator--() {
			if (this->isOpen()) {
				setWithdrawStatus(false);
				if (this->m_checking) {
					*this -= (this->m_monthlyTransactions * CHEQUING_TRANS_FEE);
				}
				else if(!this->m_checking){
					*this -= (this->m_monthlyTransactions * SAVING_TRANS_FEE);
				}
			}
			return *this;
		}

		bool bankAccount::operator+= (double deposit) {
			bool checker = false;
			if (this->isOpen()) {
				if (isFeeTrans) {
					this->m_funds += deposit; // just do the math and doesn't count as a transaction
				}
				else if(!isDepositTrans){
					if(deposit > 0)
					cout << "Deposit $" << fixed << setprecision(2) << deposit << " for " << this->m_userName << endl;
					this->m_funds += deposit; // if it's other functions calling this += overload, it just performs the math needed and doesn't count as a transaction
				}
				else if (isDepositTrans) {
					this->m_funds += deposit;
					this->m_monthlyTransactions++;
					cout << "Deposit $" << fixed << setprecision(2) <<  deposit << " for " << this->m_userName << endl;
				}
				checker = true;
			}
			return checker;
		}

		bool bankAccount::operator-= (double withdraw) {
			bool validator = false;
			if (this->isOpen()) {

				if (!isWithdrawTrans) { // if its other function calling this overload -=, do the math but doesn't print and doesn't count as transaction
					setDepositStatus(false); // make sure it doesn't count as transaction on the following +=
					*this += (withdraw * (-1)); // returns a negative number so we subtract instead of add
				}
				else if (isWithdrawTrans) {
					cout << "Withdraw $" << withdraw << " for " << this->m_userName << endl;
					isDepositTrans = false; 
					*this += (withdraw * (-1));
					this->m_monthlyTransactions++;
				}
				
				validator = true;
			}
			setDepositStatus(true);
			return validator;
		}

		// compares name, balance and type of account
		bool bankAccount::operator== (const bankAccount& tmp) const {
			bool difference = ((this->m_funds - tmp.m_funds) < 0.001);
			return ((strcmp(this->m_userName, tmp.m_userName) == 0) && difference && (this->m_checking == tmp.m_checking));
		}

		bool bankAccount::operator> (double compare) const {
			return this->m_funds > compare;
		}

		bool bankAccount::operator<= (double compare) const {
			return this->m_funds <= compare;
		}

		bool bankAccount::operator<<(bankAccount& tmp) {
			bool validator = false;
			if (this->isOpen() && tmp.isOpen() && tmp > 0.0) {
				cout << "Transfer $" << tmp.m_funds << " from " << tmp.m_userName << " to " << this->m_userName << endl;
				setDepositStatus(false);
				*this += tmp.m_funds;
				setWithdrawStatus(false);
				tmp -= tmp.m_funds;
				validator = true;
				this->m_monthlyTransactions++;
			}
			isWithdrawTrans = true;
			isDepositTrans = true;
			return validator;
		}

		void bankAccount::display(void) const {
			char notOpen[10] = " NOT OPEN";
			const char* accType = this->m_checking ? "Checking" : "Savings";	

			if (!this->isOpen()) {
				accType = notOpen; // if account is not open, set type of account to NOT OPEN so we can print it out
				cout << "Display Account -> User:-------" << this->m_userName << accType << endl;
			}
			else {
				cout << "Display Account -> User:" << setfill('-') << setw(16) << this->m_userName 
				<<  " | " << setfill(' ') << setw(this->m_checking ? 0:8) << accType 
				<< setw(14) << setfill(' ') << "| Balance: $ "  << setw(7) << fixed << setprecision(2)<< this->m_funds
				<< " | Transactions:" << setw(3) << setfill('0') << this->m_monthlyTransactions << endl;
			}

			
		}

		// ADD: Global Helper Functions

		// friend function to access is account is open
		bool isAccountOpen(const bankAccount& account) 
		{
			return account.isOpen();
		}

		bool operator> (double lhs, const bankAccount& rhs) {
			bool validator = false;
			if (isAccountOpen(rhs)) { // using friend function to check if the account is open
				validator = lhs > (double)rhs;
			}
			return validator;
		}

		bool operator<= (double lhs, const bankAccount& rhs) {
			return !(lhs > (double)rhs);
		}
	}
