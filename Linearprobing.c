
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
    int key;
    char name[50];
    char position[50];
} Employee;

Employee hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE];

void insert(int key, const char* name, const char* position) {
    int address = key % TABLE_SIZE;
    while (isOccupied[address]) {
        address = (address + 1) % TABLE_SIZE;
    }
    hashTable[address].key = key;
    strcpy(hashTable[address].name, name);
    strcpy(hashTable[address].position, position);
    isOccupied[address] = 1;
}

Employee* search(int key) {
    int address = key % TABLE_SIZE;
    int startAddress = address;
    while (isOccupied[address]) {
        if (hashTable[address].key == key) {
            return &hashTable[address];
        }
        address = (address + 1) % TABLE_SIZE;
        if (address == startAddress) {
            break;
        }
    }
    return NULL;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i]) {
            printf("[%02d]: (Key: %d, Name: %s, Position: %s)\n", i, hashTable[i].key, hashTable[i].name, hashTable[i].position);
        } else {
            printf("[%02d]: NULL\n", i);
        }
    }
}










int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        isOccupied[i] = 0;
    }

    int continueInput = 1;
    while (continueInput) {
        int key;
        char name[50], position[50];

        printf("\nEnter employee details:\n");
        printf("Enter key: ");
        scanf("%d", &key);
        getchar();

        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter position: ");
        fgets(position, sizeof(position), stdin);
        position[strcspn(position, "\n")] = '\0';

        insert(key, name, position);

        printf("\nDo you want to add another employee? (1 for yes, 0 for no): ");
        scanf("%d", &continueInput);
        getchar();
    }

    printf("\nHash Table:\n");
    displayHashTable();

    int searchKey;
    printf("\nEnter the key to search for: ");
    scanf("%d", &searchKey);

    Employee* result = search(searchKey);
    if (result != NULL) {
        printf("\nEmployee found: Key: %d, Name: %s, Position: %s\n", result->key, result->name, result->position);
    } else {
        printf("\nEmployee with key %d not found.\n", searchKey);
    }

    return 0;
}









OUTPUT : 
Enter employee details:
Enter key: 1
Enter name: Alice
Enter position: Manager

Do you want to add another employee? (1 for yes, 0 for no): 1

Enter employee details:
Enter key: 2
Enter name: Bob
Enter position: Engineer

Do you want to add another employee? (1 for yes, 0 for no): 1

Enter employee details:
Enter key: 3
Enter name: Charlie
Enter position: Technician

Do you want to add another employee? (1 for yes, 0 for no): 0

Hash Table:
[00]: (Key: 1, Name: Alice, Position: Manager)
[01]: (Key: 2, Name: Bob, Position: Engineer)
[02]: (Key: 3, Name: Charlie, Position: Technician)
[03]: NULL
[04]: NULL
[05]: NULL
[06]: NULL
[07]: NULL
[08]: NULL
[09]: NULL

Enter the key to search for: 2

Employee found: Key: 2, Name: Bob, Position: Engineer

   
