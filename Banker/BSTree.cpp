#include "stdafx.h"
#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree()
{
		root = nullptr;
}

BSTree::~BSTree()
{
		Empty();
}

bool BSTree::Insert(Account *account)
{
		int accountNum = account->getAccountNum();
		if (accountNum < 1000 || accountNum > 9999)
		{
				cout << "ERROR: Account Number Not Valid" << endl;
				cerr << "ERROR: Account Number Not Valid" << endl;
				return false;
		}
		if (root == nullptr)
		{
				root = new Node;
				root->pAcct = account;
				root->left = nullptr;
				root->right = nullptr;
				return true;
		}
		else if (root->pAcct->getAccountNum() == account->getAccountNum())
		{
				return false;
		}
		else
		{
				return insertHelper(root, account);
		}
}

bool BSTree::insertHelper(Node *node, Account *account)
{
		if (account->getAccountNum() < node->pAcct->getAccountNum())
		{
				if (node->left == nullptr)
				{
						Node *insertNode = new Node();
						insertNode->pAcct = account;
						insertNode->left = nullptr;
						insertNode->right = nullptr;
						node->left = insertNode;
						return true;
				}
				else
				{
						return insertHelper(node->left, account);
				}
		}
		else if (account->getAccountNum() > node->pAcct->getAccountNum())
		{
				if (node->right == nullptr)
				{
						Node *insertNode = new Node();
						insertNode->pAcct = account;
						insertNode->left = nullptr;
						insertNode->right = nullptr;
						node->right = insertNode;
						return true;
				}
				else
				{
						return insertHelper(node->right, account);
				}
		}
		else
		{
				cout << "ERROR: Account " << account->getAccountNum()
						<< " is already open. Transaction refused."
						<< endl;
				cerr << "ERROR: Account " << account->getAccountNum()
						<< " is already open. Transaction refused."
						<< endl;
				return false;
		}
}

bool BSTree::Retrieve(const int &accountNum, Account * &pAccount) const
{
		Account *temp = retrieveHelper(root, accountNum);
		if (temp == nullptr)
		{
				return false;
		}
		else
		{
				pAccount = temp;
				return true;
		}
}

Account * BSTree::retrieveHelper(Node *node, const int &accountNum) const
{
		if (node == nullptr)
		{
				return NULL;
		}
		else if (accountNum == node->pAcct->getAccountNum())
		{
				return (node->pAcct);
		}
		else if (accountNum < node->pAcct->getAccountNum())
		{
				return retrieveHelper(node->left, accountNum);
		}
		else
		{
				return retrieveHelper(node->right, accountNum);
		}
}

void BSTree::Display() const
{
		if (root == nullptr)
		{
				cerr << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
				cerr << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
		}
		displayHelper(root);
}

void BSTree::displayHelper(Node *node) const
{
		if (node != nullptr)
		{
				displayHelper(node->left);
				cout << *(node->pAcct) << endl;
				displayHelper(node->right);
		}
		else
		{
				return;
		}
}

void BSTree::Empty()
{
		if (root == nullptr)
		{
				cout << "Tree is Empty" << endl;
		}
		else
		{
				root = emptyHelper(root);
		}
}

BSTree::Node * BSTree::emptyHelper(Node *node)
{
		if (node != nullptr) {
				if (node->left == nullptr && node->right == nullptr)
				{
						delete node->pAcct;
						delete node;
						return nullptr;
				}
				else
				{
						node->left = emptyHelper(node->left);
						node->right = emptyHelper(node->right);
				}
		}
		return nullptr;
}

bool BSTree::isEmpty() const
{
		if (root == nullptr)
		{
				return true;
		}
		else
		{
				return false;
		}
}