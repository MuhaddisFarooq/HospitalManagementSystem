#pragma once
#include<string>
#include<iostream>
#include"Doctor.h"
using namespace std;

class Gynecologist:public Doctor
{
private:
	
	
public:
	Gynecologist();
	Gynecologist(string, string, string, string, double, string, string, int);
	string getUserType();
};

