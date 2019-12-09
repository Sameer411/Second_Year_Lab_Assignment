#include<iostream>
#include<stdlib.h>
using namespace std;

class TBTNode
{
	public:
		int data;
		TBTNode *left,*right;
		int lthread,rthread;
};

class TBT
{
	private:
	TBTNode *root,*head;
	public:
		TBT()
		{
			head=new TBTNode;
			head->left=head;
			head->right=head;
			head->lthread=1;
			head->rthread=0;
			root=NULL;
		}
		
		void create();
		void inorder();
		TBTNode* inordersucc(TBTNode*);
		void preorder();
};

void TBT:: create()
{
	TBTNode *temp,*curr;
	char ich;
	char ch;
	do
	{
		curr=new TBTNode;
		cout<<"Enter the data in the node:"<<endl;
		cin>>curr->data;
		curr->lthread=1;
		curr->rthread=1;
		if(root==NULL)
		{
			root=curr;
			root->left=head;
			root->right=head;
			head->left=root;
			head->lthread=0;
		}
		else
		{
			temp=root;
			while(1)
			{
				if((curr->data)<(temp->data))
				{
					if(temp->lthread==1)
					{
						curr->left=temp->left;
						temp->left=curr;
						temp->lthread=0;
						curr->right=temp;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->rthread=1)
					{
						curr->right=temp->right;
						temp->right=curr;
						temp->rthread=0;
						curr->left=temp;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"\n Do you want to add more?"<<endl;
		cin>>ich;
	}while(ich=='Y' || ich=='y');
}


void TBT :: preorder()
{
	TBTNode *temp;
	int flag;
	temp=root;
	while(temp!=head)
	{
		if(flag==0)
			cout<<temp->data<<endl;
			
		if((temp->lthread==0) && (flag==0))
		{
			temp=temp->left;
		}
		else
		{
			if(temp->rthread==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		}
	}
}


TBTNode* TBT :: inordersucc(TBTNode *curr)
{
	TBTNode *temp;
	temp=curr->right;
	if(!curr->rthread)
	{
		while(!temp->lthread)
		{
			temp=temp->left;
		}
	}
	return temp;
}

void TBT :: inorder()
{
	TBTNode *temp;
	temp=head;
	do
	{
		temp=inordersucc(temp);
		if(temp!=head)
		{
			cout<<temp->data<<endl;
		}
	}while(temp!=head);
}


int main()
{
	int ch;
	
	TBT t;
	t.create();
	do
	{
		cout<<"The available choices are as follows::"<<endl;
		cout<<"1. To display in inorder."<<endl;
		cout<<"2. To display in preorder."<<endl;
		cout<<"3. Exit."<<endl;
		
		
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
	
		switch(ch)
		{
		
			case 1:
					t.inorder();
					break;
			case 2:
					t.preorder();
					break;
				
			case 3:
					exit(0);
					break;
				
		}
	}while(ch<5);
	return 0;
}
