

#pragma once

#include<string>
#include<iostream>
#include"Appointment.h"

using namespace std;
class User
{
protected:
	string username;
	string password;
	string cnic;
	string email;
	Appointment* appointments;
	int sizeapp;
	

public:
	User();
	User(string, string,string);
	string getUsername();
	void setUsername(string);
	string getPassword();
	void setPass(string);
	string getCnic();
	void setCnic(string);
	string getEmail();
	void setEmail(string);
	Appointment* getAppointments();
	int getAppointmentsSize();
	
	void setAppointment(Appointment*);
	virtual string getUserType();
};

