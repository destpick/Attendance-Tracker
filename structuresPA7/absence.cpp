#include "absence.h"

absence::absence(string aDate) {
	date = aDate;
}

string absence::getDate() {
	return date;
}

void absence::setDate(string aDate) {
	date = aDate;
}