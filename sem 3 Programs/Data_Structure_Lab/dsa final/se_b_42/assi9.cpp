#include<iostream>

using namespace std;

#define MAXSIZE 50

class Stck 
{
	private:
	int top;
	int stak[MAXSIZE];
	
	public:
	
	Stck()
	{
		top=-1;
	}

	Stck(int n)
	{
		top=-1;
	}

	int push(int n)
	{
		if(top<MAXSIZE)
			return stak[++top]=n;
		else
			cout<<"\nStack is full....";
	}

	int pop()
	{
		if(top!=-1)
			return stak[top--];
		else
		{
			cout<<"\nStack is Empty";
			return -1;
		}
	}

	int isEmpty()
	{
		if(top==-1)
		{
			return 1;
			cout<<"\nStack is Empty";
		}
		else
			return 0;
	}

	int isFull()
	{
		if(top!=MAXSIZE-1)
		{
			return 1;
			cout<<"\nStack is full";
		}
		else
			return 0;
	}

	void show()
	{
		cout<<"\nStack has:\n\n";
		for(int i=0;i<=top;i++)
		{
			cout<<"      "<<stak[i];
		}
	}	
};

int main()
{
	int n,r,i;
	cout<<"\nEnter the no of elements to be pushed on stack:";
	cin>>n;
	Stck s1;

	for(i=0;i<n;i++)
	{
		s1.push(i+1);
	}

	cout<<"\n\n";
	s1.show();
	cout<<"\n\nEnter the no of elements to be popped:";
	cin>>r;

	for(i=0;i<r;i++)
	{
		cout<<"\n"<<s1.pop()<<"........popped";
	}
}
