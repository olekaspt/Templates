

#include "NodeNonTemplate.h"
#include <iostream>

NodeNonTemplate::NodeNonTemplate(int val) : m_value(val), m_next(nullptr)
{

}

NodeNonTemplate::NodeNonTemplate(int val, NodeNonTemplate * nextNode) : m_value(val), m_next(nextNode)
{

}

void NodeNonTemplate::setItem(const int& val)
{
	m_value = val;
}

void NodeNonTemplate::setNext(NodeNonTemplate* nextNodePtr)
{
	m_next = nextNodePtr;
}

int  NodeNonTemplate::getItem() const
{
	return m_value;
}

NodeNonTemplate * NodeNonTemplate::getNext() const
{
	return m_next;
}

NodeNonTemplate::~NodeNonTemplate()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	// you can recursively handle this which would require some code
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}