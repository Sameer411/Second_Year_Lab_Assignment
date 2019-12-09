#include<iostream>
using namespace std;
#define size 5

class JobQue
{
	private:
		struct queue
		{
			int que[size];
			int front;
			int rear;
		}Q;
	public:
		JobQue();				//Constructor
		bool Qfull();
		int insert(int);
		bool Qempty();
		int Delete();
		void display();
};

JobQue::JobQue()					//Initializing the Job Queue
{
	Q.front=-1;
	Q.rear=-1;
}

bool JobQue::Qfull()
{
	if(Q.rear>=size-1)
		return true;
	else
		return false;
}

int JobQue::insert(int item)
{
	if(Q.front==-1)
		Q.front++;
	Q.que[++Q.rear]=item;
		return Q.rear;
}

bool JobQue::Qempty()
{
	if((Q.front==-1)||(Q.front>Q.rear))
		return true;
		
	else
		return false;
}

int JobQue::Delete()
{
	int item;
	item=Q.que[Q.front];
	Q.front++;
	
		cout<<"\n The deleted job is:"<<item;
			return Q.front;
}

void JobQue::display()
{
	int i;
	for(i=Q.front;i<=Q.rear;i++)
	cout<<" "<<Q.que[i];
}

int main()
{
	int ch,item;
	char ans;
	JobQue J;
	do
	{
		cout<<"\n Main Menu:";
		cout<<"\n 1.ADD Job\n 2.Delete Job\n 3.Display Job Queue:";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				if(J.Qfull())		//Queue Overflow
				cout<<"\n Can not insert the job";
					
				else
				{
					cout<<"\n Enter the Job number:";
					cin>>item;
					J.insert(item);
				}
					break;
						
			case 2:	
				if(J.Qempty())		//Queue Underflow
				cout<<"\n Queue Underflow:";
					
				else 
					J.Delete();
					break;
						
			case 3:
				if(J.Qempty())
				cout<<"\n Job Queue is Empty:";
					
				else
					J.display();
					break;
					
			case 4: 
				cout<<"\n Wrong Choice:";
				break;
		}
				cout<<"\n Do you want to continue?:";
				cin>>ans;
	}while(ans=='Y'||ans=='y');
}					
