// Student's name: Diego B Soares
// ID number: 145820239
// 02/18/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.	
/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_
#define SAVING_INTEREST 0.025
#define CHEQUING_INTEREST 0.005
#define SAVING_TRANS_FEE 3.50
#define CHEQUING_TRANS_FEE 1.25
#include <iomanip>


namespace seneca
{
   const int	 ACCT_MAXLEN_USER = 16;	// Max Length of user name

   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char	m_userName[ACCT_MAXLEN_USER];
      double	m_funds;
      bool	m_checking;
      int		m_monthlyTransactions;
      bool isWithdrawTrans = true; // this variable make sure we only print client is making a withdraw
      bool isDepositTrans = true; //  this variable make sure we only print if client is making a deposit
      bool isFeeTrans = false; // it just becomes true if its inside ++ overload
      bool isOpen() const;// return true if current user name string is not empty
   public:
      bankAccount(const char* name = nullptr, bool checking = false); // Default Constructor with default arguments
      bool setup(const char* name, bool checking); // Open bank account: setup can only be done once!
      operator double() const;// return current object balance
      operator bool() const;// return true if current account is open and balance different than 0
      void setDepositStatus(bool);// helper member function to control different behaves on overload functions
      void setWithdrawStatus(bool); // helper member function to control different behaves on overload functions
      void setFeeStatus(bool);// helper member function to control different results on operators overload
      bankAccount& operator++();// add interest into account if it has positive balance using overload +=
      bankAccount& operator--();// calculate monthly fees depending on type of account and how many transactions on that month using overload -=
      bool operator+= (double); // performs a deposit into current account
      bool operator-= (double); // performs a withdraw from current account
      bool operator== (const bankAccount&) const; // compares name, balance and type of account
      bool operator> (double) const; // compares current object's balance with double paramenter
      bool operator<= (double) const;// compares if current account's balance is less or equal to param
      bool operator<<(bankAccount&);// performs a balance transfer from parameter account to current account
      void display(void) const;// display all account information,
      friend bool isAccountOpen(const bankAccount& account);// friend function to access if account is open

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      // ...
   };

   // ADD: Global helpers
   bool operator> (double lhs, const bankAccount& rhs);// performs a comparison if lhs is greater than account balance
   bool operator<= (double lhs, const bankAccount& rhs);// performs a comparison if lhs is less o equal than account balance
   // ...
}
#endif

