#include<iostream>
using namespace std;
class personal
{	
	private:
		char name[50],email[50],address[80];
		long int mob_no;
	public:
		void read_personal();
		void display_personal();
	
};
void personal::read_personal()
{
	cout<<"\nenter name\n";
	cin>>name;
	cout<<"\nenter email address\n";
	cin>>email;
	cout<<"\nenter address\n";
	cin>>address;
	cout<<"\nenter mobile number\n";
	cin>>mob_no;
}
void personal::display_personal()
{
	cout<<"\nName="<<name;
	cout<<"\nemail address="<<email;
	cout<<"\nenter address="<<address;
	cout<<"\nenter phone number="<<mob_no<<"\n";
}
class professional
{
	private:
		int salary,doj,experience;
	public:
		void read_professional();
		void display_professional();
};
void professional::read_professional()
{
	cout<<"\nenter salary\n";
	cin>>salary;
	cout<<"\nenter the year of joining\n";
	cin>>doj;
	cout<<"\nenter the experience\n";
	cin>>experience;
}
void professional::display_professional()
{
	cout<<"\nSalary="<<salary;
	cout<<"\nDate of Joining="<<doj;
	cout<<"\nExperience="<<experience<<"\n";
}
class academics
{
	private:
		float ssc_mks,hsc_mks,gate_scr;
		char clg_name[50];
	public:
		void read_academics();
		void display_academics();
};
void academics :: read_academics()
{
	cout<<"\nenter the name of college\n";
	cin>>clg_name;
	cout<<"enter ssc marks of the employee\n";
	cin>>ssc_mks;
	cout<<"enter hsc marks of the employee\n";
	cin>>hsc_mks;
	cout<<"enter gate score of the employee\n";//display of ACADEMICS REMAONONG
	cin>>gate_scr;
}
void academics :: display_academics()
{
	cout<<"\nname of the clg is\n"<<clg_name;
	cout<<"\nmarks scored in ssc is\n"<<ssc_mks;
	cout<<"\nmarks scored in hsc is\n"<<hsc_mks;
	cout<<"\nmarks scored in gate examination is\n"<<gate_scr;
}
int main()
{
	personal e1;
	e1.read_personal();
	e1.display_personal();
	professional e2;
	e2.read_professional();
	e2.display_professional();
	academics e3;
	e3.read_academics();
	e3.display_academics();
	return 0;
}	

