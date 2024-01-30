/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/





#pragma once
#include"User.h"
#include"Doctor.h"
#include"Patient.h"
#include"Admin.h"
#include<fstream>
#include <vector>
#include"Appointment.h"
#include"Gynecologist.h"
#include"Dermatologist.h"
#include"Oncologist.h"
#include"Orthopedic.h"
#include"Doctor.h"
#include"Utils.h"
#include "OnlineAppointment.h"
#include "InPersonAppointment.h"

class Oladoc
{
private:
	User** users;
	int size;
	int LoggedInUserIndex;
	
	

public:
	Oladoc();
	int Login();
	void Register();
	int getSize();
	User **getUsers();
	void BookAppointment();
	void CancelAppointment();
	void ModifyDetails();
	void Search();
	void Check_Availablity();
	void ResetPassword();
	void RechargeAccount();
	void CheckAppointmentDetails();
	void ModifyDetailsDr();
	void Addslots();
	void EditDoctorInformation();
	void ListAppointments();
	
};