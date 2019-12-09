#include <iostream>
#include <stack>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
class tree
{
public:
	node* root;
	tree()
	{
		root=NULL;
	}
	void create();
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
	void nr_preorder();
	void nr_inorder();
};
void tree :: nr_inorder()
{
	node *temp = root;
		stack<node*> s;
	
	
	while(temp!=NULL || !s.empty())
	{
		if(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		else{
			temp=s.top();
		s.pop();
		cout<<temp->data<<"\t";
		temp=temp->right;
		}
		
	}
}
void tree :: nr_preorder()
{
	node* temp;
	temp=root;
	stack<node*> s;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			s.push(temp);
			temp=temp->left;
		}
		if(s.empty())
			return;
		temp=s.top();
		s.pop();
		temp=temp->right;	
	}
}
void tree :: create()
{
	int direction;
	node* curr;
	node *temp;
	
		curr=new node;
		cout<<"Enter the data : ";
		cin>>curr->data;
		curr->right=curr->left=NULL;
		if(root==NULL)
		{
			cout<<"Root node created"<<endl;
			root=curr;
		}
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				cout<<"Enter the direction"<<endl;
				cin>>direction;
				if(direction==1)
				{
					cout<<"Heading left"<<endl;
					if(temp->left==NULL)
					{
						temp->left=curr;
						return;
					}
					else
						temp=temp->left;
				}
				else if(direction==2)
				{
					cout<<"Heading right"<<endl;
					if(temp->right==NULL)
					{
						temp->right=curr;
						return;
					}
					else
						temp=temp->right;
				
				}	
			}
			
		}			
	
}
void tree :: inorder(node* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<"\t";
		inorder(temp->right);
	}
	
}
void tree :: preorder(node* temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		preorder(temp->left);
		preorder(temp->right);
	}
	
}
void tree :: postorder(node* temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<"\t";
	}
	
}
int main()	
{
	tree t1;
	cout<<"Enter the number of nodes"<<endl;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
	
		t1.create();
	}
    cout<<"\n Inorder traversal"<<endl;
	t1.inorder(t1.root);
	cout<<"\n Non recurrsive Inorder traversal"<<endl;
	t1.nr_inorder();
	cout<<"\n Preorder traversal"<<endl;
	t1.preorder(t1.root);
	cout<<"\n Non recurrsive Preorder traversal"<<endl;
	t1.nr_preorder();
	cout<<"\n Postorder traversal"<<endl;
	t1.postorder(t1.root);
	return 0;
}
