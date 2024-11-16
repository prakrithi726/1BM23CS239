#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}
struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}
struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}
struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val) {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}
struct node *delete_beg(struct node *start) {
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("Enter the value of the node to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val) {
        start = delete_beg(start);
        return start;
    } else {
        while (ptr->data != val) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}
struct node *delete_after(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("Enter the value after which the node has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    while (preptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}
int main() {
    int option;
    do {
        printf("\n\n *****MAIN MENU*****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: start = create_ll(start);
                    printf("LINKED LIST CREATED");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_beg(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = insert_before(start);
                    break;
            case 6: start = insert_after(start);
                    break;
            case 7: start = delete_beg(start);
                    break;
            case 8: start = delete_end(start);
                    break;
            case 9: start = delete_node(start);
                    break;
            case 10: start = delete_after(start);
                     break;
        }
    } while (option != 11);
    return 0;
}
=====================================================================
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 1
Enter -1 to end
Enter the data: 1
Enter the data: 2
Enter the data: 3
Enter the data: -1
LINKED LIST CREATED
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 3
Enter the data: 0
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
0 -> 1 -> 2 -> 3 -> NULL
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 4
Enter the data: 4
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
0 -> 1 -> 2 -> 3 -> 4 -> NULL
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 5
Enter the data: 2
Enter the value before which the data has to be inserted: 2
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
0 -> 1 -> 2 -> 2 -> 3 -> 4 -> NULL
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 6
Enter the data: 6
Enter the value after which the data has to be inserted: 4
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
0 -> 1 -> 2 -> 2 -> 3 -> 4 -> 6 -> NULL
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 7
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 8
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
1 -> 2 -> 2 -> 3 -> 4 -> NULL
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 9
Enter the value of the node to be deleted: 2
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 10
Enter the value after which the node has to be deleted: 2
 *****MAIN MENU*****
 1: Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11: EXIT
 Enter your option: 2
1 -> 2 -> 4 -> NULL
 *****MAIN MENU*****
  Create a list
 2: Display the list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node before a given node
 6: Add a node after a given node
 7: Delete a node from the beginning
 8: Delete a node from the end
 9: Delete a given node
 10: Delete a node after a given node
 11.EXIT
 Enter your option: 11
