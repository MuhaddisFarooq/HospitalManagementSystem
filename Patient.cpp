#include "Patient.h"





Patient::Patient() {
	balance = 0;
}

Patient::Patient(string user, string pass,string cn, double balance) :User(user, pass,cn) {
	this->balance = balance;
}

double Patient::getBalance() {
	return balance;
}

void Patient::setBalance(double bal) {
	balance = bal;
}

string Patient::getUserType() {
	return "Patient";
}

