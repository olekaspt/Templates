// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedListNonTemplate.h"
#include <iostream>

using namespace std;

IListNonTemplate::IListNonTemplate() : m_count(0)
{

}


int IListNonTemplate::getSize() const
{
	return m_count;
	
}


bool IListNonTemplate::isEmpty() const
{
	//TODO - hint use m_count


	return false;
	
}



LinkedListNonTemplate::LinkedListNonTemplate() : IListNonTemplate(), m_head(nullptr), m_tail(nullptr)
{

}


bool LinkedListNonTemplate::add(int val)
{
	return false;
	//TODO
}

bool LinkedListNonTemplate::remove(int val)
{
	//TODO
	return false;
}


void LinkedListNonTemplate::clear()
{
	delete m_head;

	//TODO - 
	// dangling pointer warning
	// what other private data members should be adjusted?
}
LinkedListNonTemplate::~LinkedListNonTemplate()
{
	clear();
	
}

std::string LinkedListNonTemplate::toString() const
{
	string str = "";


    //TODO
	return str;
}

