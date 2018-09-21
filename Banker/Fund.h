#pragma once
#include "Transaction.h"
#include <queue>

class Fund
{
public:
		Fund();
		~Fund();

		int getBalance() const;
		string getName() const;
		void setName(string fundName);
		void Deposit(int source);
		bool Withdraw(int source);
		void AddTrans(const Transaction &trans);

		void PrintHistory();
		void PrintHistoryOfFund();

private:
		int balance;
		string name;
		vector<Transaction> transHistory;
};