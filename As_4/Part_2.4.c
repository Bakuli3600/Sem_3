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

// Recursive function to reverse linked list
Node* reverseList(Node* head) {
    // Base case: empty list or last node
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse rest of the list
    Node* newHead = reverseList(head->next);

    // Put current node at the end
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
