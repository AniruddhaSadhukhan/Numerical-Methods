#include<stdio.h>

#define F(x) 1/(1 + (x))

void trapezoidal_integration(void);

int main()
{
	printf("Program to Integrate using Trapezoidal Rule");
	printf("\n               -------------by Aniruddha\n");
	//I = h/2 [F(a) +2 Σ(i=1 to n-1) F(a + ih) + F(b) ]
	//where step size h = (b-a)/n
	//and n= number of slices
	trapezoidal_integration();
	return 0;
}

void trapezoidal_integration()
{
	float a,b,h,sum;
	int n,i;
	
	printf("\nEnter the lower limit of integration:");
	scanf("%f",&a);
	
	printf("Enter the upper limit of integration:");
	scanf("%f",&b);
	
	printf("Enter the segment width:");
	scanf("%f",&h);
	n = (b-a)/h;
	
	/*printf("Enter the number of slices:");
	scanf("%d",&n);
	h = (b-a)/n;*/
	
	printf("I = (%f/2)*[%f + 2*(",h,F(a));
	sum = F(a) + F(b);
	for (i=1;i<n;i++)
	{
		sum = sum + 2*F(a+i*h);
		printf("%f + ",F(a+i*h));
	}
	sum = h*sum/2.0;
	printf("\b\b) + %f]\n",F(b));
	
	printf("Integration when h=%f is %f\n",h,sum);
	return;
}
/*
Program to Integrate using Trapezoidal Rule
               -------------by Aniruddha

Enter the lower limit of integration:5
Enter the upper limit of integration:10
Enter the segment width:1
I = (1.000000/2)*[0.166667 + 2*(0.142857 + 0.125000 + 0.111111 + 0.100000) + 0.090909]
Integration when h=1.000000 is 0.607756

*/	
