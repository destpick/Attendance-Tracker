#pragma once
#include <iostream>
#include <string>

using std::string;

class absence {
private:
	string date;

public:
	absence(string date = "");
	string getDate();
	void setDate(string aDate);
};