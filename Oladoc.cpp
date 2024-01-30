/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/


#include "Oladoc.h"


//Getters

int Oladoc::getSize() {
	return size;
}

User **Oladoc::getUsers() {
	return users;
}

//Constructor
Oladoc::Oladoc() {
	users = new User*[100];
	size = 0;
	LoggedInUserIndex = -1;
	Appointment* app = new Appointment[10];
	fstream file("doctor.txt", ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			vector<string> words{};
			size_t pos = 0;
			while ((pos = line.find(" ")) != string::npos) {
				words.push_back(line.substr(0, pos));
				line.erase(0, pos + 1);
			}
			words.push_back(line);
			if (words[5] == "Gynecologist")
			{
				users[size] = new Gynecologist(words[0], words[1], words[2], words[3], stod(words[4]), words[6], words[7], stoi(words[8]));
				size++;
			}
			else if (words[5] == "Dermatologist")
			{
				users[size] = new Dermatologist(words[0], words[1], words[2], words[3], stod(words[4]), words[6], words[7], stoi(words[8]));
				size++;
			}
			else if (words[5] == "Oncologist")
			{
				users[size] = new Oncologist(words[0], words[1], words[2], words[3], stod(words[4]), words[6], words[7], stoi(words[8]));
				size++;
			}

			else if (words[5] == "Orthopedic")
			{
				users[size] = new Orthopedic(words[0], words[1], words[2], words[3], stod(words[4]), words[6], words[7], stoi(words[8]));
				size++;
			}

		}
		file.close();
	}
	fstream file2("patient.txt", ios::in);
	if (file2.is_open()) {
		string line;
		while (getline(file2, line)) {
			vector<string> words{};
			size_t pos = 0;
			while ((pos = line.find(" ")) != string::npos) {
				words.push_back(line.substr(0, pos));
				line.erase(0, pos + 1);
			}
			words.push_back(line);
			users[size] = new Patient(words[0], words[1], words[2], stod(words[3]));
			size++;
		}
		file.close();
	}
}

//Filehandling register

void Oladoc::Register() {
	int reg;
	cout << "Press 1 to Register as Doctor" << endl;
	cout << "Press 2 to Register as Patient" << endl;
	cout << "Press 3 to Register as Admin" << endl;
	cin >> reg;

	if (reg == 1) {
		string user,pass, loc, cn, em,hosp;
		int spec;
		double hourly_char;
		int year_exp;
		
		cout << "Enter Username: " << endl;
		cin >> user;
		cout << "Enter Password: " << endl;
		cin >> pass;
		while (!verifyPass(pass))
		{
			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> pass;
		}

		cout << "Enter Email: " << endl;
		cin >> em;
		
		cout << "Enter CNIC: " << endl;
		cin >> cn;
		
		while (!(cn.size() == 13 && is_digits(cn)))
		{
			cout << "Invalid cnic please check the digits and enter cnic again " << endl;
			cin >> cn;
		}	
		
		for (int i = 0; i < size; i++)
		{
			if (users[i]->getCnic() == cn && users[i]->getEmail() == em)
			{
				cout << "User with this email and cnic already exists" << endl;
				return;
			}
		}

		ofstream reg("doctor.txt", ios::app);
		cout << endl;
		cout << "Enter years of experience " << endl;
		cin >> year_exp;
		cout << "Enter Hourly Charge: " << endl;
		cin >> hourly_char;
		cout << "Enter Speciality: " << endl;
		cout << "1. Gynecologist" << endl;
		cout << "2. Dermatologist" << endl;
		cout << "3. Oncologist" << endl;
		cout << "4. Orthopedic" << endl;
		cin >> spec;
		while (spec < 1 || spec > 4)
		{
			cout << "Invalid Input" << endl;
			cin >> spec;
		}
		cout << "Enter Hospital name: " << endl;
		cin >> hosp;
		cout << "Enter eity: " << endl;
		cin >> loc;
		if (spec == 1)
		{
			reg << user << " " << pass << " " << cn << " " << em << " " << hourly_char << " " << "Gynecologist" << " " << hosp << " " << loc << " " << year_exp << endl;
			Gynecologist* doc = new Gynecologist(user, pass, cn, em, hourly_char, hosp, loc, year_exp);
			users[size] = doc;
			size++;
		}

		else if (spec == 2)
		{
			reg << user << " " << pass << " " << cn << " " << em << " " << hourly_char << " " << "Dermatologist" << " " << hosp << " " << loc << " " << year_exp << endl;
			Dermatologist* doc = new Dermatologist(user, pass, cn, em, hourly_char, hosp, loc, year_exp);
			users[size] = doc;
			size++;
		}
		else if (spec == 3)
		{
			reg << user << " " << pass << " " << cn << " " << em << " " << hourly_char << " " << "Oncologist" << " " << hosp << " " << loc << " " << year_exp << endl;
			Oncologist* doc = new Oncologist(user, pass, cn, em, hourly_char, hosp, loc, year_exp);
			users[size] = doc;
			size++;
		}

		else if (spec == 4)
		{
			reg << user << " " << pass << " " << cn << " " << em << " " << hourly_char << " " << "Orthopedic" << " " << hosp << " " << loc << " " << year_exp << endl;
			Orthopedic* doc = new Orthopedic(user, pass, cn, em, hourly_char, hosp, loc, year_exp);
			users[size] = doc;
			size++;
		}

		reg.close();

	}

	else if (reg == 2) {
		string user, pass, cn;
		double balance;
		

		cout << "Enter Username: " << endl;
		cin >> user;
		cout << "Enter Password: " << endl;
		cin >> pass;
		while (!verifyPass(pass))
		{
			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> pass;
		}

		cout << "Enter Balance: " << endl;
		cin >> balance;
		cout << "Enter CNIC: " << endl;
		cin >> cn;
		
		while (!(cn.size() == 13 && is_digits(cn)))
		{
			cout << "Invalid cnic please check the digits and enter cnic again " << endl;
			cin >> cn;
		}
		
		
		
		ofstream reg2("patient.txt", ios::app);
		reg2 << user << " " << pass << " " << cn<<" "<<balance << endl;
		reg2.close();
		cout << "Initial Balance: " << balance << endl;
		Patient* pat = new Patient(user, pass,cn, balance);

		users[size] = pat;
		size++;
	}

	else if (reg == 3) {
	string user, pass;
		


		cout << "Enter Username: " << endl;
		cin >> user;
		cout << "Enter Password: " << endl;
		cin >> pass;
		while (!verifyPass(pass))
	{
		cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
		cin >> pass;
	}

		



		ofstream reg3("admin.txt", ios::app);
		reg3 << user << " " << pass << " " << endl;
		reg3.close();
		
		Admin* admin = new Admin(user, pass);

			users[size] = admin;
			size++;
	}
}

//Login
int Oladoc::Login() {
	int count = 0;
	int ch;
	cout << "1. Login as Patient: " << endl;
	cout << "2. Login as Doctor: " << endl;
	cout << "3. Login as Admin: " << endl;

	cin >> ch;
	string user, pass, u, p;
	
	if (ch == 1)
	{
		cout << "Enter Username: ";
		cin >> user;
		cout << "Enter Password: ";
		cin >> pass;
		while (!verifyPass(pass))
		{
			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> pass;
		}


		for (int i = 0; i < size; i++)
		{
			if (users[i]->getUsername() == user && users[i]->getPassword() == pass && users[i]->getUserType() == "Patient")
			{
				LoggedInUserIndex = i;
				return 1;
			}
		}
		return -1;
	}

	else if (ch == 2) {
		cout << "Enter Username: ";
		cin >> user;
		cout << "Enter Password: ";
		cin >> pass;
		while (!verifyPass(pass))
		{
			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> pass;
		}


		for (int i = 0; i < size; i++)
		{
			if (users[i]->getUsername() == user && users[i]->getPassword() == pass)
			{
				LoggedInUserIndex = i;
				return 1;
			}
		}
		return -1;
	}


	else if (ch == 3) {

		cout << "Enter username " << endl;
		cin >> user;
		cout << "Enter Password " << endl;
		cin >> pass;
		while (!verifyPass(pass))
		{
			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> pass;
		}
		for (int i = 0; i < size; i++)
		{
			if (users[i]->getUsername() == user || users[i]->getPassword() == pass || users[i]->getUserType() == "Admin")
			{
				
				LoggedInUserIndex = i;
				return 1;
			}
		}
		return -1;


	}




}



//Booking appointment

void Oladoc::BookAppointment() 
{
	string appointmentsFor;
	if (users[LoggedInUserIndex]->getUserType() == "Doctor")
	{
		appointmentsFor = "Patient";
	}

	else
	{
		appointmentsFor = "Doctor";
	}

	cout << "Enter the number of " << appointmentsFor << " you want to book an appointment with: " << endl;

	if (appointmentsFor == "Patient")
	{
		cout << "ID\tUsername\tCNIC" << endl;
	}

	else if (appointmentsFor == "Doctor")
	{
		cout << "ID\tUsername\tCNIC\tSpecialization\tHourly Charge\tLocation" << endl;
	}


	
	for (int i = 0; i < size; i++)
	{
		if (appointmentsFor == "Patient" && users[i]->getUserType() == "Patient")
		{
			cout << i + 1 << "\t" << users[i]->getUsername() << "\t" << users[i]->getCnic() << endl;
			
		}
		

		 if (appointmentsFor == "Doctor" && users[i]->getUserType() != "Patient")
		{
			Doctor* doc = dynamic_cast<Doctor*>(users[i]);
			cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
		}
		
		 
		
	}
	DateTime obj;
	int id;
	cin >> id;
	cout << "Enter type of appointmemt: " << endl;
	cout << "1. Online" << endl;
	cout << "2. In Person" << endl;
	int type_of_appointment;
	cin >> type_of_appointment;
	Appointment* app = NULL;
	if (type_of_appointment == 1)
	{
		Doctor* doc = dynamic_cast<Doctor*>(users[id-1]);
		cout << "Select one time slot" << endl;
		int slot;
		for (int i = 0; i < doc->getSlotsSize(); i++)
		{
			cout << i+1 <<" "<< doc->getAvailableSlots()[i]->getDay() << " " << doc->getAvailableSlots()[i]->getHour() << endl;
		}
		cin >> slot;
		app = new OnlineAppointment(*doc->getAvailableSlots()[slot-1], "Pending");
	}

	else if (type_of_appointment == 2)
	{
		Doctor* doc = dynamic_cast<Doctor*>(users[id - 1]);
		cout << "Select one time slot" << endl;
		int slot;
		for (int i = 0; i < doc->getSlotsSize(); i++)
		{
			cout << i + 1 << " " << doc->getAvailableSlots()[i]->getDay() << " " << doc->getAvailableSlots()[i]->getHour() << endl;
		}
		cin >> slot;
		app = new InPersonAppointment(*doc->getAvailableSlots()[slot-1], "Pending");
	}
	users[LoggedInUserIndex]->setAppointment(app);
	users[id - 1]->setAppointment(app);



}

//searching for doctor via speciality , area and hospital name
void Oladoc::Search() {

	int ch, spec;
	string area, hosp;
	if (users[LoggedInUserIndex]->getUserType() == "Patient")
	{
		cout << "Press 1 to Search By Speciality" << endl;
		cout << "Press 2 to Search By Area" << endl;
		cout << "Press 3 to Search By Hospital Name" << endl;
		cin >> ch;



		string specilization;

		if (ch == 1)
		{
			int choice;
			cout << "Press 1 for Gynecologist" << endl;
			cout << "Press 2 for Dermatologist" << endl;
			cout << "Press 3 For Onologist" << endl;
			cout << "Press 4 For Orthopedic" << endl;
			cin >> choice;

			if (choice == 1) {
				specilization = "Gynecologist";
			}
			else if (choice == 2) {
				specilization = "Dermatlogist";
			}
			else if (choice == 3) {
				specilization = "Onologist";
			}
			else if (choice == 4) {
				specilization = "Orthopedic";
			}




			for (int i = 0; i < size; i++) {
				if (users[i]->getUserType() == specilization) {
					Doctor* doc = dynamic_cast<Doctor*>(users[i]);
					cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
				}
			}
		}


		else if (ch == 2) {
			cout << "Enter the area " << endl;
			cin >> area;


			for (int i = 0; i < size; i++) {
				if (users[i]->getUserType() != "Patient") {
					Doctor* doc = dynamic_cast<Doctor*>(users[i]);
					if (doc->getLoc() == area) {
						cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
					}
				}

			}


		}
		else if (ch == 3) {
			cout << "Enter the Hospital Name " << endl;
			cin >> hosp;

			for (int i = 0; i < size; i++) {
				if (users[i]->getUserType() != "Patient") {
					Doctor* doc = dynamic_cast<Doctor*>(users[i]);
					if (doc->getHospname() == hosp)
					{
						cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;


					}
				}
			}
		}
	}

}

//Modifiying patient details
void Oladoc::ModifyDetails() {
	int ch;
	string username;
	int choice;
	if (users[LoggedInUserIndex]->getUserType() == "Patient") {
		cout << "Press 1 to Change Username" << endl;
		cout << "Press 2 to Change Password" << endl;
		cout << "Press 3 to Change Cnic" << endl;
		cin >> choice;


		if (choice == 1)
		{
			cout << "Enter  Username" << endl;
			cin >> username;

			for (int i = 0; i < size; i++)
			{
				if (users[i]->getUsername() == username) {
					cout << "Enter the new username" << endl;
					cin >> username;
					users[i]->setUsername(username);

				}


			}
		}

		else if (choice == 2) {
			string pass;
			cout << "Enter the Password" << endl;
			cin >> pass;
			while (!verifyPass(pass))
			{
				cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
				cin >> pass;
			

			
				for (int i = 0; i < size; i++)
				{
					if (users[i]->getPassword() == pass) {
						cout << "Enter the New Password" << endl;
						cin >> pass;
						users[i]->setPass(pass);

					}
				}
			}
		}


		else if (choice == 3) {
			string cnic;
			cout << "Enter the CNIC" << endl;
			cin >> cnic;
			while (!(cnic.size() == 13 && is_digits(cnic)))
			{
				cout << "Invalid cnic please check the digits and enter cnic again " << endl;
				cin >> cnic;

				for (int i = 0; i < size; i++) {
					if (users[i]->getCnic() == cnic) {
						cout << "Enter the New Cnic" << endl;
						cin >> cnic;
						users[i]->setCnic(cnic);
					}
				}
			}
		}
	}
}
	
	//Reseting pass
void Oladoc::ResetPassword() {
	string password;
	if (users[LoggedInUserIndex]->getUserType() == "Patient") {
		cout << "Enter New Password" << endl;
		cin >> password;

		while (!verifyPass(password))
		{

			cout << "Password must contain at least one uppercase character, one special character, one lower case and must be 8 characters long" << endl;
			cin >> password;

			for (int i = 0; i < size; i++) {
				if (users[i]->getPassword() == password) {
					cout << "Reset your password" << endl;
					cin >> password;
					users[i]->setPass(password);
				}
			}
		}

	}
}

//for recharging balance balance must always be 3500
void Oladoc::RechargeAccount() {
	double balance;
	cout << "Enter Balance" << endl;
	cin >> balance;
	if (balance <3500) {
		cout << "Your Balance is low Please Recharge your account" << endl;
		cin >> balance;
		
	}
}
	
	//checking if doctor is available or not
void Oladoc::Check_Availablity() {
	int ch;
	string specilization, username;
	cout << "Press 1 to check Doctor Availability" << endl;
	cout << "Press 2 to check Doctor Hourly Charge" << endl;
	cin >> ch;

	if (ch == 1) {
		int choice;
		cout << "Press 1 for Gynecologist" << endl;
		cout << "Press 2 for Dermatologist" << endl;
		cout << "Press 3 For Onologist" << endl;
		cout << "Press 4 For Orthopedic" << endl;
		cin >> choice;

		if (choice == 1) {
			specilization = "Gynecologist";
		}
		else if (choice == 2) {
			specilization = "Dermatlogist";
		}
		else if (choice == 3) {
			specilization = "Onologist";
		}
		else if (choice == 4) {
			specilization = "Orthopedic";
		}

		cout << "Enter the name of Doctor " << endl;
		cin >> username;




		for (int i = 0; i < size; i++) {
			if (users[i]->getUsername() == username && users[i]->getUserType() == specilization) {
				Doctor* doc = dynamic_cast<Doctor*>(users[i]);
				cout << "Doctor is Available" << endl;
				cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;

			}

		}
	}



	else if (ch == 2) {


		int choice;
		cout << "Press 1 for Gynecologist" << endl;
		cout << "Press 2 for Dermatologist" << endl;
		cout << "Press 3 For Onologist" << endl;
		cout << "Press 4 For Orthopedic" << endl;
		cin >> choice;

		if (choice == 1) {
			specilization = "Gynecologist";
		}
		else if (choice == 2) {
			specilization = "Dermatlogist";
		}
		else if (choice == 3) {
			specilization = "Onologist";
		}
		else if (choice == 4) {
			specilization = "Orthopedic";
		}

		cout << "Enter the name of Doctor " << endl;
		cin >> username;




		for (int i = 0; i < size; i++) {
			if (users[i]->getUsername() == username && users[i]->getUserType() == specilization) {
				Doctor* doc = dynamic_cast<Doctor*>(users[i]);
				cout << "The hourly charge for this Doctor is " << endl;
				cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;

			}

		}
	}

}

//canceling the made appointment
void Oladoc::CancelAppointment()
{
	string appointmentsFor;
	if (users[LoggedInUserIndex]->getUserType() == "Doctor")
	{
		appointmentsFor = "Patient";
	}

	else
	{
		appointmentsFor = "Doctor";
	}

	cout << "Enter the number of Appointments you want to cancel with " << appointmentsFor << endl;

	if (appointmentsFor == "Patient")
	{
		cout << "ID\tUsername\tCNIC" << endl;
	}

	else if (appointmentsFor == "Doctor")
	{
		cout << "ID\tUsername\tCNIC\tSpecialization\tHourly Charge\tLocation" << endl;
	}

	for (int i = 0; i < size; i++)
	{
		if (appointmentsFor == "Patient" && users[i]->getUserType() == "Patient")
		{
			cout << i + 1 << "\t" << users[i]->getUsername() << "\t" << users[i]->getCnic() << endl;


		}

		if (appointmentsFor == "Doctor" && users[i]->getUserType() != "Patient")
		{
			Doctor* doc = dynamic_cast<Doctor*>(users[i]);
			cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
		}
	}
	DateTime obj;
	int id;
	cin >> id;
	cout << "Enter type of appointmemt: " << endl;
	cout << "1. Online" << endl;
	cout << "2. In Person" << endl;
	int type_of_appointment;
	cin >> type_of_appointment;
	Appointment* app = NULL;
	if (type_of_appointment == 1)
	{
		app = new Appointment(obj, "Pending");
	}

	else if (type_of_appointment == 2)
	{
		app = new Appointment(obj, "Pending");
	}

	users[LoggedInUserIndex]->setAppointment(app);
	users[id - 1]->setAppointment(app);
}


//Checking details of appointmnet
void Oladoc::CheckAppointmentDetails() {
	string appointmentsFor;
	if (users[LoggedInUserIndex]->getUserType() == "Doctor")
	{
		appointmentsFor = "Patient";
	}

	else if(users[LoggedInUserIndex]->getUserType()=="Patient")
	{
		appointmentsFor = "Doctor";
	}
	else {
		appointmentsFor = "Admin";
	}

	cout << "Enter the number of Appointments " << appointmentsFor <<"Have with patients" << endl;

	if (appointmentsFor == "Patient")
	{
		cout << "ID\tUsername\tCNIC" << endl;
	}

	else if (appointmentsFor == "Doctor")
	{
		cout << "ID\tUsername\tCNIC\tSpecialization\tHourly Charge\tLocation" << endl;
	}
	else {
		cout << "ID\tUsername\tCNIC\tSpecialization\tHourly Charge\tLocation" << endl;



	}

	for (int i = 0; i < size; i++)
	{
		if (appointmentsFor == "Patient" && users[i]->getUserType() == "Patient")
		{
			
			cout << i + 1 << "\t" << users[i]->getUsername() << "\t" << users[i]->getCnic() << endl;

		}

		if (appointmentsFor == "Doctor" && users[i]->getUserType() != "Patient")
		{
			Doctor* doc = dynamic_cast<Doctor*>(users[i]);
			cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
		}

		if (appointmentsFor == "Admin" && users[i]->getUserType() != "Patient")
		{
			Doctor* doc = dynamic_cast<Doctor*>(users[i]);
			cout << i + 1 << "\t" << doc->getUsername() << "\t" << doc->getCnic() << "\t" << doc->getUserType() << "\t" << doc->getHourlyCharge() << "\t" << doc->getLoc() << endl;
		}
	}
	DateTime obj;
	int id;
	cin >> id;
	cout << "Enter type of appointmemt: " << endl;
	cout << "1. Online" << endl;
	cout << "2. In Person" << endl;
	int type_of_appointment;
	cin >> type_of_appointment;
	Appointment* app = NULL;
	if (type_of_appointment == 1)
	{
		app = new Appointment(obj, "Pending");
	}

	else if (type_of_appointment == 2)
	{
		app = new Appointment(obj, "Pending");
	}

	users[LoggedInUserIndex]->setAppointment(app);
	users[id - 1]->setAppointment(app);
}


//modifiying doctor details 
void Oladoc::ModifyDetailsDr() {
	int ch;
	string location;
	int timing;
	double rates;
	int choice;
	if (users[LoggedInUserIndex]->getUserType() == "Doctor") {
		cout << "Press 1 to Change Location" << endl;
		cout << "Press 2 to Change Rates" << endl;
		cout << "Press 3 to Change Timing" << endl;
		cin >> choice;


		if (choice == 1)
		{
			cout << "Enter  Location" << endl;
			cin >> location;

			for (int i = 0; i < size; i++)
			{
				Doctor* doc = dynamic_cast<Doctor*>(users[i]);
				if (doc->getLoc() == location) {
					cout << "Enter the new Location" << endl;
					cin >> location;
					doc->setLoc(location);

				}


			}
		}

		else if (choice == 2) {

			cout << "Enter the Rates" << endl;
			cin >> rates;


			for (int i = 0; i < size; i++)
			{
				Doctor* doc = dynamic_cast<Doctor*>(users[i]);
				if (doc->getHourlyCharge() == rates) {
					cout << "Enter the New Rates" << endl;
					cin >> rates;
					doc->setHourlyCharge(rates);

				}
			}
		}



		else if (choice == 3) {

			cout << "Enter the Timings" << endl;
			cin >> timing;

			for (int i = 0; i < size; i++) {
				Doctor* doc = dynamic_cast<Doctor*>(users[i]);
				if (doc->getTime() == timing) {
					cout << "Enter the New Timings" << endl;
					cin >> timing;
					doc->setTime(timing);
				}
			}
		}
	}

}

//Adding slots for appointment

void Oladoc::Addslots() {


	if (users[LoggedInUserIndex]->getUserType() != "Patient") {

		Doctor* doc = dynamic_cast<Doctor*>(users[LoggedInUserIndex]);
		doc->AddSlots_Time();

	}

}
//editing doctor info
void Oladoc::EditDoctorInformation()
{
	Doctor* doc = dynamic_cast<Doctor*>(users[LoggedInUserIndex]);
	cout << "Enter new hourly charge: ";
	double hourlyCharge;
	cin >> hourlyCharge;
	doc->setHourlyCharge(hourlyCharge);
}
//displaying appointments
void Oladoc::ListAppointments()
{
	Doctor* doc = dynamic_cast<Doctor*>(users[LoggedInUserIndex]);
	for (int i = 0; i < doc->getAppointmentsSize(); i++)
	{
		cout << doc->getAppointments()[i].getDate_Time().getDay() << " " << doc->getAppointments()[i].getDate_Time().getHour() << " " << doc->getAppointments()[i].getType() << " " << endl;
	}
}

	
	
