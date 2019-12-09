#include<iostream>
using namespace std;
int z=0,j;
class node
{
	public:
	char name[50];
	int prn;
	char div;
	node *next;
};
class linklist1
{	
	public:
	node *head,*tail;
	linklist1()
	{
		head=NULL;
		tail=NULL;
	}
	void display()
	{
		node *temp;
		temp=head;
		int j=1;
		while(temp!=NULL)
    		{
    			cout<<"\n\nprn in "<< j << " element "<<temp->prn<<" \n\n";
    			cout<<"Name in "<< j << " element "<<temp->name<<" \n\n";
    			cout<<"Division is" << j <<" element"<<temp->div<<" \n\n";
    			temp=temp->next;
    			j++;
    		}
	}
//cleared
void ins_beg()
{
	node *s;
	node *temp=new node;
	if(head==NULL)
	{
		head=temp;
	  	tail=temp;
	}
	else
    	{ 
		s=head;
		head=temp;
        	head->next=s;
    	}
    	getdata(head);
}
void getdata(node* temp)
{  
	cout<<"Please enter the prn\n"<<endl;
	cin>>temp->prn;
	cout<<"Please enter the name\n"<<endl;
	cin>>temp->name;
	cout<<"Please enter the division\n"<<endl;
	cin>>temp->div;
}
//Insert node
void insertnode()
{
	node *temp=new node;
	if(head==NULL)
	{ 
		head=temp;
		tail=temp;
		tail->next=NULL;
	}
	else
	{	
		tail->next = temp;
        	tail = tail->next;
        	tail->next=NULL;
	}
	getdata(tail);
}
void insert_bet()
{   
	int prno;
	node *new1 = new node;
	node * temp;
	node *prev;
	node *foreward;
	getdata(new1);
	cout<<"enter the prn of the student after which you want to insert this student\n";
	cin>>prno;
	temp=head;
   	do
	{
		temp=temp->next;
		prev=temp;
	}
	while (temp->prn!=prno);
	temp=temp->next;
	foreward=temp;
	prev->next=new1;
	new1->next=foreward;
}
void fun_del()
{   
	int prno;
	node *temp;
	node *prev;
	temp=head;
	cout<<"Enter the prn no of the student which you want to delete\n";
	cin>>prno;
	do
  	{
		prev=temp;
		temp=temp->next;

    	}
	while (temp->prn!=prno);
	temp=temp->next;
	prev->next=temp;
}
void dis_tot()
{   
	int count=0;
	node *temp;
	temp=head;
	do
    	{  
		count++;
		temp=temp->next;

	}
	while (temp!=NULL);
	cout<<"The total number of members are\n"<<count<<endl;
}
void list_rev(node *temp,int j)
{
	if (z==0)
	{
		temp=head;
		z++;
	}
	if (temp->next!=NULL)
        {
		list_rev (temp->next,j++);
        }
	cout<<"\nprn of "<< j << " element is "<<temp->prn<<" \n";
        cout<<"Name of "<< j << " element is "<<temp->name<<" \n";
        cout<<"Division of" << j <<" element is "<<temp->div<<" \n";
}
};
int main ()
{
	node *temp;
	int first=0;
	int ch,num;
	linklist1 a;
	do
	{
		cout<<"1)Insert student details\n2)Display all the student's detail\n3)Insert student\n4)Delete student\n5)Total number of students\n6)Display elements in reverse"<<endl;
        	cin>>ch;
		switch(ch)
		{
    			case 1:
				cout<<"Please enter the number of students that you want to enter\n";
				cin>>num;
				for (int i=0;i<num;i++)
				{
					if (i==(num-1)&&(num!=1))
					{
						if ((first==1)&&(num!=1))
						cout<<"Please enter the details for the secretary\n";
						a.insertnode();
						first++;
					}
					else if ((i==0)&&(num!=1))
		    			{
						if ((first==0))
		        			cout<<"Please enter the information about the president\n\n";
		       				a.ins_beg();
		    				first++;
		    			}
		    			else if (num==1)
		        		cout<<"\nError : At least two students required\n"<<endl;
		   			else
		   			a.insertnode();
		    		}
            			break;
			case 2:
				a.display();
		    		break;
	    		case 3:
				a.insert_bet();
		  		break;
			case 4:
				a.fun_del();
		   		break;
			case 5:
				a.dis_tot();
		   		break;
			case 6:
				a.list_rev(temp,j);
		   		break;
		}
	}while (ch!=7);
	return 0;
}
