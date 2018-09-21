///*
// * BST.cpp
// *
// *  Created on: Apr 9, 2018
// *      Author: Yuun
// */
//
//#include "BST.h"
//
//using namespace std;
//
//template<class Key, class Value>
//typename BST<Key, Value>::Iterator BST<Key, Value>::begin() {
//	return Iterator(root_);
//}
//
//template<class Key, class Value>
//typename BST<Key, Value>::Iterator BST<Key, Value>::end() { return Iterator(nullptr);}
//
//
//template<class Key, class Value>
//BST<Key, Value>::Iterator::Iterator(BST::Node* root) {
//	if (!root) {
//		current_ = nullptr;
//		return;
//	}
//	leftmost(root);
//	current_ = stack_.top();
//	stack_.pop();
//}
//
//
//template<class Key, class Value>
//bool BST<Key, Value>::Iterator::operator==(const BST::Iterator& other) {
//	return current_ == other.current_;
//}
//
//template<class Key, class Value>
//bool BST<Key, Value>::Iterator::operator!=(const BST::Iterator& other) {
//	return !(*this == other);
//}
//
//
//template<class Key, class Value>
//typename BST<Key, Value>::Iterator& BST<Key, Value>::Iterator::operator++() {
//	if (current_ == nullptr && !stack_.empty()) {
//		current_ = stack_.top();
//		stack_.pop();
//		leftmost(current_->right());
//		return *this;
//	}
//}
//
//
//template<class Key, class Value>
//std::pair<const Key&, Value&> BST<Key, Value>::Iterator::operator*() {
//	return pair<const Key&, Value&>(current_->key(), current_->value());
//}
//
//
//template<class Key, class Value>
//void BST<Key, Value>::Iterator::leftmost(BST::Node *p) {
//	while(p) {
//		stack_.push(p);
//		p = p->left();
//	}
//}
//
//
//template<class Key, class Value>
//void BST<Key, Value>::Iterator::rightmost(BST::Node* p) {
//	while(p) {
//		stack_.push(p);
//		p = p->right();
//	}
//}
