#include "absenceStack.h"

absenceStack::absenceStack(stackNode *aTop) {
	top = aTop;
}

stackNode *& absenceStack::getTop() {
	return top;
}

void absenceStack::push(stackNode *& aDate) {

	if (this->isEmpty()) {
		top = aDate;
	}
	else {
		stackNode *temp = top;
		top = aDate;
		top->setNext(temp);
	}
}

stackNode *& absenceStack::pop() {
	stackNode *head = this->top;
	top = top->getNext();

	head->setNextNULL();

	return head;
}

stackNode *& absenceStack::peek() {
	return this->top;
}

bool absenceStack::isEmpty() {
	if (this->top==nullptr) {
		return true;
	}
	else {
		return false;
	}
}