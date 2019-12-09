//SAMEER RATHOD 
// PROGRAM 1 STUDENTS DETAILS 
#include<stdio.h>
void main()
{
	int i,sum=0,marks[20],max=0,cnt,n,counter[10],count[10],z,maxm;
	int choice,min,a,j,h,f;
	float avg_abs,avg_wabs;
	printf("enter the number of the students\n");
	scanf("%d",&a);
	printf("enter the marks for %d students",a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&marks[i]);
	}
	for(i=0;i<a;i++)
	{
		if(marks[i]!=-1)
		{
			sum=sum+marks[i];
		}	
	}
		printf("sum of marks is:\n%d\n",sum);
		for(z=0;z<6;z++)
		{
			printf("1:average\n 2:maximum marks\n 3: minimum marks\n 4:no of absent studentd\n 5:average without absent student\n 6:maximum marks scored by the class");
			printf("enter your choice \n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				avg_abs=sum/10;		//average
				printf("average marks is with absent:");
				printf("%f\n",avg_abs);
				break;
		
				case 2:
				for(i=1;i<a;i++)      //maximum
				{
						if(max<marks[i])
						max=marks[i];
				}
				printf("maximum marks in the array is:");
				printf("%d\n",max);
				break;	
	
				case 3:
				min=marks[0];     //minimum
				for(i=1;i<a;i++)
				if(marks[i]!=-1)
				{
					{
						if(min>marks[i])
						min=marks[i];
					}
				}
				printf("minimum marks in the array is:");
				printf("%d\n",min);
				break;

				case 4:
				cnt=0;               //absent studetns
				for(i=0;i<a;i++)
				{
					if(marks[i]==-1)
					{
						cnt++;
					}
				}	
				printf("total number of absent student %d\n",cnt);
				break;
		
				case 5:
				avg_wabs=sum/(10-cnt);      //absent student avg
				printf("average marks without absent students is:");
		      	 	printf("%f\n",avg_wabs);
				break;
		
				case 6:                  //maximum marks by the class
				for(i=0;i<a;i++)
				{
					count[i]=0;
					for(j=0;j<a;j++)
					{
						if(marks[i]==marks[j])
						{
						count[i]++;
						}
					}
				}
				for(h=0;h<a;h++)
				{
					printf("%d",count[h]);
				}
				for(i=0;i<a;i++)
				{
					if(marks[i]!=-1)
					{
						if(maxm<count[i])
						{
							maxm=count[i];
							f=i;
						}
					}
				}
				printf("maximum marks scored by the class is %d\n",marks[f]);
				printf("number of the student having most marks frequency is %d\n",maxm);
				break;
				default:
				printf("sorry you have selected wrong choice\n");
				break;
		}
	} 
}
