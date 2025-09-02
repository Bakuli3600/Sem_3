#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Recursive Array Sum
int arraySum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + arraySum(arr, n - 1);
}

// 2. Recursive String Reversal
void reverseString(char str[], int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

// 3. Recursive Palindrome Check (ignores spaces & case)
int isPalindrome(char str[], int start, int end) {
    while (start < end && !isalnum(str[start])) start++;
    while (start < end && !isalnum(str[end])) end--;
    if (start >= end) return 1;

    if (tolower(str[start]) != tolower(str[end]))
        return 0;

    return isPalindrome(str, start + 1, end - 1);
}

// 4. Recursive Power Function
int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

// 5. Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// 6. String Permutations
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[], int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]); // backtrack
    }
}

int main() {
    int choice;
    do {
        printf("\n===== Recursive Functions Menu =====\n");
        printf("1. Array Sum\n");
        printf("2. String Reversal\n");
        printf("3. Palindrome Check\n");
        printf("4. Power Function\n");
        printf("5. Tower of Hanoi\n");
        printf("6. String Permutations\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: {
                int arr[] = {1, 2, 3, 4, 5};
                int n = sizeof(arr) / sizeof(arr[0]);
                printf("Array sum = %d\n", arraySum(arr, n));
                break;
            }
            case 2: {
                char str[100];
                printf("Enter a string: ");
                scanf("%[^\n]", str);
                reverseString(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;
            }
            case 3: {
                char str[100];
                printf("Enter a string: ");
                scanf("%[^\n]", str);
                if (isPalindrome(str, 0, strlen(str) - 1))
                    printf("Palindrome\n");
                else
                    printf("Not Palindrome\n");
                break;
            }
            case 4: {
                int base, exp;
                printf("Enter base and exponent: ");
                scanf("%d %d", &base, &exp);
                printf("%d^%d = %d\n", base, exp, power(base, exp));
                break;
            }
            case 5: {
                int n;
                printf("Enter number of disks: ");
                scanf("%d", &n);
                towerOfHanoi(n, 'A', 'C', 'B');
                break;
            }
            case 6: {
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);
                permute(str, 0, strlen(str) - 1);
                break;
            }
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
