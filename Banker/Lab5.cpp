// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Banker.h"
using namespace std;

int main()
{
		Banker jollyBanker;
		jollyBanker.readTransactions("BankTransIn.txt");
		jollyBanker.processTrans();
		jollyBanker.BalanceOutput();
		return 0;
}