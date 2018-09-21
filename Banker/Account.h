#pragma once
#include <string>
#include <vector>
#include "Fund.h"
#include "Transaction.h"

const string fundNames[] = { "Money Market", "Prime Money Market",
"Long-Term Bond", "Short-Term Bond",
"500 Index Fund", "Capital Value Fund",
"Growth Equity Fund", "Growth Index Fund",
"Value Fund", "Value Stock Index" };

class Account
{
		friend ostream& operator<<(ostream &outStream, Account &source);
public:
		Account();
		Account(int id, string lastName, string firstName);
		~Account();

		int getAccountNum() const;
		int getFundNum() const;

		string getName() const;
		string getFundName(const int &fundNum) const;
		int getFundBalance(int fundId) const;

		void Deposit(const int &fundNum, const int &amount);
		bool Withdraw(const int &primaryFundNum,
				const int &amount, const Transaction& trans);
		void AssistingWithdraw(int primaryFundNum, int assistingFundNum,
				int amount, const Transaction& trans);
		void Record(const int &fundNum, const Transaction &tran);

		void PrintHistory();
		void PrintHistoryOfFund(int fundId);

private:
		int accountNum;
		int fundNum;
		string lastName;
		string firstName;
		Fund funds[10];
};
