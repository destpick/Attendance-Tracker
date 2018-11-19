#include "stackNode.h"

stackNode::stackNode(stackNode * aNode) {
	date.setDate("");
	nextNode = nullptr;
}

stackNode:: ~stackNode() {
}

absence & stackNode::getData() {
	return this->date;
}

void stackNode::setData(string aDate) {
	static absence aAbsence;
	aAbsence.setDate(aDate);
	this->date = aDate;
}

stackNode *& stackNode::getNext() {
	return this->nextNode;
}

void stackNode::setNext(stackNode *&aNode) {
	nextNode = aNode;
}

void stackNode::setNextNULL() {
	this->nextNode = nullptr;
}
