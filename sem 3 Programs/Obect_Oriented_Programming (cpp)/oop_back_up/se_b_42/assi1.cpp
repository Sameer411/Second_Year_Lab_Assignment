#include<iostream>
using namespace std;
class students 
{
	public:
	int roll_no;
	long int mob_no;
	char name[10],add[50],class_name[10],div[10],bldgrp[10];
	students()
	{
		cout<<"enter roll no \n";
		cin>>roll_no;
		cout<<"name\n";
		cin>>name;
		cout<<"enter mobile no \n";
		cin>>mob_no;
		cout<<"class\n";
		cin>>class_name;
		cout<<"div\n";
		cin>>div;
		cout<<"blood group\n";
		cin>>bldgrp;
		cout<<"\n";
	}
	void display_data()
	{
		cout<<roll_no<<"  "<<name<<"  "<<mob_no<<"  "<<class_name<<" "<<div<<"  "<<bldgrp<<"  "<<"\n";
	}
};
int main()
{
	int n,z;
	cout<<"enter the number of students"<<endl;
	cin>>n;
	students s[n];
	/*for(int i=0;i<n;i++)
	{
		s[i].get_data();
	}*/
	for(int i=0;i<n;i++)
	{
		s[i].display_data();
	}
	cout<<"enter the roll number you wanted to search\n";
	cin>>z;
	for(int i=0;i<n;i++)
	{
		if(s[i].roll_no==z)
		{
			s[i].display_data();
		}
	}
return 0;		
}

