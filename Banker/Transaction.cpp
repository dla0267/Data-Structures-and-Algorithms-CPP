#include "stdafx.h"
#include "Transaction.h"
#include <iostream>

Transaction::Transaction()
{
}

Transaction::Transaction(string type, int accountNum)
{
		this->transType = type;
		this->accountNum = accountNum;
}

Transaction::Transaction(string type, int accountNum, int fundNum)
{
		this->transType = type;
		this->accountNum = accountNum;
		this->fundNum = fundNum;
}

Transaction::Transaction(string type, int accountNum,
		int fundNum, int amount)
{
		this->transType = type;
		this->accountNum = accountNum;
		this->fundNum = fundNum;
		this->amount = amount;
}

Transaction::Transaction(string type, string firstName,
		string lastName, int accountNum)
{
		this->transType = type;
		this->firstName = firstName;
		this->lastName = lastName;
		this->accountNum = accountNum;
}

Transaction::Transaction(string type, int accountNum, int fundNum,
		int amount, int recipientAccountNum,
		int recipientFundNum)
{
		this->transType = type;
		this->accountNum = accountNum;
		this->fundNum = fundNum;
		this->amount = amount;
		this->recipientFundNum = recipientFundNum;
		this->recipientAccountNum = recipientAccountNum;

}

Transaction::Transaction(string type, int accountNum,
		int fundNum, int amount, string fail)
{
		this->transType = type;
		this->accountNum = accountNum;
		this->fundNum = fundNum;
		this->amount = amount;
		this->failed = fail;
}

Transaction::Transaction(string type, int accountNum, int fundNum, int amount,
		int recipientAccount, int recipientFund, string fail)
{
		this->transType = type;
		this->accountNum = accountNum;
		this->fundNum = fundNum;
		this->amount = amount;
		this->recipientFundNum = recipientFundNum;
		this->recipientAccountNum = recipientAccountNum;
		this->failed = fail;
}

Transaction::~Transaction() {
}

void Transaction::setTranType(string type)
{
		transType = type;
}

void Transaction::setFail()
{
		this->failed = "fail";
}

string Transaction::getTranType() const
{
		return transType;
}

string Transaction::getFirstName() const
{
		return firstName;
}

string Transaction::getLastName() const
{
		return lastName;
}

int Transaction::getAccountNum() const
{
		return accountNum;
}

int Transaction::getFundNum() const
{
		return fundNum;
}

int Transaction::getAmount() const
{
		return amount;
}

int Transaction::getRecipientAcntNum() const
{
		return recipientAccountNum;
}
int Transaction::getRecipientFundNum() const
{
		return recipientFundNum;
}

// to see if transaction is properly added or not.
ostream & operator<<(ostream & outStream, const Transaction & trans)
{
		if (trans.failed.length() == 0)
		{
				if (trans.getTranType() == "D" || trans.getTranType() == "W")
				{
						outStream << trans.getTranType() << " "
								<< trans.getAccountNum() << trans.getFundNum()
								<< " " << trans.getAmount();
				}
				else if (trans.getTranType() == "T")
				{
						outStream << trans.getTranType() << " "
								<< trans.getAccountNum() << trans.getFundNum()
								<< " " << trans.getAmount()
								<< " " << trans.getRecipientAcntNum()
								<< trans.getRecipientFundNum();
				}
				else if (trans.getTranType() == "O")
				{
						outStream << trans.getTranType() << " "
								<< trans.getFirstName() << " "
								<< trans.getLastName()
								<< " " << trans.getAccountNum();
				}
				else
				{
						outStream << trans.getTranType() << " " << trans.getAccountNum();
				}
		}
		else
		{
				if (trans.getTranType() == "D" || trans.getTranType() == "W")
				{
						outStream << trans.getTranType() << " "
								<< trans.getAccountNum() << trans.getFundNum()
								<< " " << trans.getAmount() << " (FAILED)";
				}
				else if (trans.getTranType() == "T")
				{
						outStream << trans.getTranType() << " "
								<< trans.getAccountNum() << trans.getFundNum()
								<< " " << trans.getAmount() << " "
								<< trans.getRecipientAcntNum()
								<< trans.getRecipientFundNum() << " (FAILED)";
				}
				else if (trans.getTranType() == "O")
				{
						outStream << trans.getTranType() << " "
								<< trans.getFirstName() << " "
								<< trans.getLastName()
								<< " " << trans.getAccountNum();
				}
				else
				{
						outStream << trans.getTranType() << " "
								<< trans.getAccountNum();
				}
		}
		return outStream;
}