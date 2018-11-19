#include <iostream>
#include <string>

#include "recordNode.h"


using std::string;
using std::cout;
using std::endl;

class completeRecord {
private:
	sRecordNode *head;
	void setValue(sRecordNode *&aNode, int aRecordNum, int aIDNum, string aLastName, string aFirstName, string aEmail, string aUnit, string aProgram, string aLevel);

public:
	completeRecord(sRecordNode *head = nullptr);
	void addRecord(int aRecordNum, int aIDNum, string aLastName, string aFirstName, string aEmail, string aUnit, string aProgram, string aLevel, string anAbs= "", string anAbsList="");
	sRecordNode *&getHead(); 
	void setHead(sRecordNode *& aNode);

};