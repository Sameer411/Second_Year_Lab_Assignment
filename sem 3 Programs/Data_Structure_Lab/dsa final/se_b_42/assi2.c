#include<stdio.h>
int i,j;
void read(int a[10][10],int c,int b);
void add(int a[10][10],int b[10][10],int n,int z);
void display(int a[10][10],int n,int z);
void multi(int a[20][10],int b[10][10],int z,int n);
void trans(int a[10][10],int z,int x);
void diago(int a[10][10],int c,int s);
void uptr(int a[01][10],int f,int r);
void main()
{
	int mat1[10][10],mat2[10][10],sm,sum[10][10],n,z,ch,upper,k;	
	printf(" Enter the number of rows: ");
	scanf("%d",&n);
	printf(" Enter the number of coloums: ");
	scanf("%d",&z);
	printf(" Enter the elements of MATRIX 1\n");
	read(mat1,n,z);
	printf(" Enter the elements of MATRIX 2\n");
	read(mat2,n,z);
	printf("Matrix 1 is\n\n");
	display(mat1,n,z);
	printf("Matrix 2 is\n\n");
	display(mat2,n,z);
	printf(" \n1.sum  \n2.Transpose \n3.sum of diagonal elements\n");
	if(n==z)
	printf(" \n4.multiplication \n5.find if the triangle is upper triangular");
	scanf(" %d",&ch);
	switch(ch)
	{
	case 1:
	{
	add(mat1,mat2,n,z);
	}
	break;
	case 2:
	{
		multi(mat1,mat2,n,z);
	}
	break;
	case 3:
	{
	printf(" \n The transpose of matrix1 is:\n");	
	trans(mat1,n,z);
	printf("The transpose of Matrix 2 is\n\n");
	trans(mat2,n,z);
	}
	break;
	case 4:
	{
		printf(" The sum of diagonal elements of matrix 1 is");
		diago(mat1,n,z);
		printf(" The sum of diagonal elements of matrix 2 is");
		diago(mat2,n,z);
	}
	break;
	case 5:
	{
		uptr(mat1,n,z);		
	}
	break;
	default:
	{
		printf(" Please enter a valid choice");
		break;
	}
	}
	}

	void add(int mat1[][10],int mat2[][10],int n,int z)
{	
	int i,j,sum[10][10];
	printf(" sum of matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=z;j++)
		{	
			sum[i][j]=mat1[i][j]+mat2[i][j];		
			printf("%d ",sum[i][j]);	
		}
		printf("\n");
	}
}
	void read(int mat1[][10],int n,int z)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=z;j++)
			{
				printf(" Enter element A%d%d: ",i,j);			
				scanf("%d",&mat1[i][j]);	
			}
		}
	}
	void display(int mat1[][10],int n,int z)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=z;j++)
			{			
				printf("%d ",mat1[i][j]);	
			}
			printf("\n");
		}
	}
	void multi(int mat1[][10],int mat2[][10],int n, int z)	
	{
		int mul[10][10],k;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=z;j++)
			{
				mul[i][j]=0;
				for(k=1;k<=z;k++)
				{
					mul[i][j]=mul[i][j]+mat1[i][k]*mat2[k][j];
				}
			}
		}	

		printf(" Multiplication of matrix is:\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=z;j++)
			{			
				printf("%d ",mul[i][j]);	
			}
			printf("\n");
		}	
	}
	
	void trans(int mat1[][10],int n,int z)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=z;j++)
			{		
				printf("%d ",mat1[j][i]);	
			}
			printf("\n");
		}
	}
	void diago(int mat1[][10],int n,int z)
	{	
		int sm;
		for(i=1;i<=n;i++)
		{
			sm=sm+mat1[i][i];
		}
				printf(": %d",sm);	
	}
	void uptr(int mat1[][10],int n,int z)
		{
			int upper;
			for(i=0;i<n;i++)
			{	
				for(j=0;j<z;j++)
				{
					if(i>j&&mat1[i][j]==0)
					{
						upper=1;
						upper++;
					}
				}
			}
			if(upper==3&&n==3&&z==3||upper==2)
			{		
				printf("matrix is upper triangular\n");
			}
			else
			{	
				printf("matrix is not upper triangularr\n");
			}
		}	
