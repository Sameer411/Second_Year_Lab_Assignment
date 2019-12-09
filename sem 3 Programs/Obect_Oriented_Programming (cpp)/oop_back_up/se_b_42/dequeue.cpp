#include<iostream>
#include<dequeue>
using namespace std;

int main()
{
	int c,m;
	dequeue<int > dq;
	dequeue<int > :: iterator it;
	do
	{
		cout<<"1.Push_front\n2.Push_back\n3.Pop_front\n4.Pop_back\n5.Get_front\n6.Get_back\n7.Display\n8.size\n9.Exit\n \nEnter your choice\n";
		cin>>c;
		switch (c)
		{
			case 1:
				cout<<"enter the element to add from front\n";
				cin>>m;
				dq.push_front(m);
			break;
			
			case 2:
				cout<<"enter the element to add from back\n";
				cin>>m;
				dq.push_back(m);
			break;
			
			case 3:
				dq.push_front();
			break;
			
			case 4:
				dq.push_back();
			break;
			
			case 5:
				cout<<"first elemen at the front is\n"<<dq.front<<"\n";
			break;
			
			case 6:
				cout<<"last element in the dequeue is\n"<<dq.back<<"\n";
			break;
			
			case 7:
				cout<<"\n";
				for(it=d.begin();it!=d.end();it++)
				{
					cout<<"\t"<<*it<<"\t";
				}
			break;
			
			case 8:
				cout<<"size of the deque is\n"<<dq.size()<<"\n";
			break;
			
			default:
				cout<<"you have selected wrong choice\n";
			break;
		}
	}while(ch!=9);
}
