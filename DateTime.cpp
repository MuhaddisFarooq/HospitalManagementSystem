#include "DateTime.h"

DateTime::DateTime() {
	
	hour = 0;
	day = 0;
}

DateTime::DateTime(int day, int hour){
	
	this->hour = hour;
	this->day = day;
	}



int DateTime::getHour() {
	return hour;
}

int DateTime::getDay() {
	return day;
}


void DateTime::setDay(int d) {
	day = d;
}

void DateTime::setHour(int h) {
	hour = h;
}


void DateTime::operator=(const DateTime& obj) {

	day = obj.day;
	hour = obj.hour;


}