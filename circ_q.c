#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int f = 0, r = -1, count = 0, q[MAX];

void insert(int q[], int val) {
    if (count == MAX)
        printf("\nQueue Overflow\n");
    else {
        r = (r + 1) % MAX;
        q[r] = val;
        count++;
        printf("\n%d is inserted\n", val);
    }
}

void delete(int q[]) {
    if (count == 0)
        printf("\nQueue Underflow\n");
    else {
        printf("\n%d is deleted\n", q[f]);
        f = (f + 1) % MAX;
        count=count-1;
    }
}

void display(int q[]) {
    if (count == 0)
        printf("Queue is Empty\n");
    else {
        int i, k = f;
        for (i = 1; i <= count; i++) {
            printf("%d\t", q[k]);
            k = (k + 1) % MAX;
        }
        printf("\n");
    }
}

void main() {
    int option, val;
    do {
        printf("\n**Circular Queue Operations");
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nThe value to insert: ");
                scanf("%d", &val);
                insert(q, val);
                break;
            case 2:
                delete(q);
                break;
            case 3:
                printf("Queue contains:\n");
                display(q);
                break;
            case 4:
                exit(0);
        }
    } while (option!=4);
}