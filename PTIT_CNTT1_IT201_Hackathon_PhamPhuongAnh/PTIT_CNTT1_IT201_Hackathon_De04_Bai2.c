#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#include "../../anything/CLion 2025.1.2/bin/mingw/lib/gcc/x86_64-w64-mingw32/13.1.0/include/iso646.h"

// Cau truc Mon an
typedef struct Drink {
        char drinkName[30];
        int price;
        char size;
}Drink;

// DSLK don
typedef struct Node {
        Drink *drink;
        struct Node* next;
}Node;

typedef struct Queue {
        Node *front;
        Node * rear;
}Queue;

typedef struct Stack {
        Node *top;
}Stack;

// tao moi mon an
Drink *createDrink() {
        Drink *newDrink = (Drink*)malloc(sizeof(Drink));
        fflush(stdin);
        printf(" - Nhap ten do uong: ");
        fgets(newDrink ->drinkName, 30, stdin);
        newDrink ->drinkName[strlen(newDrink ->drinkName) - 1] = '\0';
        printf(" - Nhap size: "); scanf("%c", &newDrink -> size);
        printf(" - Nhap gia do uong: "); scanf("%d", &newDrink ->price);
        return newDrink;
}

// tao moi node trong dslk don
Node *createNode(Drink *newDrink) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
                printf("\nDanh sach mon an da day !!");
                return NULL;
        }
        newNode -> drink = newDrink;
        newNode -> next = NULL;
        return newNode;
}
// push vao que
// Tao moi dslk
// Tao moi ngan xep
Stack *createStack() {
        Stack *newStack = (Stack*)malloc(sizeof(Stack));
        if (newStack == NULL) {
                printf("Cap phat bo nho that bai !");
                return NULL;
        }
        newStack -> top = NULL;
        return newStack;
}

// Tao moi hang doi
Queue *createQueue() {
        Queue *newQueue = (Queue*)malloc(sizeof(Queue));
        if (newQueue == NULL) {
                printf("Cap phat bo nho that bai !");
                return NULL;
        }
        newQueue -> front = NULL;
        newQueue -> rear = NULL;
        return newQueue;
}
// Them moi so dien thoai vao hang doi
Queue *addOrderQueue(Queue *orderQueue, Drink *orderDrink) {
        Node *newNode = createNode(orderDrink);
        if (newNode == NULL) {
                printf("Danh sach do uong da day!\n");
                return orderQueue;
        }
        if (orderQueue ->front == NULL) {
                orderQueue -> front = newNode;
                orderQueue -> rear = newNode;
        }else {
                orderQueue -> rear -> next = newNode;
                orderQueue -> rear = newNode;
        }
        return orderQueue;
}

void displayList(Queue *OrderQueue) {
        if (OrderQueue -> rear == NULL) {
                printf("Danh sach order trong!\n");
                return;
        }
        Node* current = OrderQueue ->front;
        while (current != NULL) {
                printf("%s - %d - %c\n",current -> drink -> drinkName, current -> drink ->price, current -> drink -> size);
                current = current -> next;
        }
}


int main() {
        Stack *cancelStack = createStack();
        Queue *orderQueue = createQueue();
        int choice;
        do {
                printf("\n-------RESTAURANT--------");
                printf("\n1. Them mon moi");
                printf("\n2. Huy them mon moi");
                printf("\n3. Dat lai mon vua bi huy");
                printf("\n4. Hien thi cac mon da order");
                printf("\n5. Thoat chuong trinh");
                printf("\nLua chon cua ban: ");
                scanf("%d", &choice);
                switch (choice) {
                        case 1:
                                Drink *newDrink = createDrink();
                                addOrderQueue(orderQueue, newDrink);
                                if (orderQueue ->front != NULL) {
                                        printf("Them mon moi thanh cong !!");
                                }
                                break;
                        case 2:
                                break;
                        case 3:

                                break;
                        case 4:
                                displayList(orderQueue);
                                break;
                        case 5:
                                printf("Thoat chuong trinh");
                                free(orderQueue);
                                free(cancelStack);
                                break;
                        default:
                                printf("Vui long chon yeu cau hop le");
                                break;
                }
        }while (choice != 5);
}
