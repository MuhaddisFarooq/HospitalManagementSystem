#pragma once
#include<string>
#include<iostream>
#include"Doctor.h"
using namespace std;

class Orthopedic :public Doctor
{
private:


public:
	Orthopedic();
	Orthopedic(string, string, string, string, double, string, string, int);
	string getUserType();
};

