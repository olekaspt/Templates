# Template

EECE2080C template Reference
Revised 20-Sep-2022

Objective: The goal of this repo is meant to show how to translate a implementation of ADT that is specific to a data type (like int), and translate it to a template.

This code is taken as starting point from https://github.com/olekaspt/Lab01

# NonTempalte Implementation
I took the files form Lab01 and renamed then.  I also renamed the classes to reflect the file names.

* Node.cpp and Node.h -> NodeNonTemplate.cpp NodeNonTempalte.h
* LinkedList.cpp and LinkedList.h -> LinkedListNonTemplate.cpp LinkedListNonTempalte.h
* tests.cpp -> testsOld.cpp  
* main.cpp -> mainOld.cpp


# Template Implementation

I took the code from Lab01 and make a couple of changes.  First I deleted the ArrayBased LinkedList.  

## Modify usage of soon to be Tempalte classes

Next change the all usages of classes to be templates.
From:
```cpp
			LinkedList linkedList = LinkedList();

```
To:
```cpp
			LinkedList<int> linkedList = LinkedList<int>();
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

We need to mark the template with template <class ItemType>, and then everywhere int was used, we replace with ItemType.   

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






