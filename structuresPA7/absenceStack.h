#include <stdbool.h>
#include <iostream>
#include "stackNode.h"


class absenceStack{
private:

	stackNode *top;

public:

	absenceStack(stackNode *aTop = nullptr);
	bool isEmpty();
	stackNode *& getTop();
	stackNode *& pop();
	stackNode *& peek();
	void push(stackNode *& aData);

};
