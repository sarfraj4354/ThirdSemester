#include<stdio.h>
#include <stdlib.h>
int main(){
//taking input
int *a;
 int s,i;
printf("program to demonstrate Dynamic memory allocation");
printf("\n");
printf("By safraj");
printf("\n");
// Asking user for the number of elements
printf("enter the element");
scanf("%d",&s);
// Dynamically allocate memory for 'a' integers for malloc
a= (int*)malloc(s * sizeof(int));
//checking memory allocation is successful or not
if (a == NULL) {
 printf("Memory allocation failed");
 return 1;
}
 for (i = 0; i < s; i++) {
 printf("Garbage value for %d = %d\n", i + 1, a[i]);
 }
 printf("\n");
 //input for array
 for (i = 0; i < s; i++) {
 printf("Enter the value for %d: ", i + 1);
 scanf("%d", &a[i]);
 }
 printf("\n");
 //displayed value
for (i = 0; i < s; i++) {
 printf("Entered value of %d = %d\n", i + 1,a[i]);

 }
// Dynamically allocate memory for 'a' integers for calloc
 a = (int*)calloc(s,sizeof(int));
 printf("calloc\n");
 printf("Enter the value \n");
 for (i = 0; i < s; i++)
 {
 scanf("%d",(a+i));
 }
 printf("entered data\n");
 for (i = 0; i < s; i++)
 {
printf("\n");
 printf("%d",*(a+i));
 }
 printf("\n");
 //input for additional size
 int a1;
printf("Enter the additional size");
scanf("%d",&a1);
int s1= s + a1;
// Reallocate memory to resize the array using realloc
 a = (int*)realloc(a, sizeof(int));
 for (i = s; i < s1; i++) {
 printf("Enter the value for %d: ", i + 1);
 scanf("%d", &a[i]);
 }
for (i = 0; i < s1 ; i++) {
 printf("Entered value of %d = %d\n", i + 1, a[i]);
}
 printf("\nHere are the all entered value\n");
for ( i = 0; i < s1; i++){
printf("%d\n",*(a+i));
}
// Free the dynamically allocated memory
free(a);
return 0;
}