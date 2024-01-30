#pragma once
#include "Appointment.h"
class InPersonAppointment : public Appointment
{
public:
	InPersonAppointment();
	InPersonAppointment(DateTime, string);
};

