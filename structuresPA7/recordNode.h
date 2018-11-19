#include <string>
#include<sstream>
#include "absenceStack.h"

using std::string;
using std::istringstream;

class sRecordNode {
	class fullName {
	public:
		string lastName;
		string firstName;
		fullName(string lastNameS = "", string firstNameS = "") {
			lastName = lastNameS;
			firstName = firstNameS;
		}
	};

public:
	sRecordNode(int rNumT = 0, int iNumT = 0, string emailT = "", string credzT = "", string programT = "", string levelT = "", sRecordNode *next = nullptr, string numofabs = "0", absenceStack*topT = nullptr);

	int getRecordNum();
	void setRecordNum(int aRecordNum);

	int getIDNum();
	void setIDNum(int aID);

	string getFirstName();
	string getLastName();
	void setName(string firstName, string lastName);

	string getEmail();
	void setEmail(string aEmail);

	string getUnits();
	void setUnits(string aCred);

	string getProgram();
	void setProgram(string aProgram);

	string getLevel();
	void setLevel(string aLevel);

	sRecordNode * getNext()const;
	void setNext(sRecordNode *& aRecord);

	string getAbsenceList();
	void setAbsenceList(string aDate);

	absenceStack *& getStack();

	void processList(string aDate);

private:
	int recordNumber;
	int idNumber;
	fullName studentName;
	string email;
	string units;
	string program;
	string level;
	sRecordNode * nextrecord;

	string numOfAbsences;
	absenceStack *sTop;
};
