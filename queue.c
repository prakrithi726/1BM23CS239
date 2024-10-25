1) LINEAR QUEUE
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full! Overflow !\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Underflow!\n");
        return -1;
    } else {
        int item = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        printf("Deleted %d\n", item);
        return item;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
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
                printf("Invalid choice! Please try again.\n");
        }
    }
}

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 2
Inserted 2

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 4
Inserted 4

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 5
Inserted 5

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice:
1
Enter the value to insert: 7
Inserted 7

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 6
Inserted 6

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 5
Queue is full! Overflow !

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements are: 2 4 5 7 6

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 2

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 4

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 5

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 7

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 6

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Queue is empty! Underflow!

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue is empty!

Queue Operations:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting...

Process returned 0 (0x0)   execution time : 243.398 s
Press any key to continue.
===================================================================================================================================================================================
2)CIRCULAR QUEUE:
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int items[SIZE], front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n%d is inserted into the queue.\n", element);
    }
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty!!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\n%d is deleted from the queue.\n", element);
        return element;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is empty!!\n");
    } else {
        printf("\nFront position: %d\n", front);
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[i]);
    }
}

int main() {
    int choice, element;
    while (1) {
        printf("\n****** Circular Queue Operations ******\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element != -1)
                    printf("%d element is deleted.\n", element);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 2

2 is inserted into the queue.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 5

5 is inserted into the queue.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 7

7 is inserted into the queue.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 6

6 is inserted into the queue.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 8

8 is inserted into the queue.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 6

Queue is full!!

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Front position: 0
Queue elements: 2 5 7 6 8

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

2 is deleted from the queue.
2 element is deleted.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

5 is deleted from the queue.
5 element is deleted.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

7 is deleted from the queue.
7 element is deleted.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

6 is deleted from the queue.
6 element is deleted.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

8 is deleted from the queue.
8 element is deleted.

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2

Queue is empty!!

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3

Queue is empty!!

****** Circular Queue Operations ******
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4

Process returned 0 (0x0)   execution time : 29.580 s
Press any key to continue.
