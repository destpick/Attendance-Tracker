#include "completeRecord.h"

completeRecord::completeRecord(sRecordNode *aNode) {
	head = aNode;
}

void completeRecord::addRecord(int aRecordNum, int aIDNum, string aLastName, string aFirstName, string aEmail, string aUnit, string aProgram, string aLevel, string anAbs, string anAbsList) {
	
	sRecordNode *student = new sRecordNode();
	
	this->setValue(student, aRecordNum, aIDNum, aLastName, aFirstName, aEmail, aUnit, aProgram, aLevel);
	
	if (anAbs != "") {
		student->setAbsenceList(anAbs);
		student->processList(anAbsList);
	}
	if (head == nullptr) {
		this->setHead(student);
	}
	else {
		student->setNext(head);
		this->setHead(student);
	}
}

sRecordNode *& completeRecord::getHead() {
	return this->head;
}

void completeRecord::setHead(sRecordNode *&aNode) {
	head = aNode;
}

void completeRecord::setValue(sRecordNode *& student, int aRecordNum, int aIDNum, string aLastName, string aFirstName, string aEmail, string aUnit, string aProgram, string aLevel) {
	student->setRecordNum(aRecordNum);
	student->setIDNum(aIDNum);
	student->setName(aFirstName, aLastName);
	student->setEmail(aEmail);
	student->setUnits(aUnit);
	student->setProgram(aProgram);
	student->setLevel(aLevel);
}