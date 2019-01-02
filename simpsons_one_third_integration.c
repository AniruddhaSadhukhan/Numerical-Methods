#include<stdio.h>
#include <math.h>
#define F(x) (1 - exp(-(x)/2.0))

void simpsons_one_third_integration(void);

int main()
{
	printf("Program to Integrate using Simpson's 1/3 Rule");
	printf("\n               -------------by Aniruddha\n");
	//I = h/3 [F(a) + 4Σ(i=1 to n) F(a + (2i-1)h) + 2Σ(i=1 to n-1) F(a + (2i)h) + F(b) ]
	//where step size h = (b-a)/2n
	//and n= number of slices
	simpsons_one_third_integration();
	return 0;
}

void simpsons_one_third_integration()
{
	float a,b,h,sum;
	int n,i;
	
	printf("\nEnter the lower limit of integration:");
	scanf("%f",&a);
	
	printf("Enter the upper limit of integration:");
	scanf("%f",&b);
	
	/*printf("Enter the segment width:");
	scanf("%f",&h);
	n = (b-a)/h;
	h=h/2;*/
	
	printf("Enter the number of slices:");
	scanf("%d",&n);
	h = (b-a)/(2*n);
	
	printf("I = (%.4f/3)*[%.4f + 4*(",h,F(a));
	sum = F(a) + F(b);
	for (i=1;i<=n;i++)
	{
		sum = sum + 4*F(a+ (2*i - 1)*h);
		printf("%.4f + ",F(a+ (2*i - 1)*h));
	}
	printf("\b\b) + 2*(");
	for (i=1;i<=n-1;i++)
	{
		sum = sum + 2*F(a+ 2*i*h);
		printf("%.4f + ",F(a+2*i*h));
	}
	sum = h*sum/3.0;
	printf("\b\b) + %.4f]\n",F(b));
	
	printf("Integration when n=%d is %f\n",n,sum);
	return;
}
/*
Program to Integrate using Simpson's 1/3 Rule
               -------------by Aniruddha

Enter the lower limit of integration:5
Enter the upper limit of integration:10
Enter the number of slices:10
I = (0.2500/3)*[0.9179 + 4*(0.9276 + 0.9436 + 0.9561 + 0.9658 + 0.9734 + 0.9792 + 0.9838 + 0.9874 + 0.9902 + 0.9924 ) + 2*(0.9361 + 0.9502 + 0.9612 + 0.9698 + 0.9765 + 0.9817 + 0.9857 + 0.9889 + 0.9913 ) + 0.9933]
Integration when n=10 is 4.849306

*/
