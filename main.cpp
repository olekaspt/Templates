// LinkedListExe.cpp : Defines the entry point for the console application.
//

#include "Node.h"


// This code is just sandbox code
int main()
{

	Node<int> * head = nullptr;

	Node<int> * cur = nullptr;

	head = new Node(1);

	cur = head;

	Node<int> * temp = new Node<int>(2);

	cur->setNext(temp);

	cur = cur->getNext();

	temp = nullptr;
	temp = new Node<int>(3);

	cur->setNext(temp);

	cur = cur->getNext();

	head = nullptr;

    return 0;
}

