#include<stdio.h>
#include <math.h>
#define MAX 50
float arr[MAX][MAX+1];
float ans[MAX];
void Gauss_Elimination(void);

int main()
{
	printf("Program to solve linear equations ");
	printf("using Gauss Elimination ");
	printf("\n               -------------by Aniruddha\n");
	Gauss_Elimination();
	return 0;
}

void Gauss_Elimination()
{
	float x,y,h,sum,temp;
	int n,i,j,count,k;
	
	//Input value and generation of augmented matrix
	
	printf("\nEnter number of unknown variable:");
	scanf("%d",&n);
	
	printf("\nEnter %d linear equations:\n",n);
	printf("\nSample Equation:");
	for(i=0;i<n;i++)
	{
		printf("a%d x%d + ",i+1,i+1);
	}
	printf("\b\b = b\n");
	for(i=1;i<=n;i++)
	{
		printf("Eqn %d:\n",i);
		for(j=1;j<=n;j++)
		{
			printf("a%d =",j) ;
			scanf("%f",&arr[i][j]);
		} 	
		printf("b =") ;
		scanf("%f",&arr[i][n+1]);
	}
	
	//Print Augmented Matrix
	
	printf("Augmented matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
			printf("%f   ",arr[i][j]) ; 	
		printf("\n") ;
	}
	
	//Generation of upper triangular matrix 
	for(k=1;k<n;k++)
	{
		for(i=1+k;i<=n;i++)//k=1:i=2,3..n|k=2:i=3..n
		{
			temp = arr[i][k];
			printf("\nR%d =R%d - %f/%f R%d",i,i,temp,arr[k][k],i-1);
			
			for(j=1;j<=n+1;j++)
				arr[i][j] = arr[i][j]	- (temp/arr[k][k])*arr[k][j];
		}
	
	
	printf("\nAfter Itteration %d:\n",k);
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
			printf("%f   ",arr[i][j]) ; 	
		printf("\n") ;
	}
	}
	
	//Finding solution by backward substitution 
	for(i=n;i>0;i--)
	{
		sum=0.0;
		for(j=i+1;j<=n;j++)
		sum=sum+arr[i][j]*ans[j];
		ans[i]=(arr[i][n+1]-sum)/arr[i][i];
	}
	
	//Printing solution 
	
	for(i=1;i<n+1;i++)
		printf("\nx%d = %f ",ans[i]);
	return;
}
/*
Program to solve linear equations using Gauss Elimination 
               -------------by Aniruddha

Enter number of unknown variable:2

Enter 2 linear equations:

Sample Equation:a1 x1 + a2 x2  = b
Eqn 1:
a1 =5
a2 =10
b =23
Eqn 2:
a1 =2 
a2 =9
b =32
Augmented matrix is:
5.000000   10.000000   23.000000   
2.000000   9.000000   32.000000   

R2 =R2 - 2.000000/5.000000 R1
After Itteration 1:
5.000000   10.000000   23.000000   
0.000000   5.000000   22.799999   

x-2019772544 = -4.520000 
x1 = 4.560000
*/
