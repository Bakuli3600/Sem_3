#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // global head

// Utility: create a new node
Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// 1. Insert Operations
void insertAtBeginning(int data) {
    Node* n = newNode(data);
    n->next = head;
    head = n;
}

void insertAtEnd(int data) {
    Node* n = newNode(data);
    if (!head) { head = n; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

void insertAtPosition(int data, int pos) {
    if (pos <= 1 || !head) { insertAtBeginning(data); return; }
    Node* temp = head;
    for (int i=1; temp->next && i<pos-1; i++) temp = temp->next;
    Node* n = newNode(data);
    n->next = temp->next;
    temp->next = n;
}

// Utility: print list
void display(Node* h) {
    while(h) { printf("%d -> ", h->data); h = h->next; }
    printf("NULL\n");
}

// 2. Reverse Linked List
void reverseIterative() {
    Node* prev = NULL, *cur = head, *next = NULL;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

Node* reverseRecursiveHelper(Node* cur, Node* prev) {
    if (!cur) return prev;
    Node* next = cur->next;
    cur->next = prev;
    return reverseRecursiveHelper(next, cur);
}

void reverseRecursive() {
    head = reverseRecursiveHelper(head, NULL);
}

// 3. Find middle node
Node* findMiddle(Node* h) {
    Node* slow = h, *fast = h;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 4. Merge two sorted lists
Node* mergeSorted(Node* l1, Node* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->data < l2->data) { l1->next = mergeSorted(l1->next, l2); return l1; }
    else { l2->next = mergeSorted(l1, l2->next); return l2; }
}

// 5. Detect cycle and return start node
Node* detectCycle(Node* h) {
    Node* slow = h, *fast = h;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) { // cycle detected
            slow = h;
            while(slow != fast) { slow=slow->next; fast=fast->next; }
            return slow;
        }
    }
    return NULL;
}

// 6. Remove duplicates from sorted list
void removeDuplicates() {
    Node* temp = head;
    while(temp && temp->next) {
        if(temp->data == temp->next->data) {
            Node* dup = temp->next;
            temp->next = dup->next;
            free(dup);
        } else temp = temp->next;
    }
}

// 7. Check palindrome using stack
bool isPalindrome() {
    int arr[1000], top=-1;
    Node* temp=head;
    while(temp){ arr[++top]=temp->data; temp=temp->next; }
    temp=head;
    for(int i=top; i>=0; i--) {
        if(arr[i]!=temp->data) return false;
        temp=temp->next;
    }
    return true;
}

// 8. Remove nth node from end
void removeNthFromEnd(int n) {
    Node* dummy=newNode(0);
    dummy->next=head;
    Node* first=dummy, *second=dummy;
    for(int i=0;i<=n;i++) first=first->next;
    while(first){ first=first->next; second=second->next; }
    Node* del=second->next;
    second->next=del->next;
    if(del==head) head=head->next;
    free(del); free(dummy);
}

// 9. Split even/odd indexed nodes
void splitEvenOdd(Node* h, Node** evenHead, Node** oddHead) {
    *evenHead=*oddHead=NULL;
    Node *evenTail=NULL, *oddTail=NULL;
    int idx=0;
    while(h) {
        if(idx%2==0) {
            if(!*evenHead) *evenHead=h;
            else evenTail->next=h;
            evenTail=h;
        } else {
            if(!*oddHead) *oddHead=h;
            else oddTail->next=h;
            oddTail=h;
        }
        h=h->next; idx++;
    }
    if(evenTail) evenTail->next=NULL;
    if(oddTail) oddTail->next=NULL;
}

// ------------------- TESTING ------------------
int main() {
    // create list: 10->20->30->40->50
    insertAtEnd(10); insertAtEnd(20); insertAtEnd(30); insertAtEnd(40); insertAtEnd(50);
    printf("Original List:\n"); display(head);

    // insert
    insertAtBeginning(5);
    insertAtPosition(25,3);
    printf("\nAfter Insertions:\n"); display(head);

    // reverse iterative
    reverseIterative(); printf("\nReversed Iterative:\n"); display(head);
    reverseRecursive(); printf("\nReversed Recursive:\n"); display(head);

    // middle
    Node* mid=findMiddle(head);
    printf("\nMiddle Node: %d\n", mid->data);

    // merge sorted
    Node* l1=newNode(1); l1->next=newNode(3); l1->next->next=newNode(5);
    Node* l2=newNode(2); l2->next=newNode(4); l2->next->next=newNode(6);
    Node* merged=mergeSorted(l1,l2);
    printf("\nMerged List:\n"); display(merged);

    // remove duplicates (prepare sorted list with dupes)
    head=NULL; insertAtEnd(1); insertAtEnd(1); insertAtEnd(2); insertAtEnd(3); insertAtEnd(3);
    printf("\nBefore Removing Duplicates:\n"); display(head);
    removeDuplicates();
    printf("After Removing Duplicates:\n"); display(head);

    // palindrome check
    head=NULL; insertAtEnd(1); insertAtEnd(2); insertAtEnd(2); insertAtEnd(1);
    printf("\nList for Palindrome Check:\n"); display(head);
    printf("Is Palindrome? %s\n", isPalindrome()? "Yes":"No");

    // remove nth from end
    head=NULL; insertAtEnd(10); insertAtEnd(20); insertAtEnd(30); insertAtEnd(40);
    printf("\nBefore Removing nth from End:\n"); display(head);
    removeNthFromEnd(2);
    printf("After Removing 2nd from End:\n"); display(head);

    // split even/odd
    head=NULL; for(int i=1;i<=6;i++) insertAtEnd(i);
    Node *even=NULL,*odd=NULL;
    splitEvenOdd(head,&even,&odd);
    printf("\nEven Indexed List:\n"); display(even);
    printf("Odd Indexed List:\n"); display(odd);

    return 0;
}
