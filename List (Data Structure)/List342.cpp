#include "stdafx.h"
//#include "List342.h"
//
//#include <string>
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//template <class ItemType>
//List342<ItemType>::List342()
//{
//	headPtr = nullptr;
//}
//
//template <class ItemType>
//List342<ItemType>::List342(const List342<ItemType> &sourceList)
//{
//	headPtr = nullptr;
//	*this = sourceList;
//}
//
//template <class ItemType>
//List342<ItemType>::~List342()
//{
//	DeleteList();
//}
//
//
//template <class ItemType>
//bool List342<ItemType>::BuildList(string fileName)
//{
//	ifstream inFile;
//	inFile.open(fileName);
//	if (!inFile)
//	{
//		cout << "Unable to open the file" << endl;
//		return false;
//	}
//	ItemType item;
//	while (inFile.eof())
//	{
//		inFile >> item;
//		Insert(&item);
//	}
//	inFile.close();
//	return true;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Insert(ItemType *obj)
//{
//	if (obj == nullptr)
//	{
//		return false;
//	}
//	if (Peek(*obj, *obj))
//	{
//		return false;
//	}
//	Node *insertNode = new Node;
//	ItemType *insertData;
//	insertData = new ItemType;
//	*insertData = *obj;
//	insertNode->data = insertData;
//	if (headPtr == nullptr)
//	{
//		headPtr = insertNode;
//		return true;
//	}
//	else if (*(insertNode->data) < *(headPtr->data))
//	{
//		insertNode->next = headPtr;
//		headPtr = insertNode;
//		return true;
//	}
//	else
//	{
//		Node *trackingPtr;
//		trackingPtr = headPtr;
//		while ((trackingPtr->next != nullptr) &&
//			(*(insertNode->data) > *(trackingPtr->next->data))) {
//			trackingPtr = trackingPtr->next;
//		}
//		insertNode->next = trackingPtr->next;
//		trackingPtr->next = insertNode;
//	}
//	return true;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType &result) {
//	if (headPtr == nullptr)
//	{
//		return false;
//	}
//	Node *currentPtr;
//	currentPtr = headPtr;
//	if (*(headPtr->data) == target)
//	{
//		headPtr = headPtr->next;
//		result = *(currentPtr->data);
//		delete currentPtr->data;
//		currentPtr->data = nullptr;
//		currentPtr->next = nullptr;
//		delete currentPtr;
//		currentPtr = nullptr;
//		return true;
//	}
//	currentPtr = headPtr;
//	Node *trackingPtr;
//	while (currentPtr->next != nullptr && *(currentPtr->next->data) < target) {
//		currentPtr = currentPtr->next;
//	}
//	if (currentPtr->next == nullptr)
//	{
//		return false;
//	}
//	else
//	{
//		trackingPtr = currentPtr->next;
//		result = *(trackingPtr->data);
//		currentPtr->next = currentPtr->next->next;
//		delete trackingPtr->data;  	// deleting the data pointer's stored values
//		trackingPtr->data = nullptr;   // assigning data pointer to nullptr;
//		delete trackingPtr; 			// deleting the tracking ptr's value;  
//		trackingPtr = nullptr;		// tracking ptr to null ptr;
//		return true;
//	}
//}
//
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType &result) const
//{
//	if (headPtr == nullptr)
//	{
//		return false;
//	}
//	Node *currentPtr;
//	currentPtr = headPtr;
//	while (currentPtr != nullptr)
//	{
//		if (*(currentPtr->data) == target) {
//			result = *(currentPtr->data);
//			return true;
//		}
//		else
//		{
//			currentPtr = currentPtr->next;
//		}
//	}
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::isEmpty() const {
//	return (headPtr == nullptr);
//}
//
//template <class ItemType>
//void List342<ItemType>::DeleteList()
//{
//	Node *temp;
//	while (headPtr != nullptr)
//	{
//		temp = headPtr;
//		headPtr = headPtr->next;
//		delete temp->data;
//		delete temp;
//	}
//	headPtr = nullptr;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Merge(List342<ItemType> &list1) {
//	if (this == &list1 || list1.headPtr == nullptr)
//	{
//		return false;
//	}
//	if (headPtr == nullptr)
//	{
//		headPtr = list1.headPtr;
//		list1.headPtr = nullptr;
//		return true;
//	}
//	Node *trackingNode2;
//	trackingNode2 = list1.headPtr;
//	if ((*headPtr->data) >= *(trackingNode2->data))
//	{
//		list1.headPtr = list1.headPtr->next;
//		if (*headPtr->data == *(trackingNode2->data))
//		{
//			delete (trackingNode2->data);
//			delete trackingNode2;
//		}
//		else
//		{
//			trackingNode2->next = headPtr;
//			headPtr = trackingNode2;
//		}
//	}
//	Node *trackingNode;
//	trackingNode = headPtr;
//	while (list1.headPtr != nullptr)
//	{
//		if (trackingNode->next != nullptr)
//		{
//			trackingNode2 = list1.headPtr;
//			if (*(trackingNode2->data) < *(trackingNode->next->data))
//			{
//				list1.headPtr = list1.headPtr->next;
//				trackingNode2->next = trackingNode->next;
//				trackingNode->next = trackingNode2;
//				trackingNode = trackingNode2;
//				trackingNode2 = nullptr;
//			}
//			else if (*(trackingNode2->data) == *(trackingNode->next->data))
//			{
//				list1.headPtr = list1.headPtr->next;
//				delete trackingNode2->data;
//				delete trackingNode2;
//				trackingNode2 = nullptr;
//			}
//			else
//			{
//				trackingNode = trackingNode->next;
//			}
//		}
//		else
//		{
//			trackingNode->next = trackingNode2;
//			list1.headPtr = nullptr;
//			return true;
//		}
//	}
//	return true;
//}
//
//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator+(const List342<ItemType> &list2) const
//{
//	List342<ItemType> tempList;
//	tempList = *this;
//	tempList += list2;
//	return tempList;
//}
//
//template <class ItemType>
//List342<ItemType>& List342<ItemType>::operator+=(const List342<ItemType> &list2)
//{
//	if (list2.headPtr == nullptr)
//	{
//		return *this;
//	}
//	if (headPtr == nullptr)
//	{
//		*this = list2;
//		return *this;
//	}
//	Node *insertNode = list2.headPtr;
//	while (insertNode != nullptr)
//	{
//		Insert(insertNode->data);
//		insertNode = insertNode->next;
//	}
//	return *this;
//}
//
//template <class ItemType>
//bool List342<ItemType>::operator==(const List342<ItemType> &list2) const
//{
//	if (((headPtr == nullptr) && (list2.headPtr != nullptr)) ||
//		((headPtr != nullptr) && (list2.headPtr == nullptr)))
//	{
//		return false;
//	}
//	Node *tracker1, *tracker2;
//	tracker1 = headPtr;
//	tracker2 = list2.headPtr;
//	while (tracker1 != nullptr && tracker2 != nullptr)
//	{
//		if (*(tracker1->data) == *(tracker2->data))
//		{
//			tracker1 = tracker1->next;
//			tracker2 = tracker2->next;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	if (tracker1 == nullptr && tracker2 == nullptr ||
//		(tracker1 != nullptr && tracker2 != nullptr))
//	{
//		return true;
//	}
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::operator!=(const List342<ItemType> &list2) const
//{
//	return !(*this == list2);
//}
//
//template <class ItemType>
//List342<ItemType>& List342<ItemType>::operator=(const List342<ItemType> &list2)
//{
//	if (this == &list2)
//	{
//		return *this;
//	}
//	DeleteList();
//	if (list2.isEmpty())
//	{
//		return *this;
//	}
//	Node *assignedNode = new Node;
//	ItemType *assignedItem = new ItemType;
//	*assignedItem = *(list2.headPtr->data);
//	assignedNode->data = assignedItem;
//	assignedNode->next = nullptr;   // necessary or not
//	headPtr = assignedNode;
//	Node *tracker, *current;
//	tracker = headPtr;
//	current = list2.headPtr->next;
//	while (current != nullptr)
//	{
//		assignedNode = new Node;
//		assignedItem = new ItemType;
//		*(assignedItem) = *(current->data);
//		assignedNode->data = assignedItem;
//		assignedNode->next = nullptr;   // not sure abou this
//		tracker->next = assignedNode;
//		tracker = tracker->next;
//		current = current->next;
//	}
//	return *this;
//}
//
//template <class ItemType>
//ostream& operator<<(ostream& outStream, const List342<ItemType> &list2)
//{
//	if (list2.isEmpty())
//	{
//		outStream << "List is Empty" << endl;
//		return outStream;
//	}
//	List342<ItemType>::Node *currentPtr;
//	currentPtr = list2.headPtr;
//	while (currentPtr != nullptr)
//	{
//		outStream << *(currentPtr->data);
//		currentPtr = currentPtr->next;
//	}
//	return outStream;
//}