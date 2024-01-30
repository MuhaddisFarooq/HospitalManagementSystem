#pragma once
#include<string>
#include<iostream>
#include"User.h"
#include"DateTime.h"
#include<fstream>
using namespace std;


class Doctor : public User
{
protected:
	double hourlyCharge;
	string location;
	int experience;
	string hosp_name;
	int time;
	DateTime** datetime_availableslots;
	int slots_size;
	
	
	
	
	
public:
	
	Doctor();
	Doctor(string,string,string,string,double, string, string, int);
	double getHourlyCharge();
	void setHourlyCharge(double);
	string getLoc();
	void setLoc(string);
	string getUserType();
	string getHospname();
	void setHospname(string);
	int getTime();
	void setTime(int);
	void AddSlots_Time();
	DateTime** getAvailableSlots();
	int getSlotsSize();


};


