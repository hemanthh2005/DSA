#include <stdio.h>
#define max 3

int q[max];
int f = 0, r = -1;

void insert_rear(int q[], int val);
void delete_front(int q[]);
void display(int q[]);

void main() {
    int option, val;
    do {
        printf("\n*Queue Operation*\n");
        printf("1.insert\t2.delete\t3.display\t4.exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the number to be inserted: ");
                scanf("%d", &val);
                insert_rear(q, val);
                break;
            case 2:
                delete_front(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (option != 4);
}

void insert_rear(int q[], int val) {
    if (r == max - 1) {
        printf("Queue is overflow\n");
    } else {
        r = r + 1;
        q[r] = val;
        printf("%d is inserted into queue\n", val);
    }
}

void delete_front(int q[]) {
    if (f > r) {
        printf("Queue is underflow\n");
    } else {
        int val=q[f];
        f = f + 1;
        printf("%d is deleted from queue\n", val);
    }
}

void display(int q[]) {
    if (f > r) {
        printf("Queue is empty\n");
    } else {
        printf("Content of the queue are: ");
        for (int i = f; i <= r; i++) {
            printf("%d\t", q[i]);
        }
        printf("\n");

    }
}