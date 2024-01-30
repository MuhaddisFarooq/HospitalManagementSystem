#include "Admin.h"


Admin::Admin() {
	username = "";
	password = "";
}

Admin::Admin(string n, string pas) {
	username = n;
	password = pas;
}


string Admin::getUsername() {
	return username;
}

string Admin::getPassword() {
	return password;
}

void Admin::setUsername(string u) {
	username = u;
}

void Admin::setPassword(string p) {
	password = p;
}

string Admin::getUserType() {
	return "Admin";
}