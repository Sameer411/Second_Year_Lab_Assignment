#include<iostream>
#include<stack>
#include<cstring>
using namespace std;


class node
{	
	public:
		char data;
		node *l,*r;
};
class expt
{
	public:
		node *root;
		expt()
		{
			root=NULL;
		}
		void exp();
		void inorder(node*);
		void nonInorder(node*);
		void nonPost(node*);
		void nonPre(node*);
		//void swap(node*);
};
void expt::exp()
{	
	stack<node *>s;
	char pf[100],ch;
	node *curr,*t1,*t2;
	cout<<"\nEnter the postfix expression : ";
	cin>>pf;
	int i=0;
	while(pf[i]!='\0')
	{
		ch=pf[i];
		curr=new node;
		curr->data=ch;
		curr->l=NULL;
		curr->r=NULL;
		if(ch>='a' && ch<='z')
		{
			s.push(curr);
		}
		else
		{
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			curr->l=t2;
			curr->r=t1;
			s.push(curr);
		}
		i++;
	}
	root=s.top();
	s.pop();
	
}
void expt::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		cout<<" ";
		cout<<root->data;
		inorder(root->r);
	}
	
}
void expt::nonInorder(node *root)
{
	node *curr;
	stack<node *>s;
	curr=root;
	do
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->l;
		}
		if(!s.empty())
		{
			
			curr=s.top();
			s.pop();
			cout<<" ";
			cout<<curr->data;
			curr=curr->r;
		}
		else
		{
			break;
		}
	}while(1);
}	
void expt::nonPost(node *root)
{	
	stack<node *>s1;
	stack<char>s2;
	
	char ra;
	node *curr=root;
	do
	{
		while(curr!=NULL)
		{
			s1.push(curr);
			s2.push('l');
			curr=curr->l;
		}
		if(!s1.empty())
		{
			curr=s1.top();
			s1.pop();
			ra=s2.top();
			s2.pop();
		
			if(ra=='l')
			{
				s1.push(curr);
				s2.push('r');
				curr=curr->r;
			}
			else
			{
				cout<<curr->data;
				curr=NULL;
			}
		}
		else
		{
			break;
		}
	}while(1);
}
void expt::nonPre(node *root)
{	
	node *curr;
	stack<node *>s;
	curr=root;
	do
	{
		while(curr!=NULL)
		{	
			
			cout<<curr->data;
			s.push(curr);
			curr=curr->l;
		}
		if(!s.empty())
		{
			
			curr=s.top();
			s.pop();
			
			curr=curr->r;
		}
		else
		{
			break;
		}
	}while(1);	
}
/*void expt::swap(node *root)
{
	stack<node *>s3;
	stack<char>s4;
	node *temp;
	char ra;
	node *curr=root;
	do
	{
		while(curr!=NULL)
		{
			s3.push(curr);
			s4.push('l');
			curr=curr->l;
		}
		if(!s3.empty())
		{
			curr=s1.top();
			s3.pop();
			ra=s4.top();
			s4.pop();
		
			if(ra=='l')
			{
				s3.push(curr);
				s4.push('r');
				curr=curr->r;
			}
			else
			{
				
				curr=NULL;
			}
		}
		else
		{
			break;
		}
	}while(1);
}*/	
					
int main()
{	
	expt e;
	int ch;
	do
	{
		cout<<"\n1.Scan Postfix Expression\n2.Recursive inorder transversal\n3.Non-Recursive inorder transversal\n4.Non-Recursive postorder transversal\n5.Non-Recursive preorder transversal\n";
		cout<<"Enter your choice\n";
		cin>>ch;

		switch(ch)
		{	
			case 1:
				e.exp();
				break;
		
			case 2:
				e.inorder(e.root);
				break;
				
			case 3:
				e.nonInorder(e.root);
				break;
				
			case 4:
				e.nonPost(e.root);
				break;
			
			case 5:
				e.nonPre(e.root);
				break;
		}
	}while(ch!=6);
		
	return 0;
}
	



