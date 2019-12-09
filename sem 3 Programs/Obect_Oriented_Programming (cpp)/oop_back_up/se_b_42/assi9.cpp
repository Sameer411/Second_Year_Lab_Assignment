#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;
class teldir
{
	public:
	char name[50];
	long int no;

		void getdata();
		void putdata();
};
void teldir::getdata()
{
	cout<<"\nEnter the name of person:";
	//cin.getline(name,50);
	cin>>name;
	cout<<"\nEnter the telephone number:";
	cin>>no;
}
void teldir::putdata()
{
	cout<<"\nName of person is :"<<name;
	cout<<"\nTelephone no. is:"<<no;
}
int main()
{
	int n,flag=0;
	long int newtel;
	fstream file;
	file.open("telephone.text",ios::app);
	teldir tel;
	cout<<"\nEnter the no. of records:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tel.getdata();
		file.write((char*)&tel,sizeof(tel));
	}
	file.close();			
	file.open("telephone.text",ios::in);
	teldir te;
	while(file.read((char*)&te,sizeof(te)))
	{
		te.putdata();
	}
	file.close();			
	file.open("telephone.text",ios::in);
	teldir telp;
	cout<<"\nEnter the telephone no. to be search:";
	cin>>newtel;
	while(file.read((char*)&telp,sizeof(telp)))
	{
		if(telp.no==newtel)
		{
			flag=1;
			telp.putdata();
		}					
	}
	if(flag==0)
	{
		cout<<"\nTelephone no. is not found\n";
	}
	else
	{
		cout<<"\nTelephone no.is found\n";
	}
	file.close();			
	return 0;
}
