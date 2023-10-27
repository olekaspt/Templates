// LinkedListExe.cpp : Defines the entry point for the console application.
//
#include "NodeNonTemplate.h"



// This code is just sandbox code
int main()
{

	NodeNonTemplate * head = nullptr;

	NodeNonTemplate * cur = nullptr;

	head = new NodeNonTemplate(1);

	cur = head;

	NodeNonTemplate * temp = new NodeNonTemplate(2);

	cur->setNext(temp);

	cur = cur->getNext();

	temp = nullptr;
	temp = new NodeNonTemplate(3);

	cur->setNext(temp);

	cur = cur->getNext();

	delete head;


    return 0;
}

