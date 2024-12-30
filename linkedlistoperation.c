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

void findMax(NODE first) {
    int max;
    NODE ptr;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    max = first->info;
    ptr = first;
    while (ptr != NULL) {
        if (ptr->info > max) {
            max = ptr->info;
        }
        ptr = ptr->link;
    }
    printf("Maximum element of the list is %d\n", max);
}

void findMin(NODE first) {
    int min;
    NODE ptr;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    min = first->info;
    ptr = first;
    while (ptr != NULL) {
        if (ptr->info < min) {
            min = ptr->info;
        }
        ptr = ptr->link;
    }
    printf("Minimum element of the list is %d\n", min);
}

void findSum(NODE first) {
    int sum = 0;
    NODE ptr;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = first;
    while (ptr != NULL) {
        sum += ptr->info;
        ptr = ptr->link;
    }
    printf("Sum of the elements in the list is %d\n", sum);
}

void main() {
    int option;
    do {
        printf("\n********** Linked List Operations *********\n");
        printf("1. Insert\t2. Display\t3. FindMax\t4. FindMin\t5. FindSum\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                first = insert(first);
                break;
            case 2:
                display(first);
                break;
            case 3:
                findMax(first);
                break;
            case 4:
                findMin(first);
                break;
            case 5:
                findSum(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (option!=6);
}