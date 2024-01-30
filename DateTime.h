
/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/



#pragma once
#include<string>
class DateTime
{
private:
	int day, hour;

public:
	DateTime();
	DateTime(int, int);
	int getDay();
	void setDay(int);
	int getHour();
	void setHour(int);
	void operator=(const DateTime & obj);
	

};

