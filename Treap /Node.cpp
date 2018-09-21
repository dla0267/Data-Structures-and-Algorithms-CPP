///*
// * Node.cpp
// *
// *  Created on: Apr 15, 2018
// *      Author: Yuun
// */
//
//#include "Node.h"
//
//template<class Key, class Value>
//Node<Key, Value>* Node<Key, Value>::lookup2(const Key& key) {
//	if (key == key_) {
//		return this;
//	}
//	if (key < key_) {
//		if (!left_) {
//			return nullptr;
//		}
//		return left_->lookup2(key);
//	}
//	if (!right_) {
//		return nullptr;
//	}
//	return right_->lookup2(key);
// }
//
//
//template<class Key, class Value>
//Node<Key, Value>* Node<Key, Value>::lookup(Node<Key, Value>* parent, const Key& key) {
//	if (parent == nullptr) {
//		parent = new Node(key);
//		return parent;
//	}
//	if(key < parent->key_) {
//		parent->left_ = lookup(parent->left_, key);
//		if (parent->left_->priority_ < parent->priority_) {
//			parent = right_rotate(parent);
//		}
//	}
//	else if (key > parent->key_) {
//		parent->right_ = lookup(parent->right_, key);
//		if (parent->right_->priority_ < parent->priority_) {
//			parent = left_rotate(parent);
//		}
//	}
//	return parent;
//}
//
//template<class Key, class Value>
//Node<Key, Value>* Node<Key, Value>::left_rotate(Node<Key, Value>* p) {
//	Node* current = p->right_;
//	Node* leftGrandChild = p->right_->left_;
//	p->right_ = leftGrandChild;
//	current->left_ = p;
//	return current;
//}
//
//
//template<class Key, class Value>
//Node<Key, Value>* Node<Key, Value>::right_rotate(Node<Key, Value>* p) {
//	Node* current = p->left_;
//	Node* grandChild = p->left_->right_;
//	p->left_ = grandChild;
//	current->right_ = p;
//	return current;
//}
//
//
//template<class Key, class Value>
//void Node<Key, Value>::dump(int indent)  {
//	if (right_) {right_->dump(indent + 1);}
//
//	for (int i = 0 ; i < indent; i ++) {
//		cerr << "====";
//	}
//	cerr << " key(" << key_ << ")," << " value(" << value_ << ")," << " left(" << left_ << ")," << " right(" << right_ << ")" << " priority(" << priority_ << ")"
//			<< endl;
//	if (left_) {left_->dump(indent + 1);}
//
//}
//
//
//template<class Key, class Value>
//void Node<Key, Value>::walk() {
//	if (right_) {
//		cout << "====";
//		right_->walk();}
//	cout << value_ << "\t" << key_ << "\t" << priority_ << endl;
//	if (left_) {
//		cout << "====";
//		left_->walk();}
//}
//
