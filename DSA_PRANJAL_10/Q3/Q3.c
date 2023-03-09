#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], temp[MAX];
int top = -1;

void push(int item) {
   if (top == MAX - 1) {
      printf("Stack Overflow\n");
   } else {
      top++;
      stack[top] = item;
   }
}

int pop() {
   int item;
   if (top == -1) {
      printf("Stack Underflow\n");
   } else {
      item = stack[top];
      top--;
      return item;
   }
}

int peek() {
   return stack[top];
}

int isEmpty() {
   if (top == -1) {
      return 1;
   } else {
      return 0;
   }
}

void sortStack() {
   int tmp;
   while (!isEmpty()) {
      tmp = pop();
      while (!isEmpty() && peek() > tmp) {
         push(temp[top] = pop());
      }
      push(tmp);
      while (top >= 0) {
         push(temp[top--]);
      }
   }
   printf("Sorted array:\n");
   for (int i = 0; i <= top; i++) {
      printf("%d ", stack[i]);
   }
}

int main() {
   int arr[] = {8, 5, 7, 1, 9, 12, 10};
   int n = sizeof(arr)/sizeof(arr[0]);
   for (int i = 0; i < n; i++) {
      push(arr[i]);
   }
   sortStack();
   return 0;
}
