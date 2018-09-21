#include "stdafx.h"
#include "Banker.h"
#include <fstream>
#include <iostream>
#include "Transaction.h"
#include <sstream>
using namespace std;

Banker::Banker()
{
}


Banker::~Banker()
{
}

void Banker::readTransactions(string textFile)
{
		ifstream inFile;
		inFile.open(textFile);
		if (!inFile)
		{
				cerr << "Unable to open the file" << endl;
		}
		string line;
		while (!inFile.eof())
		{
				getline(inFile, line);
				istringstream parseLine(line);
				string transType;
				parseLine >> transType;
				if (transType == "O")
				{
						string firstName, lastName;
						int accountNum;
						parseLine >> firstName >> lastName >> accountNum;
						Transaction transaction(transType, firstName,
								lastName, accountNum);
						trans.push(transaction);
				}
				else if (transType == "D" || transType == "W")
				{
						int accountNum;
						int fundNum;
						int amount;
						parseLine >> accountNum >> amount;
						fundNum = accountNum % 10;
						accountNum /= 10;
						Transaction transaction(transType, accountNum,
								fundNum, amount);
						trans.push(transaction);
				}
				else if (transType == "T")
				{
						int accountNum, fundNum, amount;
						int recipientAcntNum, recipientFundNum;
						parseLine >> accountNum >> amount >> recipientAcntNum;
						fundNum = accountNum % 10;
						accountNum /= 10;
						recipientFundNum = recipientAcntNum % 10;
						recipientAcntNum /= 10;
						Transaction transaction(transType, accountNum, fundNum, amount,
								recipientAcntNum, recipientFundNum);
						trans.push(transaction);
				}
				else if (transType == "H")
				{
						int accountNum;
						parseLine >> accountNum;
						Transaction transaction(transType, accountNum);
						trans.push(transaction);
				}
		}
}

void Banker::processTrans()
{
		while (!trans.empty())
		{
				Transaction transaction = trans.front();
				trans.pop();
				string type = transaction.getTranType();
				int accountNum = transaction.getAccountNum();
				Account *pAccount;
				if (type == "O")
				{
						string lastName = transaction.getLastName();
						string firstName = transaction.getFirstName();
						pAccount = new Account(accountNum, lastName, firstName);
						if (!clientAccounts.Insert(pAccount))
						{
								delete pAccount;
								pAccount = nullptr;
						}
				}
				else if (type == "D")
				{
						if (clientAccounts.Retrieve(accountNum, pAccount))
						{
								int amount = transaction.getAmount();
								int fundId = transaction.getFundNum();
								pAccount->Deposit(fundId, amount);
								pAccount->Record(fundId, transaction);
						}
				}
				else if (type == "W")
				{
						if (clientAccounts.Retrieve(accountNum, pAccount))
						{
								int amount = transaction.getAmount();
								int fundNum = transaction.getFundNum();
								pAccount->Withdraw(fundNum, amount, transaction);
						}
				}
				else if (type == "T")
				{
						Account *sender;
						Account *receiver;
						int accountNum = transaction.getAccountNum();
						int recipientAcctNum = transaction.getRecipientAcntNum();
						int senderFundNum = transaction.getFundNum();
						int recipientFundNum = transaction.getRecipientFundNum();
						int amount = transaction.getAmount();
						if (clientAccounts.Retrieve(accountNum, sender) &&
								clientAccounts.Retrieve(recipientAcctNum, receiver))
						{
								int firstAmount = sender->getFundBalance(senderFundNum);
								if (sender->Withdraw(senderFundNum, amount, transaction))
								{
										if (sender->getFundBalance(senderFundNum) >= amount) {
												receiver->Deposit(recipientFundNum, amount);
												receiver->Record(recipientFundNum, transaction);
										}
										else
										{
												int secondAmount = amount - firstAmount;
												int secondFundNum;
												if (senderFundNum == 0)
												{
														secondFundNum = 1;
												}
												else if (senderFundNum == 1)
												{
														secondFundNum = 0;
												}
												else if (senderFundNum == 2)
												{
														secondFundNum = 3;
												}
												else
												{
														secondFundNum = 2;
												}
												receiver->Deposit(recipientFundNum, amount);
												Transaction firstTran("T", accountNum, senderFundNum,
														firstAmount, recipientAcctNum,
														recipientFundNum);
												Transaction secondTran("T", accountNum, secondFundNum,
														secondAmount, recipientAcctNum,
														recipientFundNum);
												receiver->Record(recipientFundNum, firstTran);
												receiver->Record(recipientFundNum, secondTran);
										}
								}
								else
								{
										cerr << "ERROR: Not enough Funds to Transfer " << amount
												<< " " << "from " << sender->getAccountNum()
												<< senderFundNum << " to "
												<< receiver->getAccountNum()
												<< recipientFundNum << endl;
										Transaction failedTrnas("T", accountNum, senderFundNum,
												amount, recipientAcctNum,
												recipientFundNum, "Failed");
										sender->Record(senderFundNum, failedTrnas);
								}
						}
						else if (!clientAccounts.Retrieve(accountNum, sender))
						{
								cout << "ERROR: Account " << accountNum
										<< " not found. Transferal refused." << endl;
								cerr << "ERROR: Account " << accountNum
										<< " not found. Transferal refused." << endl;
						}
						else if (!clientAccounts.Retrieve(recipientAcctNum, receiver))
						{
								cout << "ERROR: Account " << recipientAcctNum
										<< " not found. Transferal refused." << endl;
								cerr << "ERROR: Account " << recipientAcctNum
										<< " not found. Transferal refused." << endl;

						}
						else
						{
								cout << "ERROR: Account " << accountNum << " and "
										<< recipientAcctNum
										<< " not found. Transferal refused." << endl;
								cerr << "ERROR: Account " << accountNum << " and "
										<< recipientAcctNum
										<< " not found. Transferal refused." << endl;
						}
				}
				else
				{
						if (transaction.getAccountNum() >= 10000 &&
								transaction.getAccountNum() <= 99999) // account number with fund Number
						{
								accountNum = transaction.getAccountNum() / 10;
								if (clientAccounts.Retrieve(accountNum, pAccount))
								{
										int fundId = transaction.getAccountNum() % 10;
										pAccount->PrintHistoryOfFund(fundId);
								}
								else
								{
										cout << "ERROR: Account " << accountNum
												<< " not found. Transaction refused." << endl;
										cerr << "ERROR: Account " << accountNum
												<< " not found. Transaction refused." << endl;
								}
						}
						else if (transaction.getAccountNum() < 10000 &&
								transaction.getAccountNum() >= 1000)
						{
								if (clientAccounts.Retrieve(accountNum, pAccount))
								{
										pAccount->PrintHistory();
								}
								else
								{
										cout << "ERROR: Account " << accountNum
												<< " not found. Transaction refused." << endl;
										cerr << "ERROR: Account " << accountNum
												<< " not found. Transaction refused." << endl;
								}
						}
				}
		}
}

void Banker::BalanceOutput() const
{
		cout << endl;
		cout << "Processing Done. Final Balances" << endl;
		clientAccounts.Display();
}

void Banker::erase()
{
		clientAccounts.Empty();
}