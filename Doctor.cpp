/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/





#include "Doctor.h"



Doctor::Doctor() : User() {
	hourlyCharge = 0;
	location = "";
	experience = 0;
	hosp_name = "";
	datetime_availableslots = new DateTime*[10];
	slots_size = 0;

}

Doctor::Doctor(string user,string pass,string cn,string em,double hour_char,string hosp, string loc, int ex):User(user,pass,cn) {
	hourlyCharge = hour_char;
	
	location = loc;
	experience = ex;
	hosp_name = hosp;
	datetime_availableslots = new DateTime * [10];
	slots_size = 0;
}

double Doctor::getHourlyCharge() {
	return hourlyCharge;
}

void Doctor::setHourlyCharge(double hour_char) {
	hourlyCharge = hour_char;
}


string Doctor::getLoc() {
	return location;
}

void Doctor::setLoc(string loc) {
	location = loc;
}


string Doctor::getUserType() {
	return "Doctor";
}


string Doctor::getHospname() {
	return hosp_name;
}

void Doctor::setHospname(string h) {
	hosp_name = h;

}


int Doctor::getTime() {
	return time;
}

void Doctor::setTime(int t) {
	time = t;
}


void Doctor::AddSlots_Time() {

	int day, hour;

	cout << "Enter the Day " << endl;
	cin >> day;

	cout << "Enter the Hour" << endl;
	cin >> hour;

	datetime_availableslots[slots_size] =  new DateTime(day, hour);
	slots_size++;


}

DateTime** Doctor::getAvailableSlots()
{
	return datetime_availableslots;
}

int Doctor::getSlotsSize()
{
	return slots_size;
}