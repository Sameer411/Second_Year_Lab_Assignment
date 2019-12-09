#include <iostream>
#include <string.h>
#define max 10
using namespace std;

class Node
{
	public:
		long int mobile;
		char name[20];
		Node *next;
};
class HashTable
{
	public:
		Node *head[max];
		HashTable();
		void insert(long int mob,char nm[20]);
		void search(long int key);
		int hash(long int key);
		void display();
};
HashTable::HashTable()
{
	for(int i=0;i<max;i++)
	{
		strcpy(head[i]->name,"");
		head[i]->mobile = 0;
		head[i]->next = NULL;
	}
}
int HashTable::hash(long int key)
{
	return (key%10);
}
void HashTable::insert(long int mob,char nm[20])
{
	int pos = hash(mob);
	if(head[pos]->mobile == 0)
	{
		head[pos]->mobile = mob;
		strcpy(head[pos]->name,nm);
	}
	else
	{
		Node *curr, *temp;
		curr = head[pos];
		temp->mobile = mob;
		strcpy(temp->name,nm);
		temp->next = NULL;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}
void HashTable::search(long int key)
{
	int pos = hash (key);
	if(head[pos]->mobile == key)
	{
		cout<<"Record found!";
	}
	else
	{
		Node *curr;
		curr = head[pos];
		while (curr!= NULL)
		{
			if(curr->mobile == key)
			{
				cout<<"Record found!";
				return;
			}
			curr = curr->next;
		}
		cout<<"Record not found!";
	}
}
void HashTable::display()
{
	Node *curr;
	cout<<"The contents of the hashtable are: \n";
	cout<<"|Sr.no. |\tName\t|\tMobile Number\t|";
	for(int i=0;i<max;i++)
	{
		curr = head[i];
		while(curr!=NULL)
		{
			cout<<"\n|"<<i;
			cout<<"\t|\t"<<head[i]->name;
			cout<<"\t|\t"<<head[i]->mobile<<"\t\t|";
			curr = curr->next;
		}
	}
}
int main()
{
	HashTable h1;
	char nm[20];
	long int key;
	int choice;
	do
	{
		cout<<"\nOptions:\n1. Insert Data\n2. Search\n3. Display\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	
				cout<<"Enter Name: ";
				cin>>nm;
				cout<<"Enter mobile number: ";
				cin>>key;
				h1.insert(key,nm);
			break;
			case 2: 
				cout<<"Enter the phone number that you want to search: ";
				cin>>key;
				h1.search(key);
			break;
			case 3: 
				h1.display();
			break;
		}

	}while(choice<4);
	return 0;
}
