#include "menu.h"

std::ostringstream;


menu::menu() {
	this->sList = new completeRecord();
}

menu::~menu() {

}

void menu::loadClassList() {
	ifstream list;
	list.open("classList.csv");
	if (list.is_open()) {
		importFile(list, "class");
		list.close();
		cout << "completed" << endl;
	}
	else {
		cout << "Error! Could not open file!" << endl;
	}
}

bool menu::isLoaded() {
	if (this->sList != nullptr) {
		return false;
	}
	////system("cls");
	cout << "Error! File has already been loaded!" << endl;
	////system("pause");
	return true;
}

void menu::importFile(ifstream &classList, string type) {
	string line = "";
	int rNum = 0;
	int iNum = 0;
	string lastNameF = "";
	string firstNameF = "";
	string emailF = "";
	string credzF = "";
	string programF = "";
	string levelF = "";
	string nLine = "";

	getline(classList, line);
	while (!classList.eof()) {
		getline(classList, line);
		classList >> rNum;
		classList.ignore(1, ',');

		classList >> iNum;
		classList.ignore(1, ',');
		classList.ignore(1, '\"');

		getline(classList, lastNameF, ',');
		getline(classList, firstNameF, '\"');
		classList.ignore(1, ',');

		getline(classList, emailF, ',');
		getline(classList, credzF, ',');
		getline(classList, programF, ',');
		if (type == "class") {
			getline(classList, levelF, '\n');
			this->sList->addRecord(rNum, iNum, lastNameF, firstNameF, emailF, credzF, programF, levelF);

		}
		else {
			getline(classList, levelF, ',');
			string numOfAbsencesF;
			getline(classList, numOfAbsencesF, '*');
			string listOfAbsences;
			getline(classList, nLine, '\n');
	
			if (numOfAbsencesF != "0") {
				getline(classList, listOfAbsences);
				listOfAbsences.pop_back();
			}
			else {
				getline(classList, line);
			}
			this->sList->addRecord(rNum, iNum, lastNameF, firstNameF, emailF, credzF, programF, levelF);
		}
	}
}

void menu::writeToMasterFile() {
	if (this->sList->getHead() != nullptr) {
		ofstream output("master.txt");
		if (output.is_open()) {
			writeToFile(output);
			output.close();
			//system("cls");
			cout << "Successful!" << endl;
			//system("pause");
		}
		else {

			//system("cls");
			cout << "Error! Could not open file!" << endl;
			//system("pause");
		}
	}
	else {
		//system("cls");
		cout << "Error! Could not find class list!" << endl;
		//system("cls");
	}
}

void menu::writeToFile(ofstream &output) {
	output << "Record Number: , ID: , Name: , Email: , Units: , Program: , Level: , Number of Absences: ,";
	sRecordNode *student = this->sList->getHead();

	while (student != nullptr) {
		printRecordToFile(output, student);
		student = student->getNext();
	}
}

void menu::printRecordToFile(ofstream &output, sRecordNode *&record) {
	output << "\n" << record->getRecordNum() << "," << record->getIDNum() << "," << record->getLastName() << ",\"" << record->getFirstName() << "\"," << record->getEmail() << "," << record->getUnits() << "," << record->getProgram() << "," << record->getLevel() << "," << record->getAbsenceList() << "*";

	if (record->getAbsenceList() != "0") {
		absenceStack *tempS = new absenceStack;
		stackNode *tempN;

		while (record->getStack()->isEmpty() == false) {
			tempN = tempS->pop();
			absence tempA = tempN->getData();

			output << tempA.getDate();

			record->getStack()->push(tempN);

			if (tempS->isEmpty() == false) {
				output << ",";
			}
			else {
				output << "*";
			}
		}
	}
}

void menu::includeMasterList() {
	ifstream masterList;
	masterList.open("master.txt");

	if (masterList.is_open()) {
		importFile(masterList, "master");
		masterList.close();

		//system("cls");
		cout << "Succesful" << endl;
		//system("pause");

	}
	else {
		//system("cls");
		cout << "Error! Could not find file." << endl;
		//system("pause");
	}
}

void menu::isAbsence() {
	char choice = 0;
	time_t t = time(0);
	struct tm*now = localtime(&t);

	string date = "";
	std::ostringstream zone;
	zone << (now->tm_mon + 1) << "/" << (now->tm_mday) << "/" << (now->tm_year + 1900);
	date = zone.str();

	sRecordNode * student = this->sList->getHead();

	while (student != nullptr) {
		do {
			//system("cls");
			cout << "Is " << student->getFirstName() << " " << student->getLastName() << " present today? (Y or N)" << endl;

			cin >> choice;

			if (choice == 'n' || choice == 'N') {
				if (student->getStack()->getTop() == nullptr || student->getStack()->peek()->getData().getDate() != date) {
					stackNode *temp = new stackNode();
					temp->setData(date);
					student->getStack()->push(temp);
					int wasAbsence = std::stoi(student->getAbsenceList()) + 1;
					student->setAbsenceList(std::to_string(wasAbsence));
				}
			}
		} while (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n');
		student = student->getNext();
	}
	//system("cls");
	cout << "Completed!" << endl;
	//system("cls");

}

void menu::getReport() {
	int choice = 0;
	do {
		//system("cls");
		cout << "Which type of report would you like to generate!" << endl;
		cout << "(1) Most recent:" << endl;
		cout << "(2) Absences based on number" << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		this->recentReport();
		break;
	case 2:
		this->numOfAbsenceReport();
		break;
	default:
		break;
	}
}

void menu::recentReport() {
	cout << "Recent Absences: " << endl;
	sRecordNode *temp = this->sList->getHead();
	string recent;
	while (temp != nullptr) {
		if (temp->getStack()->isEmpty() == false) {
			recent = temp->getStack()->getTop()->getData().getDate();

			cout << temp->getFirstName() << " " << temp->getLastName() << ":" << recent << endl;
		}
		else {
			cout << temp->getFirstName() << " " << temp->getLastName() << ": No absences!" << endl;
		}
		temp = temp->getNext();
	}
	cout << "\n" << endl;
	//system("pause");
}

void menu::numOfAbsenceReport() {
	int min = 0;

	do {
		//system("cls");
		cout << "How many absences do you wish to look at?";
		cin >> min;

	} while (min < 1);
	sRecordNode *temp = this->sList->getHead();
	string recent;
	while (temp != nullptr) {
		int absecent = std::stoi(temp->getAbsenceList());
		if (absecent >= min) {
			cout << temp->getFirstName() << " " << temp->getLastName() << endl;
		}
		temp = temp->getNext();
	}
	////system("pause");
}


void menu::printMenu() {
	////system("cls");
	int choice = 0;
	do {

		cout << "THIS IS YOUR ATTENDANCE TRACKER FOR THIS CLASS" << endl;
		cout << "1. Import Course List:" << endl;
		cout << "2. Load class list: " << endl;
		cout << "3. Store master list: " << endl;
		cout << "4. Mark Absense: " << endl;
		cout << "5. Edit absesnse: " << endl;
		cout << "6. Generate report: " << endl;
		cout << "7. Exit:" << endl;

		cin >> choice;
		switch (choice) {
		case 1:
			if (isLoaded() == false) {
				this->loadClassList();
			}
			break;
		case 2:
			if (isLoaded() == false) {
				this->includeMasterList();
			}
			break;
		case 3:
			this->writeToMasterFile();
			break;
		case 4:
			if (this->sList->getHead() != nullptr) {
				this->isAbsence();
			}
			else {
				////system("cls");
				cout << "Error! Unable to find attendance!" << endl;
				//////system("pause");
			}
			break;
		case 6:
			if (this->sList->getHead() != nullptr) {
				this->getReport();
			}
			else {
				////system("cls");
				cout << "Error! Unable to find attendance!" << endl;
				////system("pause");
			}
			break;
		default:
			break;
		}
	} while (choice != 7);
}

void menu::runApp() {
	printMenu();
}



