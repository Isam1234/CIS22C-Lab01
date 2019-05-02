// Template for the Node class

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;


template <class ItemType>
class Node
{

	friend class List <ItemType>;

private:

	ItemType data;
	Node <ItemType>* nextPtr;


public:

	Node();
	Node (const ItemType & anItem);
	Node (const ItemType &anItem, Node <ItemType>* nextPtr);
	void setItem (const ItemType & anItem);
	void setNext (Node <ItemType>* nextPtr);
	ItemType getItem() const;
	Node <ItemType>* getNext() const;
};

template <class ItemType>
Node <ItemType>::Node() :nextPtr(nullptr)
{

}

template <class ItemType>

Node <ItemType>::Node(const ItemType & anItem) : data(anItem), nextPtr(nullptr)
{

}


template <class ItemType>

Node <ItemType>::Node(const ItemType &anItem, Node <ItemType>* nextNodePtr) : data(anItem), nextPtr(nextNodePtr)
{

}


template <class ItemType>

void Node <ItemType>::setItem (const ItemType& anItem)
{
	data = anItem;
}

template <class ItemType>

void Node <ItemType>::setNext (Node <ItemType>* nextNodePtr)

{
	nextPtr = nextNodePtr;
}

template <class ItemType>

ItemType Node <ItemType> ::getItem() const

{
	return data;
}

template <class ItemType>

Node <ItemType>* Node <ItemType> ::getNext() const

{
	return nextPtr;
}

#endif

