/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/




#include "Appointment.h"


Appointment::Appointment() {
	Date_time = DateTime();
	type = "";
}

Appointment::Appointment(DateTime d_t, string type) {
	Date_time = d_t;
	this->type = type;
}

DateTime Appointment::getDate_Time() {
	return Date_time;
}

string Appointment::getType() {
	return type;
}




