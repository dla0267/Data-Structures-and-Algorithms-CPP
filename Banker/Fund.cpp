#include "stdafx.h"
#include "Fund.h"
#include <iostream>

Fund::Fund()
{
		balance = 0;
}

Fund::~Fund()
{
		// TODO Auto-generated destructor stub
}

int Fund::getBalance() const
{
		return balance;
}

string Fund::getName() const
{
		return name;
}

void Fund::setName(string fundName)
{
		this->name = fundName;
}


void Fund::Deposit(int source)
{
		balance += source;
}

bool Fund::Withdraw(int source)
{
		if (balance >= source) {
				balance -= source;
				return true;
		}
		else
		{
				return false;
		}
}

void Fund::AddTrans(const Transaction &trans)
{
		transHistory.push_back(trans);
}


void Fund::PrintHistory()
{
		if (transHistory.size() == 0)
		{
				return;
		}
		else
		{
				cout << name << ": $" << balance << endl;
				for (int i = 0; i < transHistory.size(); i++)
				{
						cout << "   " << transHistory[i] << endl;
				}
		}
}

void Fund::PrintHistoryOfFund()
{
		if (transHistory.size() == 0)
		{
				cout << "     There are no transactions made" << endl;
		}
		else
		{
				for (int i = 0; i< transHistory.size(); i++)
				{
						cout << "   " << transHistory[i] << endl;
				}
		}
}