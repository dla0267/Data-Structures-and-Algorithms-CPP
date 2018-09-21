#pragma once

#include "Account.h"

class BSTree
{

public:
		BSTree();
		~BSTree();

		bool Insert(Account *source);
		bool Retrieve(const int &accountId, Account * &srcAccount) const;
		void Display() const;

		void Empty();
		bool isEmpty() const;

private:
		struct Node
		{
				Account *pAcct;
				Node *right = nullptr;
				Node *left = nullptr;
		};
		Node *root = nullptr;
		bool insertHelper(Node * node, Account *account);
		Node * emptyHelper(Node *node);
		void displayHelper(Node *node) const;
		Account * retrieveHelper(Node *node, const int &accountNum) const;

};
