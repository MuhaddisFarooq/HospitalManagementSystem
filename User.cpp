
/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/



#include "User.h"

User::User() {
	username = "";
	password = "";
	cnic = "";
	appointments = new Appointment[10];
	sizeapp = 0;
}

User::User(string user, string pass,string cn) {
	username = user;
	password = pass;
	cnic = cn;
	appointments = new Appointment[10];
	sizeapp = 0;
}

string User:: getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

string User::getCnic() {
	return cnic;
}

string User::getEmail() {
	return email;
}

string User::getUserType() {
	return "User";
}



void User::setUsername(string us) {
	username = us;
}

void User::setPass(string pass) {
	password = pass;
}

void User::setCnic(string cn) {
	cnic = cn;
}

void User::setEmail(string em) {
	email = em;
}

void User::setAppointment(Appointment* app)
{
	appointments[sizeapp] = *app;
	sizeapp++;
}

Appointment* User::getAppointments()
{
	return appointments;
}

int User::getAppointmentsSize()
{
	return sizeapp;
}