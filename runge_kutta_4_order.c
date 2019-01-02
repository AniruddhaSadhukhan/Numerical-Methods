#include<stdio.h>
#include <math.h>
#define F(x,y) ((x)-(y))

void Runge_Kutta_4_order_ode(void);

int main()
{
	printf("Program to estimate solution of first order differential equation ");
	printf("using Runge_Kutta 4th order Method ");
	printf("\n               -------------by Aniruddha\n");
	//y(x+h)=y(x) + k
	//k=(k1+2k2+2k3+k4)/6
	//k1=h* y'(x,y(x))
	//k2=h* y'(x+h/2,y(x)+k1/2)
	//k3=h* y'(x+h/2,y(x)+k2/2)
	//k4=h* y'(x+h,y(x)+k3)
	Runge_Kutta_4_order_ode();
	return 0;
}

void Runge_Kutta_4_order_ode()
{
	float x,y,yn,k1,k2,k3,k4,k,xp,h;
	int n,i,count;
	
	printf("\nEnter initial value of x and y:");
	scanf("%f%f",&x,&y);
	
	printf("\nEnter x at which y is required:");
	scanf("%f",&xp);
	
	printf("Enter the step size:");
	scanf("%f",&h);
	
	n =(int)((xp-x)/h+0.5);
	for (i=1;i<=n;i++)
	{
		k1=h* F(x,y);
		k2=h* F(x+(h/2.0),y+(k1/2.0));
		k3=h* F(x+(h/2.0),y+(k2/2.0));
		k4=h* F(x+h,y+k3);
		k=(k1+2*k2+2*k3+k4)/6.0;
		yn=y + k;
		x=x+h;
		y=yn;
	}
	
	printf("\ny(%f)=%f\n",xp,y);
	return;
}

/*
Program to estimate solution of first order differential equation using Runge_Kutta 4th order Method 
               -------------by Aniruddha

Enter initial value of x and y:0 5

Enter x at which y is required:10
Enter the step size:1

y(10.000000)=9.000330
*/
