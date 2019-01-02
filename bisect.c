#include<stdio.h>
#include<math.h>
#define error 0.000001
#define F(x) (x)*(x)*(x)-4*(x)-9
float bisection(float a,float b);
int main()
{
	float a,b;
	printf("Program to find root of nonlinear equation using bisection method");
	printf("\n                     -------------by Aniruddha\n");
	do
	{
		printf("Enter 2 starting value:");
		scanf("%f %f",&a,&b);
	}while ((F(a))*(F(b))>0);
	printf("---------------------------------------------------------------------------------\n");
	printf("No.      a          b       f(a)       f(b)     m=(a+b)/2      f(m)    m replaces");
	printf("\n---------------------------------------------------------------------------------");
	bisection(a,b);
	return 0;
}

float bisection(float a,float b)
{
	float fa,fb,m,fm;
	int count=0;
	fa=F(a);fb=F(b);
	do
	{
		count++;
		m=(a+b)/2.0;
		fm=F(m);
		if(fm==0)
		{
			printf("\n%2d | %f | %f | %f | %f | %f | %f	-",count,a,b,fa,fb,m,fm);
			//return m;
		}
	
		if(fm * fa < 0)
		{
			//m replaces b
			printf("\n%2d | %f | %f | %f | %f | %f | %f	b",count,a,b,fa,fb,m,fm);
			b=m;fb=fm;
		}
		else
		{
			//m replaces a
			printf("\n%2d | %f | %f | %f | %f | %f | %f	a",count,a,b,fa,fb,m,fm);
			a=m;fa=fm;
		}
	}while(fabs(fm) > error && fabs(a-b)> error && count<=30);
	printf("\nRoot = %f\n",m);
	return m;
}

/*
Program to find root of nonlinear equation using bisection method
                     -------------by Aniruddha
Enter 2 starting value:2 3
---------------------------------------------------------------------------------
No.      a          b       f(a)       f(b)     m=(a+b)/2      f(m)    m replaces
---------------------------------------------------------------------------------
 1 | 2.000000 | 3.000000 | -9.000000 | 6.000000 | 2.500000 | -3.375000	a
 2 | 2.500000 | 3.000000 | -3.375000 | 6.000000 | 2.750000 | 0.796875	b
 3 | 2.500000 | 2.750000 | -3.375000 | 0.796875 | 2.625000 | -1.412109	a
 4 | 2.625000 | 2.750000 | -1.412109 | 0.796875 | 2.687500 | -0.339111	a
 5 | 2.687500 | 2.750000 | -0.339111 | 0.796875 | 2.718750 | 0.220917	b
 6 | 2.687500 | 2.718750 | -0.339111 | 0.220917 | 2.703125 | -0.061077	a
 7 | 2.703125 | 2.718750 | -0.061077 | 0.220917 | 2.710938 | 0.079424	b
 8 | 2.703125 | 2.710938 | -0.061077 | 0.079424 | 2.707031 | 0.009048	b
 9 | 2.703125 | 2.707031 | -0.061077 | 0.009048 | 2.705078 | -0.026045	a
10 | 2.705078 | 2.707031 | -0.026045 | 0.009048 | 2.706055 | -0.008505	a
11 | 2.706055 | 2.707031 | -0.008505 | 0.009048 | 2.706543 | 0.000269	b
12 | 2.706055 | 2.706543 | -0.008505 | 0.000269 | 2.706299 | -0.004118	a
13 | 2.706299 | 2.706543 | -0.004118 | 0.000269 | 2.706421 | -0.001925	a
14 | 2.706421 | 2.706543 | -0.001925 | 0.000269 | 2.706482 | -0.000826	a
15 | 2.706482 | 2.706543 | -0.000826 | 0.000269 | 2.706512 | -0.000278	a
16 | 2.706512 | 2.706543 | -0.000278 | 0.000269 | 2.706528 | -0.000004	a
17 | 2.706528 | 2.706543 | -0.000004 | 0.000269 | 2.706535 | 0.000134	b
18 | 2.706528 | 2.706535 | -0.000004 | 0.000134 | 2.706532 | 0.000065	b
19 | 2.706528 | 2.706532 | -0.000004 | 0.000065 | 2.706530 | 0.000031	b
20 | 2.706528 | 2.706530 | -0.000004 | 0.000031 | 2.706529 | 0.000013	b
Root = 2.706529

*/