#include<stdio.h>
#include<math.h>
#define MAX 10
float DiffTable[MAX][MAX + 1];
int n;
float forward_diff_interpolation(float);
float backward_diff_interpolation(float x);
int main()
{
	float x;
	int i , j;
	printf("Program to find interpolation value at specified point,given a set of data points");
	printf("\n     using Newton's Forward and Backward Difference interpolation method");
	printf("\n              	       -------------by Aniruddha\n");
	printf("Input number of data points: ");
	scanf("%d",&n);
	printf("Input data points and values: \n");
	for (i=0;i<n;i++)
		scanf("%f%f",&DiffTable[i][0],&DiffTable[i][1]);
	for(i=2;i<=n;i++)
		for(j=0;j<=n-i;j++)
			DiffTable[j][i]=DiffTable[j+1][i-1] - DiffTable[j][i-1];
	printf("Difference Table:\n");
	printf("    X         Y  ");
	for(i=1;i<n;i++)
		printf("       \u0394%df",i);	
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-i;j++)
			printf("%f  ",DiffTable[i][j]);
		printf("\n");	
	}
	printf("Input x at which interpolation is required: ");
	scanf("%f",&x);
	forward_diff_interpolation(x);
	backward_diff_interpolation(x);
}
float backward_diff_interpolation(float x)
{
	float sum,s,h,prod;
	int i,j;
	sum=DiffTable[n-1][1];
	h=DiffTable[1][0] - DiffTable[0][0];
	s=(x - DiffTable[n - 1][0])/h;
	printf("\n(%f) + ",sum);
	for(i=2;i<=n;i++)
	{
		prod=DiffTable[n-i][i];
		printf("[(%f)",prod);
		for(j=1;j<i;j++)
		{
			prod=prod*(s+j-1)/j;
			printf("{(%f)/(%d)}",(s+j-1),j);
		}
		printf("] + ");	
		sum=sum+prod;
	}
	printf("\b\b  \nBy Newton's Backward Difference Interpolation, F(%f) = %f\n",x,sum);
	return sum;
}
float forward_diff_interpolation(float x)
{
	float sum,s,h,prod;
	int i,j;
	sum=DiffTable[0][1];
	h=DiffTable[1][0] - DiffTable[0][0];
	s=(x - DiffTable[0][0])/h;
	printf("\n(%f) + ",sum);
	for(i=2;i<=n;i++)
	{
		prod=DiffTable[0][i];
		printf("[(%f)",prod);
		for(j=1;j<i;j++)
		{
			prod=prod*(s-j+1)/j;
			printf("{(%f)/(%d)}",(s-j+1),j);
		}
		printf("] + ");	
		sum=sum+prod;
	}
	printf("\b\b  \nBy Newton's Forward Difference Interpolation, F(%f) = %f\n\n",x,sum);
	return sum;
}
/*Sample output:
Input number of data points: 5
Input data points and values: 
10 .1736
20 .3420
30 .5
40 .6428
50 .7660
Difference Table:
    X         Y         Δ1f       Δ2f       Δ3f       Δ4f
10.000000  0.173600  0.168400  -0.010400  -0.004800  0.000400  
20.000000  0.342000  0.158000  -0.015200  -0.004400  
30.000000  0.500000  0.142800  -0.019600  
40.000000  0.642800  0.123200  
50.000000  0.766000  
Input x at which interpolation is required: 25

(0.173600) + [(0.168400){(1.500000)/(1)}] + [(-0.010400){(1.500000)/(1)}{(0.500000)/(2)}] + [(-0.004800){(1.500000)/(1)}{(0.500000)/(2)}{(-0.500000)/(3)}] + [(0.000400){(1.500000)/(1)}{(0.500000)/(2)}{(-0.500000)/(3)}{(-1.500000)/(4)}]   
By Newton's Forward Difference Interpolation, F(25.000000) = 0.422609


(0.766000) + [(0.123200){(-2.500000)/(1)}] + [(-0.019600){(-2.500000)/(1)}{(-1.500000)/(2)}] + [(-0.004400){(-2.500000)/(1)}{(-1.500000)/(2)}{(-0.500000)/(3)}] + [(0.000400){(-2.500000)/(1)}{(-1.500000)/(2)}{(-0.500000)/(3)}{(0.500000)/(4)}]   
By Newton's Backward Difference Interpolation, F(25.000000) = 0.422609
*/

