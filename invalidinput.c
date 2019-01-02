#include<stdio.h>
#include<string.h>

int valid_input(float *value)
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

int main()
{
	float a;
	printf("Program for Valid input Check");
	printf("\n	--By Aniruddha\n");
	do
	{
		printf("Enter a:");
		fflush(stdout);
	}while(!valid_input(&a));
	printf("%f",a);
	return 0;
}
