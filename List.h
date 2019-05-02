// Template for the List class

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class ItemType>
class List
{
private:
	Node <ItemType> *firstPtr;
	Node <ItemType> *lastPtr;

	int length;

	Node <ItemType> *getNewEntry (const ItemType &);
	
public:
	List(); 
	~List(); 
	bool insert(const ItemType &, const int);
	bool remove(ItemType &, const int);
	void clear();
	Node <ItemType> *getEntry(const int);
	bool setEntry(ItemType &, int);
	bool isEmpty() const;
	int getLength() const;
	void print() const;
};

// Default constructor
template <class ItemType>
List<ItemType>::List()
	: firstPtr(0), lastPtr(0), length(0)
{

}
// Deconstructor
template <class ItemType>
List <ItemType>::~List()
{
	clear();
}

template <class ItemType>
bool List <ItemType>::insert(const ItemType &value, const int pos)
{
	Node <ItemType> *newPtr = getNewEntry(value);

	if (isEmpty())
	{
		firstPtr = lastPtr = newPtr;
		length++;
		return true;
	}
	else
	{
		if (pos == 0)
		{
			newPtr->setNext(firstPtr);
			firstPtr = newPtr;
			length++;
			return true;
		}
		else if (0 < pos && pos < length - 1)						 // If the position is in the middle
		{
			Node <ItemType> *prevPtr = getEntry(pos - 1);
			Node <ItemType> *currentPtr = prevPtr->getNext();
			prevPtr->setNext(newPtr);								 // Update previous node
			newPtr->setNext(currentPtr);							// Update new node
			length++;												// Update the length counter
			return true;
		}
		else if (pos == length - 1)									// If the position is the end
		{
			lastPtr->setNext(newPtr);								// update previous last node
			lastPtr = newPtr; // new last node

			length++;												// Update the length counter
			return true;
		}
		else
			return false;											// The position is out of range
	}
} 

  // Delete node from a specified position in the list
template <class ItemType >
bool List <ItemType>::remove(ItemType &value, const int pos)
{
	if (isEmpty())
		return false;
	else
	{
		if (pos == 0)
		{
			Node<ItemType> *tempPtr = firstPtr;


			if (firstPtr == lastPtr)
				firstPtr = lastPtr = 0;

			else
				firstPtr = firstPtr->getNext();

			value = tempPtr->data;

			delete tempPtr;
			length--;

			return true;
		}

		else if (0 < pos && pos < length - 1)

		{
			Node <ItemType> *prevPtr = getEntry(pos - 1);
			Node <ItemType> *currentPtr = prevPtr->getNext();
			prevPtr->setNext(currentPtr->getNext());				// Update the previous node
			if (pos == length - 1)
				lastPtr = prevPtr;									// this is now the last node

			value = currentPtr->data;								// return data being removed
			delete currentPtr;										// reclaim the current node
			length--;												// Update the length counter
			return true;											// delete successful
		}
		else
			return false;											// position is out of range
	}
} 

  // Delete all nodes
template <typename ItemType>
void List <ItemType>::clear()
{
	if (!isEmpty())													// List is not empty
	{
		Node<ItemType> *currentPtr = firstPtr;
		Node<ItemType> *tempPtr;

		while (currentPtr != 0)										// delete remaining nodes
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->getNext();
			delete tempPtr;
		} 
	} 
}

// Return node from a specified position in the list. If out of range, return last node
template <typename ItemType>
Node <ItemType>*, List <ItemType>::getEntry(int pos)
{
	Node <ItemType> *ptr = firstPtr;
	for (int i = 0; i < pos; i++)								// Loop through list to find node
		if (ptr->getNext() != 0)
			ptr = ptr->getNext();
	return ptr;
} 

  // Replace node from a specified position in the list
template <typename ItemType>
bool List <ItemType>::setEntry(ItemType &value, int pos)
{
	Node <ItemType> *newPtr = getNewEntry(value);
	if (remove(value, pos))
	{
		insert(newPtr, pos);
		return true;
	}
	else
	{
		return false;											// position out of range
	}
}


template <typename ItemType>
bool List <ItemType>::isEmpty() const
{
	return (length == 0);
}


template <typename ItemType>
int List <ItemType>::getLength() const
{
	return length;
}

 // Return pointer to newly allocated node
template <typename ItemType>
Node <ItemType> *List <ItemType>::getNewEntry(const ItemType &value)
{
	return new Node <ItemType>(value);
}

// Display contents of List
template<typename ItemType>
void List <ItemType>::print() const
{
	if (isEmpty()) 
	{
		cout << " The list is empty\n\n";
		return;
	}

	Node <ItemType> *currentPtr = firstPtr;

	cout << " The list is: ";

	while (currentPtr != 0) 
	{
		cout << currentPtr->getItem() << ' ';
		currentPtr = currentPtr->getNext();
	}

	cout << "\n\n";
}

#endif

