#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE first = NULL;

NODE insert(NODE first) {
    NODE temp, cur, prev;
    int item;

    printf("\nEnter the value to be inserted:\n");
    scanf("%d", &item);

    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    temp->info = item;
    temp->link = NULL;

    if (first == NULL) {
        first = temp;
        printf("%d is inserted into the list\n", temp->info);
        return first;
    }

    prev = NULL;
    cur = first;
    while (cur != NULL && cur->info < item) {
        prev = cur;
        cur = cur->link;
    }

    if (prev == NULL) {
        temp->link = first;
        first = temp;
    } else {
        temp->link = cur;
        prev->link = temp;
    }

    printf("%d is inserted into the list\n", temp->info);
    return first;
}

void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("\nThe list is empty\n");
        return;
    }

    printf("\nThe elements in the list are:\n");
    temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                first = insert(first);
                break;
            case 2:
                display(first);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}