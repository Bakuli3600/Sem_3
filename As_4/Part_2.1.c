#include <stdio.h>
#include <stdlib.h>

// Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to find length of linked list
int length(Node* head) {
    if (head == NULL) 
        return 0;  // base case
    return 1 + length(head->next); // recursive case
}

int main() {
    // Creating linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Length of Linked List: %d\n", length(head));

    return 0;
}
