#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{
public:
	int rno;
	int n, ch, flag, recno;
	char nm[20],name[20],addr[20],div;
	void read();
	void display();
	void formatting();
	void insert();
	void show();
	void search();
	void modify();
	void removerec();
	void disprec();
};
void Student::read()
{
	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter Roll Number: ";
	cin>>rno;
	cout<<"Enter Division: ";
	cin>>div;
	cout<<"Enter address: ";
	cin>>addr;
}
void Student::display()
{
	cout<<"\n| \t"<<rno<<"\t\t|\t"<<name <<"\t\t| \t"<<div<<"\t\t| \t"<<addr<<"\t\t|";
}
void Student::formatting()
{
	cout<<"\t\t\t\t\tStudent Directory";
	cout<<"\n";
	cout<<"\n|\tR.No. \t\t| \tName \t\t| \tDivision \t| \tAddress \t|";
}
void Student::insert()
{	
	Student t;
	fstream file;
	file.open("Student.txt", ios::app|ios::out);
	cout<<"Enter the total number of records you want to enter: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		t.read();
		file.write((char *)&t, sizeof(t));
	}
	file.close();
}
void Student::show()
{	
	Student t;
	fstream file;
	t.formatting();
	file.open("Student.txt", ios::in|ios::out);
	while(file.read((char *)&t,sizeof(t)))
		t.display();
	file.close();
}
void Student::search()
{
	Student t;
	fstream file;
	flag=0;
	cout<<"Enter the name you want to find: ";
	cin>>nm;
	flag=0;
	t.formatting();
	file.open("Student.txt", ios::in|ios::out);
	while(file.read((char *)&t,sizeof(t)))
	{
		if(strcmp(t.name,nm)==0)
		{
			flag=1;
			t.display();
			break;
		}
	}
	file.close();
	if(flag==0)
		cout<<"\n|\t\tRecord not found\t\t|";
	cout<<"\n+-----------------------------------------------------------------------------------------------+\n";
}
void Student::modify()
{
	Student t;
	fstream file;
	flag=0;
	cout<<"Enter the name whose entry you want to modify: ";
	cin>>nm;	
	flag=0;
	file.open("Student.txt", ios::in|ios::out);
	while(file.read((char *)&t,sizeof(t)))
	{
		if(strcmp(t.name,nm)==0)
		{
			flag=1;
			cout<<"Record found\nEnter modified information"<<endl;
			Student tp;
			tp.read();
			file.seekp(-1*(sizeof(t)),ios::cur);
			file.write((char *)&tp, sizeof(t));
			break;
		}
	}
	file.close();
	if(flag==0)
		cout<<"Record not found";
}
void Student::removerec()
{
	Student t;
	fstream file;
	flag=0;
	cout<<"Enter the name whose entry you want to delete: ";
	cin>>nm;
	fstream tfile;
	file.open("Student.txt",ios::in|ios::out);
	while(file.read((char *)&t,sizeof(t)))
	{
		if(strcmp(t.name,nm)==0)
		{
			flag=1;
			break;
		}
	}
	file.close();
	if(flag==0)
		cout<<"Record not found\n";
	
	else
	{
		tfile.open("Temp.txt",ios::out);
		file.open("Student.txt",ios::in);
		while(file.read((char *)&t,sizeof(t)))
		{
			if(strcmp(t.name,nm)!=0)
			{
				tfile.write((char *)&t,sizeof(t));
			}
		}
		file.close();
		tfile.close();
		remove("Student.txt");
		rename("Temp.txt","Student.txt");
		cout<<"Record deleted successfully\n";
	}
}

void Student::disprec()
{
	Student t;
	fstream file;
	flag=0;
	cout<<"Enter the record number you want to display: ";
	cin>>recno;
	file.open("Student.txt", ios::in|ios::out);
	if(file.eof())
		file.clear();
	file.seekp((recno-1)*(sizeof(t)));
	file.read((char *)&t,sizeof(t));
	t.formatting();
	t.display();
	cout<<"\n+-----------------------------------------------------------------------------------------------+\n";
	file.close();
	if(flag==0)
		cout<<"Record not found";
}
int main()
{
	int ch;
	char c;
	cout<<"Options: \n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Delete\n6.Display Specific Record\n";
	Student t;
	do
	{
	cout<<"\nEnter choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:	t.insert();
			break;
		case 2: t.show();
			break;
		case 3: t.search();
			break;
		case 4: t.modify();
			break;
		case 5: t.removerec();
			break;
		case 6: t.disprec();
			break;
	}
	cout<<"If you wan to continue press 'y', if not then press 'n': ";
	cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
