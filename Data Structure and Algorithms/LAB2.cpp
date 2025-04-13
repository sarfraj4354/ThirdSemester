#include <stdio.h>
#include <stdlib.h>
int top = -1;
int push(int max);
int pop();
int display();
int stack[30];
int main() {
 int n, maxsize;
 printf("Basic Operation of Stack\t");
printf("BY safraj\n");
 printf("Enter the size of stack: ");
 scanf("%d", &maxsize);
 while (1) {
 //entering a choice
 printf("Enter your choice: 1 for push\n 2 for pop\n 3 for display\n 4 for exit\n");
 scanf("%d", &n);
 switch (n) {
 case 1:
 push(maxsize);
 break;
 case 2:
 pop();
 break;
 case 3:
 display();
 break;
 default:
 exit(0);
 }
 }
 return 0;
}
// Function to push an element onto the stack
int push(int max) {
 int a;
 // Function to check if the stack is full
 if (top == max - 1) {
 printf("Stack is full\n");
 } else {
 printf("Enter the number to be pushed: ");
 scanf("%d", &a);
 top = top + 1;
 stack[top] = a;
 }
 return 0;
}
// Function to pop an element from the stack
int pop() {
 if (top == -1) {
 printf("Underflow!!\n");
 } else {
 printf("Popped element: %d\n", stack[top]);
 top = top - 1;
 }
 return 0;
}
// Function to display an element
int display() {
 if (top == -1) {
 printf("Stack is empty\n");
 }
else {
 printf("Elements present in the stack: \n");
 for (int i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
 }
 }
 return 0;
}
