///*
// * Tree.cpp
// *
// *  Created on: Apr 15, 2018
// *      Author: Yuun
// */
//
//#include "Tree.h"
//
//template<class Key, class Value>
//Tree<Key, Value>::Tree() : root_(nullptr) {
//
//}
//
//template<class Key, class Value>
//Tree<Key, Value>::~Tree() {
//	// TODO Auto-generated destructor stub
//}
//
//template<class Key, class Value>
//typename Tree<Key, Value>::Iterator Tree<Key, Value>::begin() {
//	return Iterator(root_);
//}
//
//template<class Key, class Value>
//typename Tree<Key, Value>::Iterator Tree<Key, Value>::end() {
//	return Iterator(nullptr);
//}
//
//template<class Key, class Value>
//Tree<Key, Value>::Iterator::Iterator(Node* root) {
//	if (!root) {
//		current_ = nullptr;
//		return;
//	}
//	leftmost(root);
//	current_ = stack_.top();
//	stack_.pop();
//}
//
//template<class Key, class Value>
//bool Tree<Key, Value>::Iterator::operator==(const Iterator& other) {
//	return current_ == other.current_;
//}
//
//
//template<class Key, class Value>
//bool Tree<Key, Value>::Iterator::operator!=(const Iterator& other) {
//	return !(*this == other);
//}
//
//template<class Key, class Value>
//typename Tree<Key, Value>::Iterator& Tree<Key, Value>::Iterator::operator++() {
//	leftmost(current_->right());
//	if (stack_.empty()) {
//		current_ = nullptr;
//		return *this;
//	}
//	current_ = stack_.top();
//	stack_.pop();
//	return *this;
//}
//
//
//template<class Key, class Value>
//const std::pair<const Key&, Value&> Tree<Key, Value>::Iterator::operator*() {
//	return std::pair<const Key&, Value&>(current_->key(), current_->value());
//}
//
//
//template<class Key, class Value>
//void Tree<Key, Value>::Iterator::leftmost(Node<Key, Value>* p) {
//	while(p) {
//		stack_.push(p);
//		p = p->left();
//	}
//}
//
//template<class Key, class Value>
//int& Tree<Key, Value>::operator [](const Key& key)
//{
//	if (!root_) {
//		root_ = new Node(key);
//		return root_->value();
//	}
//	if (root_->lookup2(key) == nullptr) {
//		root_ = root_->lookup(root_, key);
//	}
//	return root_->lookup2(key)->value();
//}
//
//
//
//template<class Key, class Value>
//void Tree<Key, Value>::dump(int depth) {
//	if (root_) {
//		root_->dump(0);
//	}
//}
//
//
//template<class Key, class Value>
//void Tree<Key, Value>::walk() {
//	if (root_) {
//		root_->walk();
//	}
//}
//
//
