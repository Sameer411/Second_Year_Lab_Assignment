#include <iostream>
#include <string.h>
using namespace std;
class Node
{
	public:
	char data[20];
	Node *left, *right;
};
class BST
{
	public: 
	Node *root;
	BST()
	{
		root = NULL;
	}
	void create();
	void insert(char key[20]);
	void inorder(Node *root);
	int search(char key[20]);
	void descending(Node *root);
	void modify(Node *root,char key[20],char mod[20]);
	Node *minValueNode(Node* root); 
	Node *deleteNode(Node* root, char key[20]);
};
void BST::create()
{
	Node *curr;
	Node *temp;
	char cho;
	do
	{
		curr = new Node;
		cout<<"Enter the word: ";
		cin>>curr->data;
		curr->right = NULL;
		curr->left = NULL;
		if(root == NULL)
		{
			root = curr;
		}
		else
		{
			temp = root;
			while(1)
			{
				if(strcmp(curr->data,temp->data)<0)
				{
					if(temp->left==NULL)
					{
						temp->left = curr;
						break;
					}
					else
						temp = temp->left;
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right = curr;
						break;
					}
					else
						temp = temp->right;					
				}
			}
		}
		cout<<"Do you want to continue?: ";
		cin>>cho;
	}while(cho=='y'||cho=='Y');
}
void BST::insert(char key[20])
{
	Node *curr;
	curr = new Node;
	Node *temp;
	strcpy(curr->data,key);
	curr->right = NULL;
	curr->left = NULL;
	if(root == NULL)
	{
		root = curr;
	}
	else
	{
		temp = root;
		while(1)
		{
			if(strcmp(curr->data,temp->data)<0)
			{
				if(temp->left==NULL)
				{
					temp->left = curr;
					break;
				}
				else
					temp = temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right = curr;
					break;
				}
				else
					temp = temp->right;					
			}
		}
	}
}
int BST::search(char key[20])
{
	Node *curr;
	curr = root;
	int cnt=0;
	while(curr!=NULL)
	{
		cnt++;
		if(strcmp(curr->data,key)==0)
		{
			cout<<"Word found! (Comparisons = "<<cnt<<")";
			return 1;
		}
		else
		{
			if(strcmp(key,curr->data)<0)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	if (curr == NULL)
	{
		cout<<"The word is not present in the dictionary! (Comparisons = "<<cnt<<")";
		return 0;
	}
}
Node * BST::minValueNode(Node* root) 
{ 
    Node* curr = root; 
    while (curr->left != NULL) 
        curr = curr->left; 
    return curr; 
} 
Node* BST::deleteNode(Node* root, char key[20]) 
{
	if (root == NULL)
		return root;
	if (strcmp(key,root->data)<0)
		root->left = deleteNode(root->left, key);
	else if (strcmp(key,root->data)>0)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			delete(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		strcpy(root->data,temp->data);
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
void BST::modify(Node *root, char key[20], char mod[20])
{
	/*Node *curr;
	Node *temp;
	Node *curr1;
	curr = root;
	//s = root;
	while(curr!=NULL)
	{
		if(strcmp(curr->data,key)==0)
		{
			strcpy(curr->data,mod);
			insert(curr);
			return;
		}
		else
		{
			if(strcmp(key,curr->data)<0)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
	}
	if (curr == NULL)
	{
		cout<<"The word is not present in the dictionary!";
	}*/
	deleteNode(root,key);
	insert(mod);
}
void BST::inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<", ";
		inorder(root->right);
	}
}
void BST::descending(Node *root)
{
	if(root!=NULL)
	{
		descending(root->right);
		cout<<root->data<<", ";
		descending(root->left);
	}
}
int main()
{
	BST b;
	int ch;
	char key[20],mod[20];
	b.create();
	do
	{
		cout<<"\nOPTIONS:";
		cout<<"\n1.Insert node\n2.Search\n3.Ascending Order\n4.Descending Order\n5.Modify\n6.Delete";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the word: ";
					cin>>key;
					b.insert(key);
					break;
			
			case 2: cout<<"Enter the key you want to search: ";
					cin>>key;
					b.search(key);
					break;

			case 3: cout<<"Words arranged alphabetically: ";
					b.inorder(b.root);
					cout<<"\b\b  ";
					break;

			case 4: cout<<"Words arranged in descending order: ";
					b.descending(b.root);
					cout<<"\b\b  ";
					break;

			case 5: cout<<"Enter the word you want to modify: ";
					cin>>key;
					cout<<"Enter the word with which you want to replace "<<key<<": ";
					cin>>mod;
					//b.deleteNode(b.root,key);
					b.modify(b.root,key,mod);
					cout<<"Modification successful!\nThe words in the dictionary are: \n";
					b.inorder(b.root);
					cout<<"\b\b  ";
					break;

			case 6: cout<<"Enter the word you want to delete: ";
					cin>>key;
					b.deleteNode(b.root,key);
					cout<<"Deletion successful!\nThe words in the dictionary are: \n";
					b.inorder(b.root);
					cout<<"\b\b  ";
					break;
		}
	}while(ch<7);
}
