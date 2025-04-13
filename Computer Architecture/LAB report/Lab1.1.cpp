#include <stdio.h>
char onesComplement( char num) 
{
    return ~num; 
}
char twosComplement( char num) 
{
    return onesComplement(num) + 1; 
}
void printBinary( char num) 
{
    for (int i = 4; i >= 0; i--) 
   {
        printf("%d", (num >> i) & 1);
    }
}

int main() 
{
     char num;
    printf("Enter an 4-bit number: ");
    scanf("%d", &num);
    unsigned char onesComp = onesComplement(num);
    unsigned char twosComp = twosComplement(num);

    printf("Original number: %d\n", num);
    printf("Binary representation of original number: ");
    printBinary(num);
    printf("\n");
    printf("Binary representation of 1's complement: ");
    printBinary(onesComp);
    printf("\n");
    printf("Binary representation of 2's complement: ");
    printBinary(twosComp);
    printf("\n");

    return 0;
}

