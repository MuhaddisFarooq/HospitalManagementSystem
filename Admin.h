/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/





#pragma once
#include"User.h"
class Admin:public User
{
protected:
	string username;
	string password;

public:
	Admin();
	Admin(string, string);
	string getUsername();
	void setUsername(string);
	string getPassword();
	string getUserType();
	void setPassword(string);

};

