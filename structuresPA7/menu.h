#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

#include "completeRecord.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

class menu {
private:
	completeRecord * sList;

	bool isLoaded();
	void printMenu();
	void loadClassList();
	void importFile(ifstream &classList, string type);
	void writeToMasterFile();
	void writeToFile(ofstream &outfile);
	void printRecordToFile(ofstream &output, sRecordNode *&record);
	void includeMasterList();
	void isAbsence();
	void getReport();
	void numOfAbsenceReport();
	void recentReport();

public:
	menu();
	~menu();
	void runApp();
};