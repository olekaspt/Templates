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
