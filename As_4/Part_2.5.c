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

// Recursive function to find middle
Node* findMiddle(Node* slow, Node* fast) {
    // Base case: if fast reaches end or one step before end
    if (fast == NULL || fast->next == NULL)
        return slow;

    // Recursive call: slow moves 1 step, fast moves 2 steps
    return findMiddle(slow->next, fast->next->next);
}

// Wrapper function
Node* getMiddle(Node* head) {
    if (head == NULL) return NULL;
    return findMiddle(head, head);
}

// Function to print list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Linked List: ");
    printList(head);

    Node* middle = getMiddle(head);
    if (middle != NULL)
        printf("Middle Node: %d\n", middle->data);

    return 0;
}
