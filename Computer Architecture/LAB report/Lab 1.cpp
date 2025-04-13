#include<stdio.h>
int conversion(int num, int base) 
{
    int rem;
	  if (num == 0) 
    {
        return 1;  
    } 
    else 
    {
        rem = num % base;
        conversion(num / base, base);  
        if (base == 16 && rem >= 10) 
	  {
            printf("%c", rem + 55);
        } 
	  else 
	  {
            printf("%d", rem);
        }
    }
}
int main() 
{
    int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	if(num!=0)
    	{
		printf("The result Binary = ");
		conversion(num, 2);
		printf("\n");
		printf("The result Hexadecimal = ");
		conversion(num, 16);
		printf("\n");
		printf("The result Octal = ");
		conversion(num, 8);
		printf("\n");
	}
	else
	{
		printf("The  binary number is=O\n");
		printf("The  hexadecimal number is=O\n");
		printf("The  octal number is=O\n");
	}
}

