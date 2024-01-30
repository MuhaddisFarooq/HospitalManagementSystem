#pragma once
#include<string>
#include<iostream>
#include"Doctor.h"
using namespace std;

class Dermatologist :public Doctor
{
private:


public:
	Dermatologist();
	Dermatologist(string, string, string, string, double, string, string, int);
	string getUserType();
};

