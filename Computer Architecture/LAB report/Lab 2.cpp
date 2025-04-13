#include <stdio.h>
int main()
{
	int num1,num2,r,as,bs,rs;
	printf("Enter two numbers:");
	scanf("%d%d", &num1,&num2);
	r=num1+num2;
	as=(num1>>4)&1;
	bs=(num2>>4)&1;
	rs=(r>>4)&1;
	if(((as==bs)&&(as==rs))||(as!=bs))
	{
		printf("\No Overflow \n Result=%d",r);
	}
	else
	{
		printf("\n Overflow detected\n The result is:%d",r);
	}
}

