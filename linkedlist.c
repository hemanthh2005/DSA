#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE first = NULL;

NODE insertRear(NODE first) {
    NODE temp, cur;
    int item;
    printf("\nThe value to insert: ");
    scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    temp->info = item;
    temp->link = temp;
    if (first == NULL) {
        first = temp;
        return first;
    }
    cur = first;
    while (cur->link != first) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = first;
    printf("%d is inserted into the list\n", temp->info);
    return first;
}

NODE deleteFront(NODE first) {
    NODE cur;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    if (first->link == first) {
        printf("%d is deleted from the list\n", first->info);
        free(first);
        first = NULL;
        return first;
    }
    cur = first;
    while (cur->link != first) {
        cur = cur->link;
    }
    cur->link = first->link;
    printf("%d is deleted from the list\n", first->info);
    free(first);
    first = cur->link;
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
    while (cur->link != first) {
        printf("%d\t", cur->info);
        cur = cur->link;
    }
    printf("%d\t", cur->info);
    printf("\n");
}

void main() {
    int option;
    do {
        printf("\n*Linked List Operations\n");
        printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                first = insertRear(first);
                break;
            case 2:
                first = deleteFront(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (option!=4);
}