#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//  insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//  print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//  to sort the linked list using Bubble Sort
void sortList(struct Node* head) {
    if (head == NULL) return;

    struct Node* i;
    struct Node* j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

//  reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
}

//  concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    
    insertEnd(&list1, 5);
    insertEnd(&list1, 2);
    insertEnd(&list1, 9);
    insertEnd(&list1, 1);
    
   
    insertEnd(&list2, 3);
    insertEnd(&list2, 8);
    insertEnd(&list2, 4);
    
    printf("List 1: ");
    printList(list1);
    
    printf("List 2: ");
    printList(list2);
    
  
    sortList(list1);
    printf("List 1 after sorting: ");
    printList(list1);
    
  
    reverseList(&list1);
    printf("List 1 after reversing: ");
    printList(list1);
    
   
    concatenateLists(&list1, list2);
    printf("List 1 after concatenation with List 2: ");
    printList(list1);
    
    return 0;
}



List 1: 5 -> 2 -> 9 -> 1 -> NULL
List 2: 3 -> 8 -> 4 -> NULL
List 1 after sorting: 1 -> 2 -> 5 -> 9 -> NULL
List 1 after reversing: 9 -> 5 -> 2 -> 1 -> NULL
List 1 after concatenation with List 2: 9 -> 5 -> 2 -> 1 -> 3 -> 8 -> 4 -> NULL


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Stack {
    struct Node* top;  
};

// Queue using Linked List (FIFO)
struct Queue {
    struct Node* front;  
    struct Node* rear;   
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//  Stack Operations

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Push an element to the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d to the stack\n", data);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;  
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;  // Error code for empty stack
    }
    return stack->top->data;
}

//  Queue Operations 

// Initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Enqueue an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("Enqueued %d to the queue\n", data);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d to the queue\n", data);
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  
    }
    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Dequeued %d from the queue\n", dequeuedValue);
    return dequeuedValue;
}

// Get the front element of the queue
int front(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot view front.\n");
        return -1;  
    }
    return queue->front->data;
}



// Print the stack
void printStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Print the queue
void printQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    struct Stack stack;
    struct Queue queue;
    
    // Initialize stack and queue
    initStack(&stack);
    initQueue(&queue);
    
    // Stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);
    
    peek(&stack);
    pop(&stack);
    printStack(&stack);
    
    // Queue operations
    enqueue(&queue, 100);
    enqueue(&queue, 200);
    enqueue(&queue, 300);
    printQueue(&queue);
    
    front(&queue);
    dequeue(&queue);
    printQueue(&queue);
    
    return 0;
}


Pushed 10 to the stack
Pushed 20 to the stack
Pushed 30 to the stack
Stack: 30 -> 20 -> 10 -> NULL
Peeked at stack: 30
Popped 30 from the stack
Stack: 20 -> 10 -> NULL
Enqueued 100 to the queue
Enqueued 200 to the queue
Enqueued 300 to the queue
Queue: 100 -> 200 -> 300 -> NULL
Front of queue: 100
Dequeued 100 from the queue
Queue: 200 -> 300 -> NULL





   
   
