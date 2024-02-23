// Student's name: Diego B Soares
// ID number: 145820239
// 02/18/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.	
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

		//@param true or false
		//@brief helper member function to control different behaves on overload functions
		void bankAccount::setWithdrawStatus(bool value)
		{
			this->isWithdrawTrans = value;
		}

		//@param true or false
		//@brief helper member function to control different behaves on overload functions
		void bankAccount::setDepositStatus(bool value) {
			this->isDepositTrans = value;
		}

		//@param true or false
		//@brief helper member function to control different results on operators overload
		void bankAccount::setFeeStatus(bool value) {
			this->isFeeTrans = value;
		}

		// return true if current user name string is not empty
		bool bankAccount::isOpen() const
		{
			return (m_userName[0] != '\0');
		}

		// return current object balance
		bankAccount::operator double() const {
			return this->m_funds;
		}

		// return true if current account is open and balance different than 0
		bankAccount::operator bool() const {
			return isOpen() && (m_funds != 0.0);
		}
		// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

		//@return current object
		//@brief add interest into account if it has positive balance using overload +=
		bankAccount& bankAccount::operator++() {
			if (this->isOpen() && this->m_funds > 0) {
				setFeeStatus(true); // make sure we do the right output on += overload
				if (this->m_checking) {
					*this += (this->m_funds * CHEQUING_INTEREST);
				}
				else if(!this->m_checking){
					*this += (this->m_funds * SAVING_INTEREST);
				}
			}
			setFeeStatus(false); // set back to false so other overload operators work as expected
			return *this;
		}
		//@return current object
		//@brief calculate monthly fees depending on type of account and how many transactions on that month using overload -=
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

		// @param value to deposit.
		// @return true if operation successful
		// @brief 1- If it's a fee transaction, just performs math
		// 2- If it's other functions calling it, it doesn't count as 1 transaction
		// 3- If it's indeed a deposit transaction, do all number 2 and counts as 1 transaction
		bool bankAccount::operator+= (double deposit) {
			bool checker = false;
			if (this->isOpen()) {
				if (isFeeTrans) { // on overload ++ it sets to true so this if works only if called from ++ operator
					this->m_funds += deposit; // just do the math and doesn't count as a transaction
				}
				else if(!isDepositTrans){ // if its called from any other operator, add deposit value into account, prints receipt but don't count as 1 transaction
					if(deposit > 0)
					cout << "Deposit $" << fixed << setprecision(2) << deposit << " for " << this->m_userName << endl;
					this->m_funds += deposit;
				}
				else if (isDepositTrans) {
					cout << "Deposit $" << fixed << setprecision(2) <<  deposit << " for " << this->m_userName << endl;
					this->m_funds += deposit;
					this->m_monthlyTransactions++; // if it's a deposit transaction, count as 1 transaction
				}
				checker = true;
			}
			return checker;
		}

		//@return true if operation successful
		//@param value to withdraw
		// @brief executes a withdraw if account is open, if it's other functions calling it, do math only
		bool bankAccount::operator-= (double withdraw) {
			bool validator = false;
			if (this->isOpen()) {
				setDepositStatus(false); // make sure it doesn't count as transaction on the following +=
				if (!isWithdrawTrans) { // if its other function calling this overload -=, do the math but doesn't print and doesn't count as transaction
					*this += (withdraw * (-1)); // returns a negative number so we subtract instead of add
				}
				else if (isWithdrawTrans) { // if it's a withdraw transaction, prints statement, do math and counts as 1 transaction
					cout << "Withdraw $" << withdraw << " for " << this->m_userName << endl;
					*this += (withdraw * (-1));
					this->m_monthlyTransactions++;
				}
				validator = true;
			}
			setDepositStatus(true); // set deposit status back to original so it doesn't interferee on += overload
			return validator;
		}

		//@return true if accounts are equal
		//@param object to compare with current object
		//@brief compares name, balance and type of account
		bool bankAccount::operator== (const bankAccount& tmp) const {
			bool difference = ((this->m_funds - tmp.m_funds) < 0.001);
			return ((strcmp(this->m_userName, tmp.m_userName) == 0) && difference && (this->m_checking == tmp.m_checking));
		}

		//@return true if current object balance is greater than param
		//@param value to compare to current object's balance
		//@brief compares current object's balance with double paramenter
		bool bankAccount::operator> (double compare) const {
			return this->m_funds > compare;
		}

		//@return true if current account's balance is less or equal to param
		//@param value to compare to current account's balance
		//@brief compares if current account's balance is less or equal to param
		bool bankAccount::operator<= (double compare) const {
			return this->m_funds <= compare;
		}

		//@return true if operation successful
		//@param account instance to pull balance
		//@brief performs a balance transfer from parameter account to current account
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
			setWithdrawStatus(true);
			setDepositStatus(true);
			return validator;
		}

		// display all account information,
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

		// friend function to access if account is open
		bool isAccountOpen(const bankAccount& account) 
		{
			return account.isOpen();
		}

		//@return true if it's greater
		//@param lhs double value to compare
		//@param rhs account instance to compare balance
		//@brief performs a comparison if lhs is greater than account balance
		bool operator> (double lhs, const bankAccount& rhs) {
			bool validator = false;
			if (isAccountOpen(rhs)) { // using friend function to check if the account is open
				validator = lhs > (double)rhs;
			}
			return validator;
		}


		//@return true if is less or equal
		//@param lhs double value to compare
		//@param rhs account instance to compare balance
		//@brief performs a comparison if lhs is less o equal than account balance
		bool operator<= (double lhs, const bankAccount& rhs) {
			return !(lhs > (double)rhs);
		}
	}
