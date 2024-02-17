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
      bool isOpen() const;
   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);
      operator double() const;
      operator bool() const;
      void setDepositStatus(bool);
      void setWithdrawStatus(bool);
      void setFeeStatus(bool);
      bankAccount& operator++();
      bankAccount& operator--();
      bool operator+= (double);
      bool operator-= (double);
      bool operator== (const bankAccount&) const;
      bool operator> (double) const;
      bool operator<= (double) const;
      bool operator<<(bankAccount&);
      void display(void) const;
      friend bool isAccountOpen(const bankAccount& account);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      // ...
   };

   // ADD: Global helpers
   bool operator> (double lhs, const bankAccount& rhs);
   bool operator<= (double lhs, const bankAccount& rhs);
   // ...
}
#endif

