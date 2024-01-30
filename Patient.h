/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/



#pragma once

#include"User.h"
#include<fstream>
#include"Doctor.h"
#include"Utils.h"

class Patient:public User
{
protected:
	double balance;


public:
	Patient();
	Patient(string,string,string,double);
	double getBalance();
	void setBalance(double);
	string getUserType();
	

};

