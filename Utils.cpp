#pragma once
#include"Utils.h"
//Function
bool is_digits(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}
bool verifyPass(string password) {

	bool special_symbs = false, upper_case = false, lower_case = false, digit = false;
	int length = 0;
	while (password[length] != 0)
	{
		length++;
	}


	for (int i = 0; i < length; i++)
	{
		if ((password[i] >= 32 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
		{
			special_symbs = true;
		}
		if (password[i] >= 65 && password[i] <= 90)
		{
			upper_case = true;
		}
		if (password[i] >= 97 && password[i] <= 122)
		{
			lower_case = true;
		}
		if (password[i] >= 48 && password[i] <= 57)
		{
			digit = true;
		}
	}

	if (length < 8)
	{
		return false;
	}

	if (special_symbs && upper_case && lower_case && digit)
	{
		return true;
	}

	return false;
}


