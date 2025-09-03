#include <stdio.h>

#define MAX 5

int q[MAX];
int f = -1;
int r = -1;

int empty() {
    return f == -1;
}

int full() {
    return ((r + 1) % MAX) == f;
}

void enq(int val) {
    if (full()) {
        printf("Queue full\n");
        return;
    }
    if (empty()) {
        f = 0;
        r = 0;
    } else {
        r = (r + 1) % MAX;
    }
    q[r] = val;
}

int deq() {
    if (empty()) {
        printf("Queue empty\n");
        return -1;
    }
    int val = q[f];
    if (f == r) {
        // Queue has become empty
        f = r = -1;
    } else {
        f = (f + 1) % MAX;
    }
    return val;
}

void show() {
    if (empty()) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    while (1) {
        printf("%d ", q[i]);
        if (i == r) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("-------Queue Menu-------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Show the full queue\n");
        printf("6. Exit\n");
        printf("Choose your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enq(val);
                break;
            case 2:
                val = deq();
                if (val != -1) {
                    printf("Dequeued: %d\n", val);
                }
                break;
            case 3:
                if (empty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                if (full()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 5:
                show();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

