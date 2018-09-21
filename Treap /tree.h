/*
 * Tree.h
 *
 *  Created on: Apr 15, 2018
 *      Author: Yuun
 */

#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include "Node.h"

#include <iostream>
#include <stack>


using namespace std;

template<class Key, class Value>
class Tree {
public:
	class Iterator {
	public:
		Iterator(Node<Key, Value>* root);
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);

		Iterator& operator++();
		const std::pair<const Key&, Value&> operator*();

	private:
		Node<Key, Value>* current_;
		void leftmost( Node<Key, Value>* p);
		std::stack<Node<Key, Value>*> stack_;
	};

	Tree();
	virtual ~Tree();

	Iterator begin();
	Iterator end();

	int& operator[](const Key& key);

	void dump();


private:
	Node<Key, Value>* root_;
};


template<class Key, class Value>
Tree<Key, Value>::Tree() : root_(nullptr) {

}

template<class Key, class Value>
Tree<Key, Value>::~Tree() {
	// TODO Auto-generated destructor stub
}

template<class Key, class Value>
typename Tree<Key, Value>::Iterator Tree<Key, Value>::begin() {
	return Iterator(root_);
}

template<class Key, class Value>
typename Tree<Key, Value>::Iterator Tree<Key, Value>::end() {
	return Iterator(nullptr);
}

template<class Key, class Value>
Tree<Key, Value>::Iterator::Iterator(Node<Key, Value>* root) {
	if (!root) {
		current_ = nullptr;
		return;
	}
	leftmost(root);
	current_ = stack_.top();
	stack_.pop();
}

template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator==(const Iterator& other) {
	return current_ == other.current_;
}


template<class Key, class Value>
bool Tree<Key, Value>::Iterator::operator!=(const Iterator& other) {
	return !(*this == other);
}

template<class Key, class Value>
typename Tree<Key, Value>::Iterator& Tree<Key, Value>::Iterator::operator++() {
	leftmost(current_->right());
	if (stack_.empty()) {
		current_ = nullptr;
		return *this;
	}
	current_ = stack_.top();
	stack_.pop();
	return *this;
}


template<class Key, class Value>
const std::pair<const Key&, Value&> Tree<Key, Value>::Iterator::operator*() {
	return std::pair<const Key&, Value&>(current_->key(), current_->value());
}


template<class Key, class Value>
void Tree<Key, Value>::Iterator::leftmost(Node<Key, Value>* p) {
	while(p) {
		stack_.push(p);
		p = p->left();
	}
}

template<class Key, class Value>
int& Tree<Key, Value>::operator [](const Key& key)
{
	if (!root_) {
		root_ = new Node<Key, Value>(key);
		return root_->value();
	}
	if (root_->lookup(key) == nullptr) {
		root_ = root_->insert(root_, key);
	}
	return root_->lookup(key)->value();
}


template<class Key, class Value>
void Tree<Key, Value>::dump() {
	root_->dump(root_, 0);
}



#endif /* SRC_TREE_H_ */
