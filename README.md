# Template

EECE2080C template Reference
Revised 20-Sep-2022

Objective: The goal of this repo is meant to show how to translate a implementation of ADT that is specific to a data type (like int), and translate it to a template.

This code is taken as starting point from https://github.com/olekaspt/Lab01

# NonTemplate Implementation
I took the files form Lab01 and renamed then.  I also renamed the classes to reflect the file names.

* Node.cpp and Node.h -> NodeNonTemplate.cpp NodeNonTemplate.h
* LinkedList.cpp and LinkedList.h -> LinkedListNonTemplate.cpp LinkedListNonTemplate.h
* tests.cpp -> testsOld.cpp  
* main.cpp -> mainOld.cpp


# Template Implementation

I took the code from Lab01 and make a couple of changes.  First I deleted the ArrayBased LinkedList.  

## Modify usage of soon to be Template classes

Next change the all usages of classes to be templates.
From:
```cpp
LinkedList linkedList = LinkedList();

	OR

Node * node1 = new Node(1);

```
To:
```cpp
LinkedList<int> linkedList = LinkedList<int>();

	OR
std::shared_ptr<Node<int>> node1 = std::make_shared<Node<int>>(1);
```
Additionally the signature of the type passed into the generic testcases needs to be chagned.
```cpp
    void TestEmpty(IList& list)
```
To:
```cpp
    void TestEmpty(IList<int>& list)
```

## Rename files and adjust includes
Change cpp files to be txx, to indicate that is not cpp file and meant to be compiled

* Node.cpp  -> Node.txx
* LinkedList.cpp -> LinkedList.txx

Modify CMakeLisst.txt

Take out this line and all references to applibrary.  As Templates are generated on demaned and compiled as needed.
```
add_library (applibrary SHARED Nodee.cpp LinkedList.cpp )
```

Now take out header file include in txx (which used to cpp).

Now add to the bottom of the header file include the appropiate txx file.  For example in Node.h
```cpp
    #include "Node.txx"
```

## Adjust Header files
Below is what to change to Node.h

We need to mark the class with template <class ItemType>, and then everywhere int was used, we replace with ItemType.   We are also
using smart pointers so adding those instead of dumb pointers.

```cpp
#pragma once
#include <memory>

template <class ItemType>
class Node
{
private:
	ItemType m_value;
	std::shared_ptr<Node<ItemType>> m_next;

public:
	Node() = delete;
	Node(ItemType val);
	Node(ItemType val, std::shared_ptr<Node<ItemType>> nextNode);
	void setItem(const ItemType& val);
	void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
	ItemType getItem() const;
	std::shared_ptr<Node<ItemType>> getNext() const;
	virtual ~Node();
	
};

#include "Node.txx"
```

And then in the txx file, you need to change the implementation from:

```cpp
Node::Node(ItemType val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
```

To:
```cpp
template <class ItemType>
Node<ItemType>::Node(ItemType val, std::shared_ptr<Node<ItemType>> nextNode) : m_value(val), m_next(nextNode)
{

}
```

For the LinkedList we will do the same as well.  With some additional points

Any inherited classes needs to also include the template.  So in this case 

From :
```cpp
class LinkedList : public IList
{
```
To :
```cpp
template <class ItemType>
class LinkedList : public IList<ItemType>
{
```

And in the txx file
From :
```cpp
LinkedList::LinkedList() : IList(), m_head(nullptr), m_tail(nullptr)
{

}
```
To :
```cpp
template <class ItemType>
LinkedList<ItemType>::LinkedList() : IList<ItemType>(), m_head(nullptr), m_tail(nullptr)
{

}
```

But the rest of the changes shoudl be similiar as we did Node.h and Node.txx

