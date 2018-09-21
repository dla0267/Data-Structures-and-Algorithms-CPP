#pragma once
#include <string>
using namespace std;

class Transaction
{
		friend ostream & operator<<(ostream &outStream, const Transaction &trans);
public:
		Transaction();
		Transaction(string type, int accountNum);
		Transaction(string type, int accountNum, int fundNum);
		Transaction(string type, int accountNum, int fundNum, int amount);
		Transaction(string type, string firstName,
				string lastName, int accountNum);
		Transaction(string type, int accountNum, int fundNum, int amount,
				int recipientAccountNum, int recipientFundNum);

		// constructors for failed transactions
		Transaction(string type, int accountNum,
				int fundNum, int amount, string fail);
		Transaction(string type, int accountNum, int fundNum, int amount,
				int recipientAccount, int recipientFund, string fail);
		~Transaction();

		void setTranType(string type);
		void setFail();

		string getTranType() const;
		string getFirstName() const;
		string getLastName() const;

		int getAccountNum() const;
		int getFundNum() const;
		int getAmount() const;
		int getRecipientAcntNum() const;
		int getRecipientFundNum() const;

private:
		string transType;
		string firstName;
		string lastName;
		string failed;
		int accountNum;
		int fundNum;
		int amount;
		int recipientAccountNum;
		int recipientFundNum;
};
