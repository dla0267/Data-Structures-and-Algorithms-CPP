/*
 * Node.h
 *
 *  Created on: Apr 15, 2018
 *      Author: Yuun
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_


#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

typedef string Key;
typedef int Value;

template<class Key, class Value>
class Node {
public:
	Node() : key_(), value_(), priority_(), left_(nullptr), right_(nullptr) {};
	virtual ~Node() { delete left_; delete right_;}
	Node(Key key) : key_(key), value_(), priority_(rand()), left_(nullptr), right_(nullptr){};

	const Key& key() const {return key_;}
	Value& value() {return value_;}
	int& priority() {return priority_;}
	Node<Key, Value>*& left() {return left_;};
	Node<Key, Value>*& right() {return right_;}

	Node<Key, Value>* insert(Node<Key, Value>* parent, const Key& key);
	Node<Key, Value>* lookup(const Key& key);

	void dump(Node<Key, Value>* current, int indent);

private:
	const Key key_;
	Value value_;
	int priority_;
	Node* left_;
	Node* right_;

	Node<Key, Value>* left_rotate(Node<Key, Value>* p);
	Node<Key, Value>* right_rotate(Node<Key, Value>* p);

};


template<class Key, class Value>
Node<Key, Value>* Node<Key, Value>::lookup(const Key& key) {
	if (key == key_) {
		return this;
	}
	if (key < key_) {
		if (!left_) {
			return nullptr;
		}
		return left_->lookup(key);
	}
	if (!right_) {
		return nullptr;
	}
	return right_->lookup(key);
 }


template<class Key, class Value>
Node<Key, Value>* Node<Key, Value>::insert(Node<Key, Value>* parent, const Key& key) {
	if (parent == nullptr) {
		parent = new Node(key);
		return parent;
	}
	if(key < parent->key_) {
		parent->left_ = insert(parent->left_, key);
		if (parent->left_->priority_ < parent->priority_) {
			parent = right_rotate(parent);
		}
	}
	else if (key > parent->key_) {
		parent->right_ = insert(parent->right_, key);
		if (parent->right_->priority_ < parent->priority_) {
			parent = left_rotate(parent);
		}
	}
	return parent;
}

template<class Key, class Value>
Node<Key, Value>* Node<Key, Value>::left_rotate(Node<Key, Value>* p) {
	Node* current = p->right_;
	Node* leftGrandChild = p->right_->left_;
	p->right_ = leftGrandChild;
	current->left_ = p;
	return current;
}


template<class Key, class Value>
Node<Key, Value>* Node<Key, Value>::right_rotate(Node<Key, Value>* p) {
	Node* current = p->left_;
	Node* grandChild = p->left_->right_;
	p->left_ = grandChild;
	current->right_ = p;
	return current;
}


template<class Key, class Value>
void Node<Key, Value>::dump(Node<Key, Value>* current, int indent)  {
    if (current != nullptr) {
    	dump(current->right(), indent + 1);
        for (int i = 0; i < indent; i++) {
            cerr << "\t";
        }
        cerr << current->key() << " " << current->value() << " " <<
                  current->priority() << endl;
        dump(current->left(), indent + 1);
    }
}


#endif /* SRC_NODE_H_ */



