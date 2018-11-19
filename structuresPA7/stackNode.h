#pragma once
#include <stdio.h>
#include <iostream>
#include "absence.h"

class stackNode {
	
private:
	absence date;
	stackNode *nextNode;

public:
	stackNode( stackNode *next = nullptr);
	~stackNode();
	absence & getData();
	void setData(string date);
	stackNode *&getNext();
	void setNext(stackNode *& aNode);
	void setNextNULL();
};