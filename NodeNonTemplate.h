#pragma once

class NodeNonTemplate
{
private:
	int m_value;
	NodeNonTemplate * m_next;

public:
	NodeNonTemplate() = delete;
	NodeNonTemplate(int val);
	NodeNonTemplate(int val, NodeNonTemplate * nextNode);
	void setItem(const int& val);
	void setNext(NodeNonTemplate* nextNodePtr);
	int getItem() const;
	NodeNonTemplate * getNext() const;
	virtual ~NodeNonTemplate();
	
};
