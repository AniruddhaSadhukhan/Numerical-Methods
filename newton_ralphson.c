#include<stdio.h>
#include<math.h>
#define error 0.000001
#define MAXCOUNT 30
#define F(x) (x)*(x) -4*(x)-10
#define Fd(x) 2*(x)-4
float newton_ralphson(void);
int main()
{
	float x0;
	printf("Program to find root of nonlinear equation using Newton Ralphson Method");
	printf("\n                     -------------by Aniruddha\n");
	newton_ralphson();
	return 0;
}

float newton_ralphson()
{
	float x0,xn,fx,fdx,h;
	int count;
	printf("\nEnter a starting value:");
	scanf("%f",&x0);
	printf("-------------------------------------------------------\n");
	printf("No.     	 Xn = Xo - (f(X0)/f'(Xo))");
	printf("\n-------------------------------------------------------");
	printf("\n 0\t \t\t%f\n",x0);
	for(count=1;count<=MAXCOUNT;count++)
	{
		fx=F(x0);
		fdx=Fd(x0);
		h=fx/fdx;
		xn=x0-h;
		printf("%2d\t %f-(%f/%f) = %f\n",count,x0,fx,fdx,xn);
		if(isnan(xn) || isinf(xn))
			break;
		if(fabs(h)< error)
		{
			printf("\nRoot = %f\n",xn);
			return xn;
		}
		x0=xn;
	}
	/*ALTERNATE APPROACH
	do
	{
		count++;
		fa=F(a);
		fda=Fd(a);
		h=fa/fda;
		if(isnan(h) || isinf(h))
		{
			printf("Error...Try another input\n");
			goto l1;
		}
		a=a-h;
	}while(fabs(fa)>error && count<20);*/
	printf("Required solution does not converge or iterations are insufficient.Try Again");
	newton_ralphson();
}
	
/*
Program to find root of nonlinear equation using Newton Ralphson Method
                     -------------by Aniruddha

Enter a starting value:5
-------------------------------------------------------
No.     	 Xn = Xo - (f(X0)/f'(Xo))
-------------------------------------------------------
 0	 		5.000000
 1	 5.000000-(-5.000000/6.000000) = 5.833333
 2	 5.833333-(0.694445/7.666667) = 5.742754
 3	 5.742754-(0.008209/7.485508) = 5.741657
 4	 5.741657-(0.000000/7.483315) = 5.741657

Root = 5.741657


*/
