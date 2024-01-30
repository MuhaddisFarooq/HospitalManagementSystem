#pragma once
#include <iostream>
#include <string>
#include"DateTime.h"
using namespace std;


class Appointment
{
private:
	DateTime Date_time;
	string type;
public:
	Appointment();
	Appointment(DateTime, string);
	DateTime getDate_Time();
	string getType();
};

