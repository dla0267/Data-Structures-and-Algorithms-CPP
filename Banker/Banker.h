#pragma once

#include "BSTree.h"
#include "Transaction.h"
#include <queue>

class Banker
{
public:
		Banker();
		~Banker();

		void readTransactions(string textFile);
		void processTrans();
		void BalanceOutput() const;
		void erase();

private:
		BSTree clientAccounts;
		queue<Transaction> trans;
		vector<int> clientIDs;
};