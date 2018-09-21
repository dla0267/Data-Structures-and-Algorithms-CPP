/*
 * BST.h
 *
 *  Created on: Apr 9, 2018
 *      Author: Yuun
 */

#ifndef SRC_BST_H_
#define SRC_BST_H_

#include <stack>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

template<class Key, class Value>
class BST {
private:

	class Node {
	public:
		Node(Key key) : key_(key), value_(), left_(nullptr), right_(nullptr) {}

		const Key& key() {return key_;}
		Value& value() {return value_;}
		Node*& left() {return left_;}
		Node*& right() {return right_;}

		Value& lookup(const Key& key);

	private:
		const Key key_;
		Value value_;
		Node* left_;
		Node* right_;
	};

	Node *root_;
	void dumpHelper(Node* current, int depth);
public:
	class Iterator {
	public:
		Iterator(Node* root);

		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);
		Iterator& operator++();
		const std::pair<const Key&, Value&> operator*();

	private:
		void leftmost(Node* p);
		Node* current_;
		std::stack<Node*> stack_;
	};

	Value& operator[](const Key& key);
	Iterator begin();
	Iterator end();
	void dump();

};

template<class Key, class Value>
Value& BST<Key, Value>::operator[](const Key& key) {
	if (!root_) {
		root_ = new Node(key);
		return root_->value();
	}
	return root_->lookup(key);
}


template<class Key, class Value>
Value& BST<Key, Value>::Node::lookup(const Key& key) {
	{
		if (key == key_) {
			return value_;
		}
		if (key < key_) {
			if (!left_) {
				left_ = new Node(key);
				return left_->value_;
			}
			return left_->lookup(key);
		}
		if (!right_) {
			right_ = new Node(key);
			return right_->value_;
		}
		return right_->lookup(key);
	}
}

template<class Key, class Value>
typename BST<Key, Value>::Iterator BST<Key, Value>::begin() {
	return Iterator(root_);
}

template<class Key, class Value>
typename BST<Key, Value>::Iterator BST<Key, Value>::end() {
	return Iterator(nullptr);
}


template<class Key, class Value>
BST<Key, Value>::Iterator::Iterator(BST::Node* root) {
	if (!root) {
		current_ = nullptr;
		return;
	}
	leftmost(root);
	current_ = stack_.top();
	stack_.pop();
}


template<class Key, class Value>
bool BST<Key, Value>::Iterator::operator==(const BST::Iterator& other) {
	return current_ == other.current_;
}

template<class Key, class Value>
bool BST<Key, Value>::Iterator::operator!=(const BST::Iterator& other) {
	return !(*this == other);
}


template<class Key, class Value>
typename BST<Key, Value>::Iterator& BST<Key, Value>::Iterator::operator++() {
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
const std::pair<const Key&, Value&> BST<Key, Value>::Iterator::operator*() {
	return std::pair<const Key&, Value&>(current_->key(), current_->value());
}


template<class Key, class Value>
void BST<Key, Value>::Iterator::leftmost(BST::Node *p) {
	while(p) {
		stack_.push(p);
		p = p->left();
	}
}

template<class Key, class Value>
void BST<Key, Value>::dump() {
	dumpHelper(this->root_, 0);
}

template<class Key, class Value>
void BST<Key, Value>::dumpHelper(Node* current, int depth) {
	if (current != nullptr) {
		dumpHelper(current->right(), depth + 1);
		for (int i = 0; i < depth; i++) {
			cerr << "----";
		}
		cerr << current->key() << " " << current->value()
					<< " " << endl;
		dumpHelper(current->left(), depth + 1);
	}
}

#endif /* SRC_BST_H_ */
