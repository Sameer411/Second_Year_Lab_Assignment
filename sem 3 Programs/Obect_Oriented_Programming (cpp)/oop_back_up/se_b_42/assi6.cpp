#include<iostream>
#include<string.h>
using namespace std;

class publication
{
	protected:
		char title[20];
		float price;

	public:
		virtual void getdata()=0;
		virtual void display()=0;
};

class book:public publication
{

	protected:
		int page;

	public:
		void getdata();
		void display();
};

class tape:public publication
{
	protected:
		int time;
	public:
		void getdata();
		void display();
};

void book::getdata()
{
	cout<<"Enter title: "<<endl;
	cin.ignore();
	cin.getline(title,15);
	try
	{	
			cout<<"Enter price: "<<endl;
			cin>>price;
			if(price>500)
				throw(price);
	}
	catch(float)
	{
		cout<<"Exception Caught"<<endl;
		price=0;
		strcpy(title,"NULL");
		page=0;
		return;
	}
	cout<<"No of pages: "<<endl;
	cin>>page;
}

void tape::getdata()
{
	cout<<"Enter title: "<<endl;
	cin.ignore();
	cin.getline(title,100);
	cout<<"Enter price: "<<endl;
	cin>>price;
	try
	{	
			cout<<"Time(in minutes): "<<endl;
			cin>>time;
			if(time>600)
				throw(time);
	}
	catch(...)
	{
		cout<<"Exception Caught"<<endl;
		price=0;
		strcpy(title,"NULL");
		time=0;
		return;
	}
}

void book::display()
{
	cout<<"\t\t\n***BOOK***"<<endl;
	cout<<"\t\tTitle:"<<title<<endl;
	cout<<"\t\tPrice:"<<price<<endl;
	cout<<"\t\tPages:"<<page<<endl;
}

void tape::display()
{
	cout<<"\t\t\n***TAPE***"<<endl;
	cout<<"\t\tTitle: "<<title<<endl;
	cout<<"\t\tPrice: "<<price<<endl;
	cout<<"\t\tTime: "<<time<<endl;
}

int main()
{
	publication *p[10];
	int i=0,choice,j;
	do{
		cout<<"1.Book\n2.Tape\n3.Display\n4.exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				p[i]=new book;
				p[i]->getdata();
				i++;
				break;
			case 2:
				p[i]=new tape;
				p[i]->getdata();
				i++;
				break;
			case 3:
				for(j=0;j<i;j++)
					p[j]->display();
		}
	}while(choice!=4);
	return 0;
}

