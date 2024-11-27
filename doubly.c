#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head_ref;

    if (*head_ref == NULL){
        *head_ref = newNode;
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void insertLeft(struct Node** head_ref, int target, int data) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head_ref = newNode;
    }
    temp->prev = newNode;
}


void deleteNode(struct Node** head_ref, int target) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head_ref = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int choice, data, target;

    do {
        printf("\n-- Menu --\n");
        printf("1. Append a node\n");
        printf("2. Insert a node to the left of a given node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 2:
                printf("Enter the target value: ");
                scanf("%d", &target);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertLeft(&head, target, data);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &target);
                deleteNode(&head, target);
                break;

            case 4:
                printf("List contents: ");
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
//output
  -- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 1
Enter the value to append: 1

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 1
Enter the value to append: 5

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 1
Enter the value to append: 7

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 1
Enter the value to append: 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 3
Enter the value to delete: 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 1
Enter the value to append: 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 4
List contents: 1 <-> 5 <-> 7 <-> 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 3
Enter the value to delete: 7

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 4
List contents: 1 <-> 5 <-> 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 2
Enter the target value: 1
Enter the value to insert: 8

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 4
List contents: 8 <-> 1 <-> 5 <-> 9

-- Menu --
1. Append a node
2. Insert a node to the left of a given node
3. Delete a node by value
4. Display the list
5. Exit
Enter your choice: 5
Exiting program.

Process returned 0 (0x0)   execution time : 73.135 s
Press any key to continue.
//leetcode
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    
    int length = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    
    int values[length];
    temp = head;
    for (int i = 0; i < length; i++) {
        values[i] = temp->val;
        temp = temp->next;
    }
    
    int left = 0;
    int right = length - 1;
    while (left < right) {
        if (values[left] != values[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

