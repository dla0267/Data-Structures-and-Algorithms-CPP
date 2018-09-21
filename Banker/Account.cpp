#include "stdafx.h"
#include "Account.h"
#include <iostream>

Account::Account()
{
}

Account::Account(int accountNum, string lastName, string firstName)
{
		this->accountNum = accountNum;
		this->lastName = lastName;
		this->firstName = firstName;
		for (int i = 0; i < 10; i++)
		{
				funds[i].setName(fundNames[i]);
		}
}

Account::~Account() {
		// TODO Auto-generated destructor stub
}

int Account::getAccountNum() const
{
		return accountNum;
}

int Account::getFundNum() const
{
		return fundNum;
}

int Account::getFundBalance(int fundId) const
{
		return funds[fundId].getBalance();
}


string Account::getName() const
{
		return lastName + " " + firstName;
}

string Account::getFundName(const int &fundId) const
{
		return funds[fundId].getName();
}

void Account::Deposit(const int &fundNum, const int &amount)
{
		funds[fundNum].Deposit(amount);
}

void Account::AssistingWithdraw(int primaryFundNum,
		int assistingFundNum, int amount,
		const Transaction &trans)
{
		string tranType = trans.getTranType();
		int availableAmount = funds[primaryFundNum].getBalance();
		int amountLeft = amount - availableAmount;
		if (funds[assistingFundNum].getBalance() >= amountLeft)
		{
				funds[primaryFundNum].Withdraw(availableAmount);
				funds[assistingFundNum].Withdraw(amountLeft);
				if (tranType == "T")
				{
						int receiver = trans.getRecipientAcntNum();
						int receiverFund = trans.getRecipientFundNum();
						Transaction addTrans("T", accountNum, primaryFundNum,
								availableAmount, receiver, receiverFund);
						funds[primaryFundNum].AddTrans(addTrans);
						Transaction addTrans2("T", accountNum, assistingFundNum,
								amountLeft, receiver, receiverFund);
						funds[assistingFundNum].AddTrans(addTrans2);
				}
				else if (tranType == "W")
				{
						Transaction addTrans("W", accountNum,
								primaryFundNum, availableAmount);
						funds[primaryFundNum].AddTrans(addTrans);
						Transaction addTrans2("W", accountNum,
								assistingFundNum, amountLeft);
						funds[assistingFundNum].AddTrans(addTrans2);

				}
		}
		else
		{
				Transaction addFailTrans("W", accountNum, primaryFundNum,
						amount, "Fail");
				funds[primaryFundNum].AddTrans(addFailTrans);
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from "
						<< firstName << " " << lastName << " "
						<< this->getFundName(primaryFundNum) << endl;
		}
}

bool Account::Withdraw(const int &primaryFundNum,
		const int &amount,
		const Transaction &trans)
{
		if (primaryFundNum == 0 || primaryFundNum == 1
				|| primaryFundNum == 2 || primaryFundNum == 3)
		{
				if (primaryFundNum == 0)
				{
						if (funds[primaryFundNum].getBalance() >= amount)
						{
								funds[primaryFundNum].Withdraw(amount);
								funds[primaryFundNum].AddTrans(trans);
								return true;
						}
						else if (funds[primaryFundNum].getBalance()
								+ funds[1].getBalance() >= amount)
						{
								AssistingWithdraw(primaryFundNum, 1, amount, trans);
								return true;
						}
						else
						{
								AssistingWithdraw(primaryFundNum, 1, amount, trans);
								return false;
						}
				}
				else if (primaryFundNum == 1)
				{
						if (funds[primaryFundNum].getBalance() >= amount)
						{
								funds[primaryFundNum].Withdraw(amount);
								funds[primaryFundNum].AddTrans(trans);
								return true;
						}
						else if (funds[primaryFundNum].getBalance()
								+ funds[0].getBalance() >= amount)
						{
								AssistingWithdraw(primaryFundNum, 0, amount, trans);

								return true;
						}
						else
						{
								AssistingWithdraw(primaryFundNum, 0, amount, trans);
								return false;
						}
				}
				else if (primaryFundNum == 2)
				{
						if (funds[primaryFundNum].getBalance() >= amount)
						{
								funds[primaryFundNum].Withdraw(amount);
								funds[primaryFundNum].AddTrans(trans);
								return true;
						}
						else if (funds[primaryFundNum].getBalance()
								+ funds[3].getBalance() >= amount)
						{
								AssistingWithdraw(primaryFundNum, 3, amount, trans);
								return true;
						}
						else
						{
								AssistingWithdraw(primaryFundNum, 3, amount, trans);
								return false;
						}
				}
				else
				{
						if (funds[primaryFundNum].getBalance() >= amount)
						{
								funds[primaryFundNum].Withdraw(amount);
								funds[primaryFundNum].AddTrans(trans);
								return true;
						}
						else if (funds[primaryFundNum].getBalance()
								+ funds[2].getBalance() >= amount)
						{
								AssistingWithdraw(primaryFundNum, 2, amount, trans);
								return true;
						}
						else
						{
								AssistingWithdraw(primaryFundNum, 2, amount, trans);
								return false;
						}
				}
		}
		else
		{
				if (funds[primaryFundNum].getBalance() >= amount)
				{
						funds[primaryFundNum].Withdraw(amount);
						funds[primaryFundNum].AddTrans(trans);
						return true;
				}
				else
				{
						cout << "ERROR: Not enough funds to withdraw " << amount
								<< " from " << firstName << " " << lastName << " "
								<< this->getFundName(primaryFundNum) << endl;
						cerr << "ERROR: Not enough funds to withdraw " << amount
								<< " from " << firstName << " " << lastName << " "
								<< this->getFundName(primaryFundNum) << endl;
						Transaction failedTrans("W", accountNum, primaryFundNum,
								amount, "Fail");
						funds[primaryFundNum].AddTrans(failedTrans);
						return false;
				}
		}
}


void Account::Record(const int &fundNum, const Transaction &tran)
{
		funds[fundNum].AddTrans(tran);
}


void Account::PrintHistory()
{
		cout << "Transaction History for " << getName() << " by fund." << endl;
		for (int i = 0; i < 10; i++)
		{
				funds[i].PrintHistory();
		}

}

void Account::PrintHistoryOfFund(int fundNum)
{
		cout << "Transaction History for " << getName() << " "
				<< getFundName(fundNum) << ": $" << getFundBalance(fundNum) << endl;
		funds[fundNum].PrintHistoryOfFund();
}

ostream& operator<<(ostream &outStream, Account &source)
{
		outStream << source.getName() << " ID: " << source.getAccountNum() << endl;
		for (int i = 0; i < 10; i++)
		{
				outStream << "     " << source.getFundName(i) << " :$"
						<< source.getFundBalance(i) << endl;
		}
		return outStream;
}