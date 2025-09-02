#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
typedef struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
} Node;

// Function prototypes
void insertNode(Node** head, int value);
void deleteNode(Node** head, int value);
void displayList(Node* head);
void reverseList(Node** head);
int searchNode(Node* head, int value);

// Function to insert a node at the end of the linked list
void insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // List is empty, new node becomes head
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end
        }
        temp->next = newNode; // Append the new node
    }
    printf("Node %d inserted successfully.\n", value);
}

// Function to delete a node by value
void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Node %d deleted successfully.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node %d deleted successfully.\n", value);
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("List reversed successfully.\n");
}

// Function to search for a node by value
int searchNode(Node* head, int value) {
    Node* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // Value not found
}

// Main function with menu-driven interface
int main() {
    Node* head = NULL; // Head pointer moved inside main (Bonus)
    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert a node at the end\n");
        printf("2. Delete a node by value\n");
        printf("3. Display the list\n");
        printf("4. Reverse the list\n");
        printf("5. Search for a node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                reverseList(&head);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                position = searchNode(head, value);
                if (position != -1)
                    printf("Node %d found at position %d.\n", value, position);
                else
                    printf("Node %d not found in the list.\n", value);
                break;
            case 6:
                printf("Exiting program.\n");
                // Free all nodes before exiting
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
