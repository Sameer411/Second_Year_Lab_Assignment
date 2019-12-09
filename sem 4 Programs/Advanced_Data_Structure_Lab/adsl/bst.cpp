#include<iostream>
#include<string.h>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};

class bst
{
	public:
		node *root;
		bst()
		{
			root=NULL;
		}
		void create(int a);				//THE TREE WILL BE CREATED
		void inorder(node *);				//TREE WILL BE PRINTED IN INORDER
		void preorder(node *);				//TREE WILL BE PRINTED IN PREORDER
		void postorder(node *);				//TREE WILL BE PRINTED IN POSTORDER
		int search(int);				//AN ELEMENT FROM THE TREE WILL BE SEARCH
		int height(node *root);				//HEIGHT OF THE TREE WILL BE DISPLAYED
		
};
//---------------------------------------------------------------------------------------------------------------------------------
//					CREATE FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
void bst :: create(int a)
{
	node *curr;
	curr=new node;
	curr->data=a;
	curr->left=NULL;
	curr->right=NULL;
	{
		if(root==NULL)
			root=curr;
		else
		{
			node *temp;
			temp=root;
			while(1)
			{
				if(temp->data > curr->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					
					else
						temp=temp->left;
				}
				
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
						temp=temp->right;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//					INORDER FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
void bst :: inorder(node *curr)
{
	if(curr!=NULL)
	{
		inorder(curr->left);
		cout<<curr->data<<" ";
		inorder(curr->right);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//					PREORDER FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
void bst :: preorder(node *curr)
{
	if(curr!=NULL)
	{
		cout<<curr->data<<" ";
		inorder(curr->left);
		inorder(curr->right);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//					POSTORDER FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
void bst :: postorder(node *curr)
{
	if(curr!=NULL)
	{
		inorder(curr->left);
		inorder(curr->right);
		cout<<curr->data<<" ";
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//					SEARCH FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
int bst :: search(int key)
{
	node *curr;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==key)
			return 1;
		else
		{
			if(key<curr->data)
			{
				curr=curr->left;
			}
			
			else
			{
				curr=curr->right;
			}
		}
	}
	
	return -1;
}
//---------------------------------------------------------------------------------------------------------------------------------
//					HEIGHT FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
int bst :: height(node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		if (height(root->right) > height(root->left))
		{
			return 1+ height(root->right);
		}
		return 1+ height(root->left);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
//					MAIN FUNCTION 
//---------------------------------------------------------------------------------------------------------------------------------
int main()
{
	bst t;							// OBJECT OF CLASS BST
	int ch,data,flag=0,key,ans;
	while(flag==0)
	{
	cout<<"\n***** OPERATIONS ON BST *****\n";		//CHOICES FOR THE OPERATION ON BST
	cout<<"1.CREATE\n2.INORDER DISPLAY\n3.PREORDER DISPLAY\n4.POSTORDER DISPLAY\n5.SEARCH\n6.HEIGHT\n7.EXIT\n";
	cout<<"\nenter your choice :- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter the data: ";
			cin>>data;
			t.create(data);				// CALLING CREATE FUNTION 
			break;
		case 2:
			t.inorder(t.root);			//CALLING INORDER FUNCTION
			break;
		case 3:
			t.preorder(t.root);			//CALLING PREORDER FUNCTION
			break;
		case 4:
			t.postorder(t.root);			//CALLING POSTORDER FUNCTION
			break;
		case 5:
			cout<<"\nEnter the element to be Searched: ";
			cin>>key;
			ans=t.search(key);			//CALLING SEATCH FUNCTION
			if(ans==1)
				cout<<"\nElement found";
			else
				cout<<"\nElement NOT found";
			break;
		case 6:
			cout<<"\n\tThe height of the tree is:"<<"\t"<<t.height(t.root);		//CALLING HEIGHT FUNCTION
			break;
		case 7:
			flag=1;					// EXIT COMMAND
			cout<<"\nThank you for executiong the program\n";
			break;
		default:
			cout<<"\nERROR: no such command found";
	}
	}
	
}

/*
		OUTPUT

sameer_rathod@mmlab-HP-Pro-3330-MT:~/Desktop/adsl$ g++ bst.cpp
sameer_rathod@mmlab-HP-Pro-3330-MT:~/Desktop/adsl$ ./a.out

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 1

Enter the data: 5

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 1

Enter the data: 9

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 1

Enter the data: 4

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 1

Enter the data: 7

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 1

Enter the data: 2

***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 2
2 4 5 7 9 
***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 3
5 2 4 7 9 
***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 4
2 4 7 9 5 
***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 5

Enter the element to be Searched: 6

Element NOT found
***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 6

	The height of the tree is:	3
***** OPERATIONS ON BST *****
1.CREATE
2.INORDER DISPLAY
3.PREORDER DISPLAY
4.POSTORDER DISPLAY
5.SEARCH
6.HEIGHT
7.EXIT
enter your choice :- 7

Thank you for executiong the program
sameer_rathod@mmlab-HP-Pro-3330-MT:~/Desktop/adsl$ 
 
*/
