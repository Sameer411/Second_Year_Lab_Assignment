#include<iostream>
#include<cmath>
using namespace std;

struct poly1
{
	int expo;
	float coeff;
};

class polynomial
{
	private:
		poly1 poly[100];
		int total_terms;
	public:
		
		polynomial()
		{
			total_terms=0;
		}
	void read_poly();
	void dis_poly();

	void evaluate(double value);
	polynomial add_poly(polynomial B);
	//polynomial multi_poly(polynomial B);
};
	
void polynomial::read_poly()
{
	int i;
	cout<<"\nread the polynomial\n";
	cout<<"\nEnter the total no of terms\n";
	cin>>total_terms;
	for(i=0;i<total_terms;i++)
	{
		cout<<"\nEnter the exponent of\n"<<i+1<<" term\n";
		cin>>poly[i].expo;
		cout<<"\nEnter the coefficient of\n"<<i+1<<" term\n";
		cin>>poly[i].coeff;
	}
}
void polynomial::dis_poly()
{
		int i;
		cout<<"\nThe polynomial is as follows\n";
		for(i=0;i<total_terms;i++)
		{
			cout<<poly[i].coeff<<"x^"<<poly[i].expo<<"+";
			cout<<"\t";
		}
}
void polynomial::evaluate(double)
{ 
	int i,x;
	double sum=0;
	cout<<"\nenter the value of variable\n";
	cin>>x;
	for(i=0;i<total_terms;i++)
	{
 		sum=sum+poly[i].coeff*pow(x,poly[i].expo);
	}
	cout<<"\nevalution is as =\n"<<sum;
}
polynomial polynomial::add_poly(polynomial b)
{ 
	int m,n,i=0,k=0,j=0;
	polynomial c;
	while (i<total_terms&&j<b.total_terms)
	{
		if(poly[i].expo==b.poly[j].expo)
		{
			c.poly[k].coeff=poly[i].coeff+b.poly[j].coeff;
			c.poly[k].expo=poly[i].expo;
			i++;
			j++;
			k++;
		}
		else if (poly[i].expo>b.poly[j].expo)
			{
				c.poly[k].coeff=b.poly[i].coeff;	
				c.poly[k].expo=poly[i].expo;
				i++;
				j++;
				k++;
			}
		else
			{
				c.poly[k].coeff=b.poly[j].coeff;
				c.poly[k].expo=b.poly[j].expo;
				j++;
				k++;
			}
	}
	
	while(i<total_terms)
	{
		c.poly[k].coeff=poly[i].coeff;
		c.poly[k].expo=poly[i].expo;
		i++;
		k++;
	}
	while(j<b.total_terms)
	{
		c.poly[k].coeff=b.poly[j].coeff;
		c.poly[k].expo=b.poly[j].expo;
		j++;
		k++;
	}
	c.total_terms=k;
	return c;
}

int main()
{
	polynomial a,b,c;
	a.read_poly();
	a.dis_poly();
	b.read_poly();
	b.dis_poly();
	a.evaluate(2);
	c=a.add_poly(b);
	c.dis_poly();

	return 0;
}
