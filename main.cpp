// LinkedListExe.cpp : Defines the entry point for the console application.
//

#include "Node.h"


// This code is just sandbox code
int main()
{

	std::shared_ptr<Node<int>>  head = nullptr;

	std::shared_ptr<Node<int>> cur = nullptr;

	head = std::make_shared<Node<int>>(1);

	cur = head;

	std::shared_ptr<Node<int>> temp = std::make_shared<Node<int>>(2);

	cur->setNext(temp);

	cur = cur->getNext();

	temp = nullptr;
	temp = std::make_shared<Node<int>>(3);

	cur->setNext(temp);

	cur = cur->getNext();

	head = nullptr;

    return 0;
}

