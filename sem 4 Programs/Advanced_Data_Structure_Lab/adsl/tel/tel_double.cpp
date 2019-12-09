#include <iostream>
#include <string.h>
#define max 10
using namespace std;
struct Person
{
	long int mobile;
	char name [40];
	void readData()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter mobile number: ";
		cin>>mobile;
	}
	void putData()
	{
		cout<<"\t|\t"<<name;
		cout<<"\t|\t"<<mobile<<"\t\t|";
	}
};
class HashTable
{
	Person ht[max];
public:
	HashTable();
	int hash (long int key);
	void insert(Person);
	void search(long int key);
	void deleteRecord(long int key);
	void display();
};
HashTable::HashTable()
{
	for (int i=0;i<max;i++)
	{
		ht[i].mobile = 0;
		strcpy(ht[i].name,"");
	}
}
int HashTable::hash(long int key)
{
	return (key%10);
}
void HashTable::insert(Person p)
{
	int pos = hash(p.mobile);
	if(ht[pos].mobile == 0)
		ht[pos] = p;
	else
	{
		for(int i=0;i%max!=pos;i++)
		{
			pos = (hash(p.mobile)+(7-p.mobile%7))%10;
			if(ht[pos].mobile == 0)
			{
				ht[pos] = p;
				return;
			}
		}
		cout<<"The hashtable is full!";
	}
}
void HashTable::search(long int key)
{
	int pos = hash(key);
	if(ht[pos].mobile == key)
	{
		cout<<"Record found!";
		cout<<"|Sr.no. |\tName\t|\tMobile Number\t|";
		cout<<"\n|"<<pos;
		ht[pos].putData();
	}
	else
	{
		for(int i=0;i%max!=pos;i++)
		{
			pos = (hash(key)+(7-key%7))%10;
			if(ht[pos].mobile == key)
			{
				cout<<"Record found!";
				cout<<"|Sr.no. |\tName\t|\tMobile Number\t|";
				cout<<"\n|"<<pos;
				ht[pos].putData();
				return;
			}
		}
		cout<<"Record not found!";
	}
}
void HashTable::deleteRecord(long int key)
{
	int pos = hash(key);
	if(ht[pos].mobile == key)
	{
		ht[pos].mobile = 0;
		strcpy(ht[pos].name,"");
		cout<<"Record deleted successfully!";
	}
	else
	{
		for(int i=0;i%max!=pos;i++)
		{
			pos = (hash(key)+(7-key%7))%10;
			if(ht[pos].mobile == key)
			{
				ht[pos].mobile = 0;
				strcpy(ht[pos].name,"");
				cout<<"Record deleted successfully!";
				return;
			}
		}
		cout<<"Record not found!";
	}
}
void HashTable::display()
{
	cout<<"The contents of the hashtable are: \n";
	cout<<"|Sr.no. |\tName\t|\tMobile Number\t|";
	for(int i=0;i<max;i++)
	{
		cout<<"\n|"<<i;
		ht[i].putData();
	}
}
int main()
{
	HashTable h;
	Person p;
	long int key;
	int choice;
	do
	{
		cout<<"\nOptions:\n1. Insert Data\n2. Search\n3. Delete\n4. Display\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	p.readData();
					h.insert(p);
					break;
			case 2: cout<<"Enter the phone number that you want to search: ";
					cin>>key;
					h.search(key);
					break;
			case 3: cout<<"Enter the phone number of the person whose record you want to delete: ";
					cin>>key;
					h.deleteRecord(key);
					break;
			case 4: h.display();
					break;
		}

	}while(choice<5);
	return 0;
}
