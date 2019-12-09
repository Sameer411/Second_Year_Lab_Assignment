#include <iostream>
#include<cstring>
using namespace std;
class except
{	int error;	
	public:
	void display_error(int no)
	{
		if (no==1)
		cout<<"\nError,Nashik is not allowed\n**********************\n"<<endl;
		else if (no==2)
		cout<<"\nError,Age is not allowed\n**********************\n"<<endl;
		else if (no==3)
		cout<<"\nError,vehicle is not allowed\n**********************\n"<<endl;
		else if (no==4)
		cout<<"\nError,salary is not allowed\n**********************\n"<<endl;
	}
};
class person:public except
{	public:
		int salary;
		char city[50];
		int age;
		char vehicle[50];
		void getdata();
		void display();
};
void person::getdata()
{	int flag=1;
	//City----------------------
	while (flag==1)	
	{
		int ch;
		if (flag==1)
		{
			cout<<"Please choose the city that you live in\n1.Chennai\n2.Banglore\n3.Pune\n4.Mumbai\n5.Nashik"<<endl;
			cin>>ch;
			if (ch==1)
				strcpy(city,"Chennai");
			else if (ch==2)
				strcpy(city,"Banglore");
			else if (ch==3)
				strcpy(city,"Pune");
			else if (ch==4)
				strcpy(city,"Mumbai");
			else if (ch==5)
				strcpy(city,"Nashik");
			else
				cout<<"Please enter a valid choice"<<endl;
			try 
			{
				if (strcmp(city,"Nashik")==0)
				{
					flag=0;			
					throw city;
				}
			}
			catch (char city[50])
			{
				except a;
				a.display_error(1);		
			}
		}

//age------------
	if (flag==1)
	{	
		cout<<"Please enter your age";
		cin>>age;
		try 
			{
				if (age<18||age>55)
				{
					flag=0;
					throw age;
				}
			
			}
		catch (int age)
		{
			except a;
			a.display_error(2);
		}
	}
		
//Vehicle---------
	if (flag==1)
	{	
		cout<<"Please choose the vehicle that you have"<<endl;
		cout<<"1.Two wheeler\n2.Four wheeler"<<endl;
		cin>>ch;
		if (ch==1)
			strcpy(vehicle,"2");
		else if (ch==2)
			strcpy(vehicle,"4");
		else
			cout<<"Please enter a valid choice"<<endl;
		try 
		{
			if (strcmp(city,"Four wheeler")==0)
			{
				flag=0;		
				throw vehicle;
			}
		}
		catch (char vehicle[50])
		{
			except a;
			a.display_error(3);
		}
	}
//Salary-------------
	if (flag==1)
	{	
		cout<<"Please enter your salary"<<endl;
		cin>>salary;
		try 
		{
			if (salary<50000||salary>100000)
			{
				flag=0;
				throw salary;
			}
		}
		catch (int salary)
		{
			except a;
			a.display_error(4);
		}
	
	}
	break;
	}
}
void person::display()
{	cout<<"City\t"<<city<<endl;
	cout<<"Age\t"<<age<<endl;
	cout<<"Vehicle\t"<<vehicle<<endl;
	cout<<"Salary\t"<<salary<<"\n"<<endl;
}
int main()
{
	int ch,i=0;
	person a[100];
	do
	{
		cout<<"1.Enter the data of the citizen\n2.Display the data\n3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				a[i].getdata();
				i++;
			break;
			case 2:
				for (int z=0;z<i;z++)
				a[z].display();
			break;
			default:
				cout<<"Please enter a valid choice\n";
			break;
		}
	}while(ch!=3);
}
