#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
const unsigned short numComponents = 10;
unsigned short prices[numComponents];
string treatments[numComponents];
void welcome ( );
void showMenu ( );
void priceList ( );
void makeAppointment ( );
void openAppointments( );
void checkTime( );
void display_appointments(); 
char choice;
int day,d,j;
string date, customer, treatment;
string appBook[5][8][3];
int main () 
{
	welcome ();
	openAppointments();
	do
	{
		showMenu ();
		switch (toupper(choice))
		{									
			case 'A':
				makeAppointment();
			break;
			case 'Q':
				 cout << "\nThank you.\n"; 
			break;
            		default: 
           			 cout << "Invalid choice.\n";
           		break;
        	}
   	}while (toupper(choice) != 'Q');
return 0;
}
void welcome () 
{
// Welcome the user to the program.
	cout << "******************************\n        welcome to\n        RATHOD hospital\n******************************\n\n";
}
void showMenu () 
{
// Output the menu to the user.
	cout << "\nSelect one of the following options:\n"
	<< "------------------------------------\n"
	<< "A:Make an Appointment\n"
	<< "Q:Exit\n";
        cin >> choice;
}
void openAppointments()
{
}
void printPrices (string treatments, unsigned short prices[]) 
{
	for (unsigned short i = 0; i < numComponents; i++) 
	{
		cout << setw (50) << setiosflags(ios::left) << treatments[i] << prices[i] << "\n";
		if (i% 20 == 0 && i != 0)
		{
		}
	}
}
void showDays () 
{
// Output the menu to the user.
	    cout << "\n\tSelect one of the following days:\n"
		<< "\t------------------------------------\n\n"
		<< "\t1:Monday\n"
		<< "\t2:Tuesday\n"
		<< "\t3:Wednesday\n"
		<< "\t4:Thursday\n"
		<< "\t5:Friday\n\n";
		cin >> day;
} 
void makeAppointment () 
{
// Asks the user for the day of the appointment
	showDays();
	switch(day)
	{
		case 1:
        		date = "Monday";
        		checkTime();
        	break;
    		case 2:
        		date = "Tuesday";
        		checkTime();
        	break;
    		case 3:
        		date = "Wednesday";
        		checkTime();
        	break;
   	 	case 4:
        		date = "Thursday";
        		checkTime();
        	break;
    		case 5:
        		date = "Friday";
        		checkTime();
        	break;
    		default:
        		showMenu();
        	break;
	}
}
void checkTime()
{
// Checks the arrays for free time and stores the inputs.
 	int time;
	bool checkSum = false;
	cout<<"enter the number of patients\n";
	cin>>d;
	for(j=0;j<d;j++)
	{
		do
		{
			cout<<"appoinments are available for following times\n1.11am\t\t2.12pm\t\t3.13pm\t\t4.14pm\t\t5.15pm\t\t";
        		cout << "\nEnter time for appointment for patient "<<j+1<<"\n";
        		cin >> time;
        		if(appBook[day][time-9][0] == "")
        		{
        	   		cout << "\nEnter the name of patient:\n";
        	    		cin >> customer;
        	    		cout << "\nEnter the treatment for "<< customer <<":\n";
        	    		cin >> treatment;
       	 	    		appBook[day][time-9][0] = date;
            			appBook[day][time-9][1] = customer;
            			appBook[day][time-9][2] = treatment;
            			checkSum = true;
        		} 
        		else 
        		{
                		cout<< "\nThat time is taken!\n"
                		<< "\t-----------------------\n\n";
        		}
    		}while(checkSum == false);
    		cout <<"\n/***"<< appBook[day][time-9][1] << " is getting a treatment for " << appBook[day][time-9][2] << " at " << time << " on " << appBook[day][time-9][0]<<"***/\n\n";
    	}
}
