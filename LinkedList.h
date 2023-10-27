#pragma once

#include <string>
#include <memory>
#include "Node.h"

template <class ItemType>
class  IList {
public:

	IList();

	/** Returns true  if list is empty, otherwise false */
	virtual bool isEmpty() const ;
	/** Returns the number of elements in the LinkedList */
	virtual int getSize() const;

	/** Adds a value to the LinkedList.  Adds the value to the end of the List.  Return true if able to, otherwise false */
	virtual bool add(ItemType val) = 0;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	virtual bool remove(ItemType val) = 0;
	/** Remove  all elements from LinkedList */
	virtual void clear() = 0;
        /** Generates a string of the contents of the LinkedList, and lists them in order.  */
	virtual std::string toString() const = 0;

	

protected:
	int m_count;

};


template <class ItemType>
class LinkedList : public IList<ItemType>
{
public:
	LinkedList();
	/** Adds a value to the LinkedList. Adds the value to the end of the List. Return true if able to, otherwise false */
	bool add(ItemType val) override;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	bool remove(ItemType val)  override;
	/** Remove  all elements from LinkedList */
	void clear()  override;
	virtual ~LinkedList();
	/** Generates a string of the contents of the LinkedList, and lists them in order.  */
	std::string toString() const override;
private:
	std::shared_ptr<Node<ItemType>> m_head;
	std::shared_ptr<Node<ItemType>> m_tail;// this is optional to use, but it does make things easier
};

#include "LinkedList.txx"

