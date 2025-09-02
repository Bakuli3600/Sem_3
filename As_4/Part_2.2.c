#include <stdio.h>
#include <stdlib.h>

// Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to search for an element
int search(Node* head, int target) {
    if (head == NULL)
        return 0; // Not found
    if (head->data == target)
        return 1; // Found
    return search(head->next, target);
}

int main() {
    // Create linked list: 5 -> 15 -> 25 -> 35 -> NULL
    Node* head = createNode(5);
    head->next = createNode(15);
    head->next->next = createNode(25);
    head->next->next->next = createNode(35);

    int target = 25;
    if (search(head, target))
        printf("%d found in the linked list.\n", target);
    else
        printf("%d not found in the linked list.\n", target);

    target = 40;
    if (search(head, target))
        printf("%d found in the linked list.\n", target);
    else
        printf("%d not found in the linked list.\n", target);

    return 0;
}
