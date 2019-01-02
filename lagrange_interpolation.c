#include<stdio.h>
#define MAX 10
float lagrange_interpolation(float x[],float fx[],int n,float xp);
int main()
{
	float x[MAX],fx[MAX],xp;
	int n,i,j;
	printf("Program to find interpolation value at specified point,given a set of data points, using Lagrange interpolation method");
	printf("\n                     -------------by Aniruddha\n");
	printf("Input number of data points: ");
	scanf("%d",&n);
	printf("Input data points and values: \n");
	for (i=0;i<n;i++)
		scanf("%f%f",&x[i],&fx[i]);
	printf("Input x at which interpolation is required: ");
	scanf("%f",&xp);
	lagrange_interpolation(x,fx,n,xp);
	return 0;
}
float lagrange_interpolation(float x[],float fx[],int n,float xp)
{
	float sum=0.0,prod;
	int i,j;
	for (i=0;i<n;i++)
	{
		prod=1.0;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			prod=prod * (xp - x[j])/(x[i] - x[j]);
		}
		sum=sum+prod*fx[i];
	}
	printf("Interpolated function value : f(%f) = %f\n",xp,sum);
	return sum;
}

/*
Program to find interpolation value at specified point,given a set of data points, using Lagrange interpolation method
                     -------------by Aniruddha
Input number of data points: 5
Input data points and values: 
1 1
2 4
3 9
4 16
5 25
Input x at which interpolation is required: 6
Interpolated function value : f(6.000000) = 36.000000
*/
