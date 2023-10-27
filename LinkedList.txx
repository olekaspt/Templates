// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


template <class ItemType>
IList<ItemType>::IList() : m_count(0)
{

}

template <class ItemType>
int IList<ItemType>::getSize() const
{
	return m_count;
	
}

template <class ItemType>
bool IList<ItemType>::isEmpty() const
{
	//TODO - hint use m_count


	return false;
	
}


template <class ItemType>
LinkedList<ItemType>::LinkedList() : IList<ItemType>(), m_head(nullptr), m_tail(nullptr)
{

}


template <class ItemType>
bool LinkedList<ItemType>::add(ItemType val)
{
	return false;
	//TODO
}

template <class ItemType>
bool LinkedList<ItemType>::remove(ItemType val)
{
	//TODO
	return false;
}

template <class ItemType>
void LinkedList<ItemType>::clear()
{
	m_head = nullptr;

	//TODO - 
	// dangling pointer warning
	// what other private data members should be adjusted?
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
	
}

template <class ItemType>
std::string LinkedList<ItemType>::toString() const
{
	string str = "";


    //TODO
	return str;
}
