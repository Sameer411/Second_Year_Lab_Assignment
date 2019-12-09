#include<iostream>
using namespace std;
        class complex
        {		float x,y;       
				public:
					complex()
					{
					}
					complex(float real,float img)		
					{
						x=real;
						y=img;
					}
					complex operator+(complex);
					complex operator-(complex);		
					complex operator*(complex);
					void display();
		};
		
		complex complex::operator +(complex c)
		{
			complex result;
			result.x=x+c.x;
			result.y=y+c.y;
			return result;
		}
		complex complex::operator -(complex c)
		{
			complex result;
			result.x=x-c.x;
			result.y=y-c.y;
			return result;
		}		
			complex complex::operator *(complex c)
		{
			complex result;
			result.x=x*c.x-y*c.y;
			result.y=x*c.y+y*c.x;
			return result;
		}		
		void complex::display()
		{	if(y>0)
			cout<<x<<"+i"<<y<<"\n";
			else
			cout<<x<<"-i"<<y<<"\n";		
		}
		int main()
		{
			float x1,y1,x2,y2;	
			complex c1,c2,c3,c4,c5;
			cout<<"\nenter real & img value of frist complex number";			
			cin>>x1>>y1;
			cout<<"\nenter real & img value of second complex number";			
			cin>>x2>>y2;
			c1=complex(x1,y1);
			c2=complex(x2,y2);
					
			c3=c1+c2;
			c3.display();
			c4=c1-c2;
			c4.display();			
			c5=c1*c2;
			c5.display();



			return 0;
		}
				
                
				
		
		


		

