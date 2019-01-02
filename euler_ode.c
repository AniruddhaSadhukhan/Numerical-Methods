#include<stdio.h>
#include <math.h>
#define F(x,y) (3*(x)*(x)+1)

void euler_ode(void);

int main()
{
	printf("Program to estimate solution of first order differential equation ");
	printf("using Euler's Method ");
	printf("\n               -------------by Aniruddha\n");
	//y(x+h)=y(x) + h * y'(x,y(x))
	euler_ode();
	return 0;
}

void euler_ode()
{
	float x,y,yn,xp,h;
	int n,i;
	
	printf("\nEnter initial value of x and y:");
	scanf("%f%f",&x,&y);
	
	printf("\nEnter x at which y is required:");
	scanf("%f",&xp);
	
	printf("Enter the step size:");
	scanf("%f",&h);
	
	n =(int)((xp-x)/h+0.5);

	for (i=1;i<=n;i++)
	{
		yn=y + h * F(x,y);
		printf("y(%4f)=%4f + %4f * %4f = %4f\n",x+h,y,h,F(x,y),yn);
		y=yn;
		x=x+h;
	}
	
	printf("\ny(%f)=%f\n",xp,y);
	return;
}

/*
Program to estimate solution of first order differential equation using Euler's Method 
               -------------by Aniruddha

Enter initial value of x and y:5 10

Enter x at which y is required:15
Enter the step size:1
y(6.000000)=10.000000 + 1.000000 * 76.000000 = 86.000000
y(7.000000)=86.000000 + 1.000000 * 109.000000 = 195.000000
y(8.000000)=195.000000 + 1.000000 * 148.000000 = 343.000000
y(9.000000)=343.000000 + 1.000000 * 193.000000 = 536.000000
y(10.000000)=536.000000 + 1.000000 * 244.000000 = 780.000000
y(11.000000)=780.000000 + 1.000000 * 301.000000 = 1081.000000
y(12.000000)=1081.000000 + 1.000000 * 364.000000 = 1445.000000
y(13.000000)=1445.000000 + 1.000000 * 433.000000 = 1878.000000
y(14.000000)=1878.000000 + 1.000000 * 508.000000 = 2386.000000
y(15.000000)=2386.000000 + 1.000000 * 589.000000 = 2975.000000

y(15.000000)=2975.000000

*/
