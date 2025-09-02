#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() { return top == -1; }
int isFull() { return top == MAX - 1; }

void push(char c) { if(!isFull()) stack[++top] = c; }
char pop() { return isEmpty() ? '\0' : stack[top--]; }

int isParenthesesMatch(char str[]) {
    top = -1; // reset stack
    for(int i=0; str[i]; i++) {
        if(str[i]=='(') push('(');
        else if(str[i]==')') {
            if(isEmpty()) return 0;
            pop();
        }
    }
    return isEmpty();
}

int main() {
    char s1[] = "(a+b)*(c+d)";
    char s2[] = "((a+b)";
    printf("%s -> %s\n", s1, isParenthesesMatch(s1) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", s2, isParenthesesMatch(s2) ? "Balanced" : "Not Balanced");
}
