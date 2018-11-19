#include "recordNode.h"

sRecordNode::sRecordNode(int rNumT, int iNumT, string emailT, string credzT, string programT, string levelT, sRecordNode *next, string numofabs, absenceStack*topT) {
	recordNumber = rNumT;
	idNumber = iNumT;
	email = emailT;
	units = credzT;
	program = programT;
	level = levelT;
	nextrecord = next;
	numOfAbsences = numofabs;
	this->sTop = new absenceStack;
}


int sRecordNode::getRecordNum() {
	return recordNumber;
}

void sRecordNode::setRecordNum(int aRec) {
	recordNumber = aRec;
}

int sRecordNode::getIDNum() {
	return idNumber;
}

void sRecordNode::setIDNum(int aRec) {
	idNumber = aRec;
}

string sRecordNode::getFirstName() {
	return studentName.firstName;
}

string sRecordNode::getLastName() {
	return studentName.lastName;
}

void sRecordNode::setName(string aFirstName, string aLastName) {
	this->studentName.firstName = aFirstName;
	this->studentName.lastName = aLastName;
}

string sRecordNode::getEmail() {
	return email;
}

void sRecordNode::setEmail(string aEmail) {
	email = aEmail;
}

string sRecordNode::getUnits() {
	return units;
}

void sRecordNode::setUnits(string aUnit) {
	units = aUnit;
}

string sRecordNode::getProgram() {
	return program;
}

void sRecordNode::setProgram(string aProgram) {
	program = aProgram;
}

string sRecordNode::getLevel() {
	return level;
}

void sRecordNode::setLevel(string aLevel) {
	level = aLevel;
}

sRecordNode * sRecordNode::getNext()const {
	return nextrecord;
}

void sRecordNode::setNext(sRecordNode *& aNode) {
	nextrecord = aNode;
}

absenceStack *& sRecordNode::getStack() {
	return this->sTop;
}

string sRecordNode::getAbsenceList() {
	return this->numOfAbsences;
}

void sRecordNode::setAbsenceList(string aAbs) {
	this->numOfAbsences = aAbs;
}

void sRecordNode::processList(string aDate) {
	istringstream absence(aDate);
	string fulldate = "";
	string lastDate = "";

	do {
		lastDate = fulldate;
		getline(absence, fulldate, ',');
		if (fulldate != lastDate) {
			stackNode *temp = new stackNode;
			temp->setData(fulldate);
			this->getStack()->push(temp);
		}
	} while (fulldate != lastDate);
}