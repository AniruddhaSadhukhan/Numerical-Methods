#include<stdio.h>
#include <math.h>
#define F(x,y) (3*(x)*(x)+1)

void Runge_Kutta_2_order_ode(void);

int main()
{
	printf("Program to estimate solution of first order differential equation ");
	printf("using Runge_Kutta Method ");
	printf("\n               -------------by Aniruddha\n");
	//y(x+h)=y(x) + k
	//k=(k1+k2)/2
	//k1=h* y'(x,y(x))
	//k2=h* y'(x+h,y(x)+k1)
	Runge_Kutta_2_order_ode();
	return 0;
}

void Runge_Kutta_2_order_ode()
{
	float x,y,yn,k1,k2,k,xp,h;
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
		printf("\n\nk1=%4f * %4f",h,F(x,y));
		k2=h* F(x+h,y+k1);
		printf("\nk2=%4f * %4f",h,F(x+h,y+k1));
		k=(k1+k2)/2.0;
		yn=y + k;
		printf("\ny(%4f)=%4f + (%4f * %4f)/2 = %4f\n",x+h,y,k1,k2,yn);
		x=x+h;
		y=yn;
	}
	
	printf("\ny(%f)=%f\n",xp,y);
	return;
}

/*
Program to estimate solution of first order differential equation using Runge_Kutta Method 
               -------------by Aniruddha

Enter initial value of x and y:0 5

Enter x at which y is required:10
Enter the step size:1


k1=1.000000 * 1.000000
k2=1.000000 * 4.000000
y(1.000000)=5.000000 + (1.000000 * 4.000000)/2 = 7.500000


k1=1.000000 * 4.000000
k2=1.000000 * 13.000000
y(2.000000)=7.500000 + (4.000000 * 13.000000)/2 = 16.000000


k1=1.000000 * 13.000000
k2=1.000000 * 28.000000
y(3.000000)=16.000000 + (13.000000 * 28.000000)/2 = 36.500000


k1=1.000000 * 28.000000
k2=1.000000 * 49.000000
y(4.000000)=36.500000 + (28.000000 * 49.000000)/2 = 75.000000


k1=1.000000 * 49.000000
k2=1.000000 * 76.000000
y(5.000000)=75.000000 + (49.000000 * 76.000000)/2 = 137.500000


k1=1.000000 * 76.000000
k2=1.000000 * 109.000000
y(6.000000)=137.500000 + (76.000000 * 109.000000)/2 = 230.000000


k1=1.000000 * 109.000000
k2=1.000000 * 148.000000
y(7.000000)=230.000000 + (109.000000 * 148.000000)/2 = 358.500000


k1=1.000000 * 148.000000
k2=1.000000 * 193.000000
y(8.000000)=358.500000 + (148.000000 * 193.000000)/2 = 529.000000


k1=1.000000 * 193.000000
k2=1.000000 * 244.000000
y(9.000000)=529.000000 + (193.000000 * 244.000000)/2 = 747.500000


k1=1.000000 * 244.000000
k2=1.000000 * 301.000000
y(10.000000)=747.500000 + (244.000000 * 301.000000)/2 = 1020.000000

y(10.000000)=1020.000000

*/
