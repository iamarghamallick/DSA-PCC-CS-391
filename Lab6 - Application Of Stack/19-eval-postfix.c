// Postfix evaluation

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int st[MAX];
int top = -1;

int isEmpty() { return top == -1; }

int isFull() { return top == MAX - 1; }

void push(char data) {
  if (isFull()) {
    printf("Overflow\n");
    return;
  }
  st[++top] = data;
}

char pop() {
  if (isEmpty()) {
    printf("Underflow\n");
    return '\0';
  }
  return st[top--];
}

int evaluatePostfix(char exp[]) {
  int n = strlen(exp);

  for (int i = 0; i < n; i++) {
    char item = exp[i];

    if (isdigit(item)) {
      push(item - '0');
    } else {
      int num2 = pop();
      int num1 = pop();
      switch (item) {
      case '+':
        push(num1 + num2);
        break;
      case '-':
        push(num1 - num2);
        break;
      case '*':
        push(num1 * num2);
        break;
      case '/':
        push(num1 / num2);
        break;
      default:
        break;
      }
    }
  }
  return pop();
}

int main() {
  char exp[] = "553+22+/*";
  int result = evaluatePostfix(exp);
  printf("%d\n", result);
  return 0;
}
