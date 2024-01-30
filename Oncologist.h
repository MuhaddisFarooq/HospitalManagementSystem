#pragma once
#include<string>
#include<iostream>
#include"Doctor.h"
using namespace std;

class Oncologist :public Doctor
{
private:


public:
	Oncologist();
	Oncologist(string, string, string, string, double, string, string, int);
	string getUserType();
};

