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
	printf("i                                                                     l(i)                                                                                   f(i)     f(i)l(i)\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
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
		printf("%d | ",i);
		for(j=0;j<n;j++)
			if(i!=j)
				printf("(X-x[%d])/(x[%d]-x[%d]) ",j,i,j);
		printf("=");
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				prod=prod * (xp - x[j])/(x[i] - x[j]);
				printf("(%f-%f)/(%f-%f) ",xp,x[j],x[i],x[j]);
			}
			
		}
		printf("=%f | %f | %f\n",prod,fx[i],prod*fx[i]);
		sum=sum+prod*fx[i];
	}
	printf("Interpolated function value : f(%f) = %f\n",xp,sum);
	return sum;
}
