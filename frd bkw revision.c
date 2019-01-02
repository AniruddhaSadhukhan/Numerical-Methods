#include<stdio.h>
#include<math.h>
#include<string.h>


int vinp(float *value)
{
	int n;
	char buff[32];
	if(fgets(buff,sizeof buff,stdin)!=NULL)
	{
		char *newline =strchr(buff,'\n');
		if(newline!=NULL)
			*newline='\0';
	}
	return sscanf(buff,"%f%n",value,&n)==1 & (int)strlen(buff)==n;
}

int vinpint(int *value)
{
	int n;
	char buff[32];
	if(fgets(buff,sizeof buff,stdin)!=NULL)
	{
		char *newline =strchr(buff,'\n');
		if(newline!=NULL)
			*newline='\0';
	}
	return sscanf(buff,"%d%n",value,&n)==1 & (int)strlen(buff)==n;
}

int main()
{
	float arr[50][50],sum=0,prod,xn,s;
	int n,i,j;
	printf("Program to find interpolation value at specified point,given a set of data points");
	printf("\n     using Newton's Forward and Backward Difference interpolation method");
	printf("\n              	       -------------by Aniruddha\n");
	do
	{
		printf("Enter no. of data sets:");
		fflush(stdout);
	}while(!vinpint(&n));
	for(i=1;i<=n;i++)
	{
		do
		{
			printf("Enter x[%d]:",i);
			fflush(stdout);
		}while(!vinp(&arr[i][1]));
		do
		{
			printf("Enter f[%d]:",i);
			fflush(stdout);
		}while(!vinp(&arr[i][2]));
	}
	
	do
	{
		printf("Enter x at which interpolation is required:");
		fflush(stdout);
	}while(!vinp(&xn));
	
	for(j=3;j<=n+1;j++)
	{
		for(i=1;i<=n-j+2;i++)
		{
			//printf("\n%f-%f=%f\n",arr[i+1][j-1],arr[i][j-1],arr[i+1][j-1] - arr[i][j-1]);
			arr[i][j]=arr[i+1][j-1] - arr[i][j-1];
		}
			
	}	
	printf("%f  ",arr[3][3]);		
	printf("Difference Table\n");
	printf("  x  	f(x)	");
	for(i=1;i<n;i++)
		printf("  %df    ",i);
		
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n+2-i;j++)
			printf("%f  ",arr[i][j]);	
	}
	
	//Forward
	s=(xn-arr[1][1])/(arr[2][1]-arr[1][1]);
	sum=arr[1][2];
	for(i=1;i<n;i++)
	{
		prod=1;
		for(j=0;j<i;j++)
			prod=prod*(s-j)/(j+1);
		sum=sum+prod*arr[1][2+i];
	}
	printf("\n\n%f\n\n",sum);
	
	//backward
	s=(xn-arr[n][1])/(arr[2][1]-arr[1][1]);
	sum=arr[n][2];
	for(i=1;i<n;i++)
	{
		prod=1;
		for(j=0;j<i;j++)
			prod=prod*(s+j)/(j+1);
		sum=sum+prod*arr[n-i][2+i];
	}
	printf("\n\n%f\n\n",sum);
	return 0;
}
