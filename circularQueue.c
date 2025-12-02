#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// ------------------------------
// INSERT (ENQUEUE)
// ------------------------------
void enqueue(int value) {

    // Condition for full queue
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue is FULL!\n");
        return;
    }

    // First element
    if (front == -1) {
        front = rear = 0;
    }
    else {
        // move rear in circular manner
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// ------------------------------
// DELETE (DEQUEUE)
// ------------------------------
void dequeue() {

    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    // If only one element left
    if (front == rear) {
        front = rear = -1;
    }
    else {
        // move front in circular manner
        front = (front + 1) % MAX;
    }
}

// ------------------------------
// DISPLAY
// ------------------------------
void display() {

    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue: ");

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) break;  // stop after reaching last element

        i = (i + 1) % MAX;  // move in circular manner
    }

    printf("\n");
}

// ------------------------------
// MAIN FUNCTION
// ------------------------------
int main() {

    int choice, value;

    while (1) {

        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
