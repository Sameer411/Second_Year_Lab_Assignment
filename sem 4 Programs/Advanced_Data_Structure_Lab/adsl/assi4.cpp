#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *left,*right;
};

class BST
{
	
	public:
		node *root;
		void create();
		void insert();
		void inorder(node*);
		void preorder(node*);
		void postorder(node*);
		int search(int key);
		int minvalue(node*);
		int height(node*);
		BST()
		{
			root=NULL;
		}
};

void BST :: create()
{
	node *curr;
	node *temp;
	char ans;
	do
	{
		curr=new node;
		cout<<"Enter the data you want to insert in the node:"<<endl;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if (root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data < temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if (temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"Do you want to add more nodes(y/n)?"<<endl;
		cin>>ans;
	}while((ans=='y')||(ans=='Y'));

}

void BST :: insert()
{
	node *curr;
	node *temp;
	char ans;
	
	
		curr=new node;
		cout<<"Enter the data you want to insert in the node:"<<endl;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if (root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data < temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if (temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
}

void BST:: inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<(root->data)<<endl;
		inorder(root->right);
	}
}

void BST:: preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<(root->data)<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}

void BST:: postorder(node *root)
{
	if(root!=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		cout<<(root->data)<<endl;
	}
}

int BST :: search(int key)
{
	node *curr;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			cout<<"Key is found!"<<endl;
			break;
		}
		else if(key<curr->data)
		{
			curr=curr->left;
		}
		else if(key>curr->data)
		{
			curr=curr->right;
		}
		else
		{
			cout<<"Key not found!"<<endl;
		}
	}
	
}

int BST :: minvalue(node* root) 
{ 
	node* curr = root; 
	while(curr->left != NULL) 
  	{ 
    	curr = curr->left; 
  	} 
  	return (curr->data); 
}

int BST :: height(node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		if(height (root->right)>height(root->left))
			return (1+ height(root->right));
			return (1+ height(root->left));
	}
}




int main()
{
	int ch,ikey,min,len;
	
	BST b;
	b.create();
	do
	{
		cout<<"The available choices are as follows::"<<endl;
		cout<<"1. To insert a node in binary search tree at appropriate location"<<endl;
		cout<<"2. Display tree in preorder."<<endl;
		cout<<"3. Display tree in inorder."<<endl;
		cout<<"4. Display tree in postorder."<<endl;
		cout<<"5. To search elemen in the tree."<<endl;
		cout<<"6. To find the minimum element in the tree."<<endl;
		cout<<"7. To find number of nodes in the longest path."<<endl;
		
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
	
		switch(ch)
		{
		
			case 1:
				b.insert();
				break;
			
			case 2:
				cout<<"The tree in preorder format is:"<<endl;
				b.preorder(b.root);
				break;
				
			
			case 3:
				cout<<"The tree in inorder format is:"<<endl;
				b.inorder(b.root);
				break;
		
			case 4:
				cout<<"The tree in postorder format is:"<<endl;
				b.postorder(b.root);
				break;
			
			case 5:
				cout<<"Enter the element you want to search"<<endl;
				cin>>ikey;
				b.search(ikey);
				break;
			
			case 6:
				min=b.minvalue(b.root);
				cout<<"The minimum element in the binary search tree is:"<<min<<endl;
				break;
				
			case 7:
				len=b.height(b.root);
				cout<<"Number of nodes in the longest path is :"<<len<<endl;
				break;
			
		}
	}while(ch<8);
	return 0;
}
