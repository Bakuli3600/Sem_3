#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Forward declaration
bool isBalanced(const char *str, int *i);

bool isOpenParenthesis(const char *str, int *i) {
    (*i)++; // move past '('
    if (!isBalanced(str, i)) 
        return false;
    if (str[*i] == ')') {
        (*i)++; // matched closing
        return true;
    }
    return false; // no closing found
}

bool isBalanced(const char *str, int *i) {
    while (str[*i] != '\0' && str[*i] != ')') {
        if (str[*i] == '(') {
            if (!isOpenParenthesis(str, i))
                return false;
        } else {
            (*i)++; // skip non-parenthesis chars
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string with parentheses: ");
    scanf("%s", str);

    int i = 0;
    if (isBalanced(str, &i) && str[i] == '\0')
        printf("Parentheses are balanced!\n");
    else
        printf("Parentheses are NOT balanced!\n");

    return 0;
}
