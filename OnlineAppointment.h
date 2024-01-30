#pragma once
#include "Appointment.h"
class OnlineAppointment : public Appointment
{
public:
	OnlineAppointment();
	OnlineAppointment(DateTime, string);
};

