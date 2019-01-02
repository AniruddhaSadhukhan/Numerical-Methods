#include<stdio.h>
#include<math.h>
#define error 0.000001
#define F(x) 2*(x)*(x)*(x)-2.5*(x)-5
float bisection(float a,float b);
int main()
{
	float a,b;
	printf("Program to find root of nonlinear equation using False Position method");
	printf("\n                     -------------by Aniruddha\n");
	do
	{
		printf("Enter 2 starting value:");
		scanf("%f %f",&a,&b);
		while(getchar()!='\n');
	}while ((F(a))*(F(b))>0);
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("No.      X1         X2       f(X1)       f(X2)  X=X1-{F(X1)(X2-X1)/F(X2)-F(X1)}  f(X) X replaces");
	printf("\n----------------------------------------------------------------------------------------------------");
	bisection(a,b);
	return 0;
}

float bisection(float a,float b)
{
	float fa,fb,m,fm;
	int count=0;
	fa=F(a);fb=F(b);
	m=a-(fa*(b-a)/(fb-fa));
	fm=F(m);
	do
	{
		count++;
		if(fm==0)
		{
			printf("\n%2d | %f | %f | %f | %f | 	%f	    | %f	   -",count,a,b,fa,fb,m,fm);
			//return m;
		}
	
		if(fm * fa < 0)
		{
			//m replaces b
			printf("\n%2d | %f | %f | %f | %f | 	%f	    | %f	   b",count,a,b,fa,fb,m,fm);
			b=m;fb=fm;
		}
		else
		{
			//m replaces a
			printf("\n%2d | %f | %f | %f | %f | 	%f 	    | %f	   a",count,a,b,fa,fb,m,fm);
			a=m;fa=fm;	
		}
		m=a-(fa*(b-a)/(fb-fa));;
		fm=F(m);
	}while(fabs(fm) > error && fabs(a-b)> error && count<30);
	printf("\nRoot = %f\n",m);
	return m;
}

/*Sample Output
Program to find root of nonlinear equation using False Position method
                     -------------by Aniruddha
Enter 2 starting value:1 2
----------------------------------------------------------------------------------------------------
No.      X1         X2       f(X1)       f(X2)  X=X1-{F(X1)(X2-X1)/F(X2)-F(X1)}  f(X) X replaces
----------------------------------------------------------------------------------------------------
 1 | 1.000000 | 2.000000 | -5.500000 | 6.000000 | 	1.478261 	    | -2.234897	   a
 2 | 1.478261 | 2.000000 | -2.234897 | 6.000000 | 	1.619857 	    | -0.548832	   a
 3 | 1.619857 | 2.000000 | -0.548832 | 6.000000 | 	1.651716 	    | -0.116986	   a
 4 | 1.651716 | 2.000000 | -0.116986 | 6.000000 | 	1.658376 	    | -0.024166	   a
 5 | 1.658376 | 2.000000 | -0.024166 | 6.000000 | 	1.659747 	    | -0.004959	   a
 6 | 1.659747 | 2.000000 | -0.004959 | 6.000000 | 	1.660028 	    | -0.001017	   a
 7 | 1.660028 | 2.000000 | -0.001017 | 6.000000 | 	1.660085 	    | -0.000209	   a
 8 | 1.660085 | 2.000000 | -0.000209 | 6.000000 | 	1.660097 	    | -0.000043	   a
 9 | 1.660097 | 2.000000 | -0.000043 | 6.000000 | 	1.660100 	    | -0.000008	   a
10 | 1.660100 | 2.000000 | -0.000008 | 6.000000 | 	1.660100 	    | -0.000001	   a
Root = 1.660100

*/	
