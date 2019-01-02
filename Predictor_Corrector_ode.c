#include<stdio.h>
#include <math.h>
#define F(x,y) (3*(x)*(x)+1)

void Predictor_Corrector_ode(void);

int main()
{
	printf("Program to estimate solution of first order differential equation ");
	printf("using Predictor-Corrector Method ");
	printf("\n               -------------by Aniruddha\n");
	//y(x+h)=y(x) + h * y'(x,y(x))
	//y(x+2h)[p]=y(x) + 2*h * y'(x+h,y(x+h)) 
	//y(x+2h)[c]=y(x+h) + h/2 * [y'(x+h,y(x+h)) + y'(x+2*h,y(x+2h)[p])];
	Predictor_Corrector_ode();
	return 0;
}

void Predictor_Corrector_ode()
{
	float x,y,yn,ynnc,ynnp,xp,h;
	int n,i,count;
	
	printf("\nEnter initial value of x and y:");
	scanf("%f%f",&x,&y);
	
	printf("\nEnter x at which y is required:");
	scanf("%f",&xp);
	
	printf("Enter the step size:");
	scanf("%f",&h);
	
	n =(int)((xp-x)/h+0.5);
	h=h/2;
	for (i=1;i<=n;i++)
	{
		yn=y + h * F(x,y);
		printf("\n\ny(%4f)=%4f + %4f * %4f = %4f\n",x+h,y,h,F(x,y),yn);
		ynnp= y + 2*h*F(x+h,yn);
		printf("\ny(%4f)[p]=%4f + 2*%4f * %4f = %4f\n",x+2*h,y,h,F(x+h,yn),ynnp);
		ynnc= yn+ (h/2)*(F(x+h,yn)+F(x+2*h,ynnp));
		printf("\ny(%4f)[c]=%4f + 0.5* %4f *[%4f + %4f]  = %4f\n",x+2*h,yn,h,F(x+h,yn),F(x+2*h,ynnp),ynnc);
		y=ynnc;
		x=x+2*h;
	}
	
	printf("\ny(%f)=%f\n",xp,y);
	return;
}
/*
Program to estimate solution of first order differential equation using Predictor-Corrector Method 
               -------------by Aniruddha

Enter initial value of x and y:0 5

Enter x at which y is required:5 
Enter the step size:1


y(0.500000)=5.000000 + 0.500000 * 1.000000 = 5.500000

y(1.000000)[p]=5.000000 + 2*0.500000 * 1.750000 = 6.750000

y(1.000000)[c]=5.500000 + 0.5* 0.500000 *[1.750000 + 4.000000]  = 6.937500


y(1.500000)=6.937500 + 0.500000 * 4.000000 = 8.937500

y(2.000000)[p]=6.937500 + 2*0.500000 * 7.750000 = 14.687500

y(2.000000)[c]=8.937500 + 0.5* 0.500000 *[7.750000 + 13.000000]  = 14.125000


y(2.500000)=14.125000 + 0.500000 * 13.000000 = 20.625000

y(3.000000)[p]=14.125000 + 2*0.500000 * 19.750000 = 33.875000

y(3.000000)[c]=20.625000 + 0.5* 0.500000 *[19.750000 + 28.000000]  = 32.562500


y(3.500000)=32.562500 + 0.500000 * 28.000000 = 46.562500

y(4.000000)[p]=32.562500 + 2*0.500000 * 37.750000 = 70.312500

y(4.000000)[c]=46.562500 + 0.5* 0.500000 *[37.750000 + 49.000000]  = 68.250000


y(4.500000)=68.250000 + 0.500000 * 49.000000 = 92.750000

y(5.000000)[p]=68.250000 + 2*0.500000 * 61.750000 = 130.000000

y(5.000000)[c]=92.750000 + 0.5* 0.500000 *[61.750000 + 76.000000]  = 127.187500

y(5.000000)=127.187500

*/
