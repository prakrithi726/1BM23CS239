#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


struct Node* createListFromArray(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}


void insertLeft(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}


void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;


    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }


    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value;
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Create List from Array\n");
        printf("2. Insert Node at the Beginning\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                head = createListFromArray(arr, n);
                printf("List created from array: ");
                displayList(head);
                break;

            case 2:

                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertLeft(&head, value);
                printf("List after inserting node at the beginning: ");
                displayList(head);
                break;

            case 3:

                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                printf("List after deletion: ");
                displayList(head);
                break;

                            case 4:

                printf("Current list: ");
                displayList(head);
                break;

            case 5:

                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 5);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
