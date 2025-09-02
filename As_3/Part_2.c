#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

int isEmpty() { return top == NULL; }

void push(char c) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = c;
    n->next = top;
    top = n;
}

char pop() {
    if(isEmpty()) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int isParenthesesMatchLL(char str[]) {
    top = NULL; // reset
    for(int i=0; str[i]; i++){
        if(str[i]=='(') push('(');
        else if(str[i]==')') {
            if(isEmpty()) return 0;
            pop();
        }
    }
    int res = isEmpty();
    while(!isEmpty()) pop(); // free remaining nodes
    return res;
}

int main() {
    char s1[] = "(x+y)*(z+w)";
    char s2[] = "((x+y))(";
    printf("%s -> %s\n", s1, isParenthesesMatchLL(s1) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", s2, isParenthesesMatchLL(s2) ? "Balanced" : "Not Balanced");
}
