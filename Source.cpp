/*

NAME : MUHADDIS FAROOQ
ROLL: 21I-0391
SECTION: G


*/




#include <iostream>
#include"Oladoc.h"
using namespace std;

int main() 
{
	Oladoc obj;
	while (true) 
	{
		
		int choice;
		cout << "******************************************" << endl;
		cout << "Welcome to Oladoc Hospital" << endl;

		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Exit" << endl;
		

		cin >> choice;
		cout << endl;
		
		switch (choice) 
		{
			
			
		case 1:
			
			int ch;
			cout << "1. Patient" << endl;
			cout << "2. Doctor" << endl;
			cout << "3. Admin" << endl;
			cin >> ch;

			if (ch == 1)
			{

				if (obj.Login() == 1)
				{
					int ch;
					cout << "1. Book Appointment" << endl;
					cout << "2. Search For Doctor" << endl;
					cout << "3. Modify Patient Details" << endl;
					cout << "4. Reset Password" << endl;
					cout << "5. Recharge Account" << endl;
					cout << "6. Check Doctor Availability" << endl;
					cout << "7. Cancel Appointment" << endl;

					cin >> ch;
					if (ch == 1)
					{
						obj.BookAppointment();
						
					}
					else if (ch == 2) {
						obj.Search();
						
					}
					else if (ch == 3) {
						obj.ModifyDetails();
						
					}
					else if (ch == 4) {
						obj.ResetPassword();
						
					}
					else if (ch == 6) {
						obj.Check_Availablity();
						
					}
					else if (ch == 7) {
						obj.CancelAppointment();
						
					}


				}
			}
			else if (ch == 2) {
				
				
				if (obj.Login() == 1) {
					int choi;
					cout << "1. AddSlots" << endl;
					cout << "2. Edit Information" << endl;
					cout << "3. List Appointments" << endl;
					cin >> choi;

					if (choi == 1) {
						obj.Addslots();
						
					}

					else if (choi == 2) {
						obj.EditDoctorInformation();
						
					}

					else if (choi == 3)
					{
						obj.ListAppointments();
						
					}

				}
				
			}
			else if (ch == 3) {
				if (obj.Login() == 1) {
					
						int choi;
						cout << "Press 1 To View All Doctor Appointment" << endl;
						cout << "Press 2 to Edit doctor data " << endl;
						cout << "Press 3 to Edit Patient Data" << endl;
						cin >> choi;
						if (choi == 1) {
							obj.ListAppointments();

						}
						else if (choi == 2) {
							obj.ModifyDetailsDr();

						}
						else if (choi == 3) {
							obj.ModifyDetails();
						}
					


				}
			}

			break;



			
			
			


			
		
		case 2:
			obj.Register();
			break;

		case 3:
			system("cls");
			cout << "Exiting..................." << endl;
			return 0;
		}
	}

	/*Oladoc obj;
	obj.Register();
	obj.Register();
	cout << obj.Login() << endl;
	cout << obj.Login() << endl;
	*/


}



