#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

typedef struct node *NODE;
NODE first = NULL;

NODE insert(NODE first) {
    NODE temp;
    int item;
    printf("\nThe value to insert: ");
    scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    temp->info = item;
    temp->link = first;
    first = temp;
    printf("%d is inserted into the list\n", temp->info);
    return first;
}

NODE delete_sp(NODE first) {
    NODE cur, prev;
    int key;
    printf("\nEnter the value to be deleted: ");
    scanf("%d", &key);

    if (first == NULL) {
        printf("List is underflow\n");
        return first;
    }

    if (key == first->info) {
        cur = first;
        first = first->link;
        printf("%d is deleted from the list\n", cur->info);
        free(cur);
        return first;
    }

    cur = first;
    prev = NULL;

    while (cur != NULL && cur->info != key) {
        prev = cur;
        cur = cur->link;
    }

    if (cur == NULL) {
        printf("Key not found\n");
        return first;
    }

    prev->link = cur->link;
    printf("%d is deleted from the list\n", cur->info);
    free(cur);
    return first;
}

void display(NODE first) {
    NODE cur;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Contents of the list are: ");
    cur = first;

    while (cur != NULL) {
        printf("%d\t", cur->info);
        cur = cur->link;
    }
    printf("\n");
}

void main() {
    int option;
    do {
        printf("\n********** Linked List Operations *********\n");
        printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                first = insert(first);
                break;
            case 2:
                first = delete_sp(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (option!=4);
}