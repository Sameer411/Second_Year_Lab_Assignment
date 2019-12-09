#include<iostream>
#include"stack.h"
#include<cstring>
#include<stdlib.h>
using namespace std;
class node
{
	public:
	char word[30];
	string mean;
	node *left;
	node *right;
};
class Bst
{
	public:
	node *root;
	Bst()
	{
		root==NULL;
	}
	void create();
	void insert();
	void search(node *root,char wd[30]);
	void display();
	void update(node *root,char wr[30]);
};

void Bst::create()
{
	root=new node;
	cout<<"\nEnter the word to be added:	";
	cin>>root->word;
	cout<<"\nEnter the meaning of the word:	";
	cin.ignore();
	getline(cin,root->mean);
	root->left=NULL;
	root->left=NULL;
}
void Bst::insert()
{
	node *p,*temp;
	p=new node;
	cout<<"\nEnter the word to be added:	";
	cin>>p->word;
	cout<<"\nEnter the meaning of the word:	";
	cin.ignore();
	getline(cin,p->mean);
	p->left=NULL;
	p->right=NULL;
	temp=root;
	while(temp!=NULL)
	{
		if(strcmp(p->word,temp->word)>0)
		{
			if(temp->right==NULL)
			{
				temp->right=p;
				break;
			}
			else
				temp=temp->right;
		}
		else if(strcmp(p->word,temp->word)<0)
		{
			if(temp->left==NULL)
			{
				temp->left=p;
				break;
			}		
			else
			temp=temp->left;
			
		}
		else
			cout<<"\nElement already present";
	}
	
}

void Bst::search(node *root,char wd[30])
{
	node *temp=root;
	int flag=0;
	
	if(strcmp(wd,temp->word)==0)
		{
			cout<<"\nword found ";
			cout<<"\nMeaning is :  ";
			cout<<temp->mean;
			flag=1;
		}
	else if(strcmp(wd,temp->word)<0)
		
			return search(temp->left,wd);
		
	else 
			return search(temp->right,wd);
	if(flag==0)
		cout <<"\nNot found";
}
void Bst::update(node *root,char wr[30])
{
	node *temp=root;
	string m;
	int flag=0;
	char ans;
	
	if(strcmp(wr,temp->word)==0)
		{
			cout<<"\nWord found	";
			cout<<"\nPrevious meaning was:	";
			cout<<temp->mean;
			cout<<"\n\nEnter the new meaning:	";
			cin.ignore();
			getline(cin,m);
			temp->mean=m;
			flag=1;
		}
	else if(strcmp(wr,temp->word)<0)
		
			return update(temp->left,wr);
		
	else 
			return update(temp->right,wr);
	if(flag==0)
		cout <<"\nNot found";
}

int main()
{
	Bst b;
	int chi,h;
	char wd[30],wr[30];
	do
	{
	cout<<"\n1.Create:";
	cout<<"\n2.insert:";
	cout<<"\n3.Search:";
	cout<<"\n4.Update:";
	cout<<"\n5.Exit";
	cout<<"\nEnter the choice:";
	cin>>chi;
	switch(chi)
	{
		case 1:								//create
			b.create();
			cout<<"\nBst created:	";
			break;
		case 2:								//insert
			b.insert();
			cout<<"\nElement inserted:	";
			break;
		case 3:								//search
			cout<<"\nEnter the element to be searched	:";
			cin>>wd;
			b.search(b.root,wd);	
			break;
		case 4:								//update
			cout<<"\nEnter the word to be updated:	";
			cin>>wr;
			b.update(b.root,wr);
			break;
		
	}		
	}while(chi<5);

}
