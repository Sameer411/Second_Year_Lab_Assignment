#include<iostream>
using namespace std;
class pizza
{
	int front,rear,prize,q[5];
	public:
		pizza()
		{
			front=-1;
			rear=-1;
                }
                int isfull()
                {
			if((front==0&&rear==4)||front==rear+1)
                        {
				return 1;
                        }
                        else
			{
				return 0;
                        }
                }      
                int isempty()
                {
                        if(front==-1&&rear==-1)
                        {
				return 1;
                        }
                        else
                        {
   	                        return 0;
                        }
                }
                void add()
                {
  	                if(isfull()==0)
  	                {
  	 	                cout<<"\n Enter the Pizza ID: ";
  	 	                if(front==-1&&rear==-1)
  	 	                {
  	  		                front=0;
  	  		                rear=0;
  	  		                cin>>q[rear];
  	 	                }
  	 	                else
  	 	                {
  	   		                rear=(rear+1)%5;
  	   		                cin>>q[rear];
  	 	                }
   		                char c;
 		                cout<<" Do you want to add another order ? ";
   		                cin>>c;
   		                if(c=='y'||c=='Y')
  	 	                add();
  	                }
  	                else
  	                {
  	 	                cout<<"\n Orders are full ";
  	                }
  	                int h=0;
  	                for( h=0;h!=q[front];h++)
  	                {
	  			prize=q[h]*100;
  		        }
  			cout<<"your bill is:\n"<<prize<<"\n";
                }
                void serve()
                {
  	                if(isempty()==0)
  	                {
  	 	                if(front==rear)
  	 	                {
  	 	 	                cout<<"\n Order served is : "<<q[front];
  	 	 	                front=-1;
  	 	 	                rear=-1;
  	 	                }
  	 	                else
  	 	                {
  	 	 	                cout<<"\n Order served is : "<<q[front];
  	 	 	                front=(front+1)%5;
  	 	                }
  	                }
  	                else
  	                {
  	 	                cout<<"\n All orders are served ";
  	                }
                }
                void menu()
                {
                        cout<<"\n\nPIZZA PARLOUR !\n\n";     
                        
                        cout<<"\nFollowing pizza's are available now\n";
        		
        		cout<<"\n"<<"sr. no.\t\t"<<"pizza name\t\t"<<"pizza ID NO.\t\t"<<"\n\n";
        		
        		cout<<"i)\t\t"<<"margherita\t\t"<<"1"<<"\n";
        		
        		cout<<"ii)\t\t"<<"customised\t\t"<<"2"<<"\n";
        		
        		cout<<"iii)\t\t"<<"onion pizza\t\t"<<"3"<<"\n";
        		
        		cout<<"iv)\t\t"<<"peppy_paneer\t\t"<<"4"<<"\n";
        		
        		cout<<"v)\t\t"<<"mexican green wave\t"<<"5"<<"\n";
       	
                }
                void display()
                {
  	                if(isempty()==0)
  	                {
  	                        for(int i=front;i!=rear;i=(i+1)%5)
  	                        {
  	  	                        cout<<q[i]/*<<" <- "*/;
  	                        }
  	 	                cout<<q[rear];
  	                }
  	                else
  	                {
 	 	                cout<<"\nAll orders are served";	
 	                }
                }
                void check()
                {
                        int ch;   
                        cout<<"\n 1. Add a Pizza in Queue \n 2. Display the Orders \n 3. Serve a pizza \n Enter your choice : \n";
                        cin>>ch;
                        switch(ch)
                        {             
                                case 1:
                                        add();
                                break;
   
                                case 2:
                                        display();
                                break;
   
                                case 3:
                                        serve();
                                break;
                          
                                default:
                                        cout<<" Invalid choice ";
                                        check();
                                break;
                                
                        }
                        char ch1;
                        cout<<"\n Do you want to continue? ";
                        cin>>ch1;
                        if(ch1=='y'||ch1=='Y')
                        check();
               }
}; 
int main() 
{
        pizza p1;
        p1.menu();
        p1.check();
        return 0;
}
