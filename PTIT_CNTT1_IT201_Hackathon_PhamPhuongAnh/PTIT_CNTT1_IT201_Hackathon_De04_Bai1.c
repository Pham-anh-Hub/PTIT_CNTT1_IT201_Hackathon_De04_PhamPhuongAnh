#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// Cau truc Mon an
typedef struct Dish {
        int id;
        char name[30];
        char category[30];
        int price;
}Dish;

// DSLK don
typedef struct Node {
        Dish *dish;
        struct Node* next;
}Node;

// dslk doi
typedef struct dNode {
        Dish *dish;
        struct Node* next;
        struct Node *prev;
}dNode;

// tao moi mon an
Dish *createDish() {
        Dish *newDish = (Dish*)malloc(sizeof(Dish));

        printf(" - Nhap ID mon an: ");
        scanf("%d", &newDish -> id);
        fflush(stdin);
        printf(" - Nhap ten mon an: ");
        fgets(newDish ->name, 30, stdin);
        newDish -> name[strlen(newDish ->name) - 1] = '\0';
        printf(" - Nhap danh muc mon an: ");
        fgets(newDish ->category, 30, stdin);
        newDish -> category[strlen(newDish ->category) - 1] = '\0';
        printf(" - Nhap gia mon an: "); scanf("%d", &newDish -> price);
        return newDish;
}

// tao moi node trong dslk don
Node *createNode(Dish *newDish) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
                printf("\nDanh sach mon an da day !!");
                return NULL;
        }
        newNode -> dish = newDish;
        newNode -> next = NULL;
        return newNode;
}
// Tao moi trong ds lk doi
dNode *create_dNode(Dish *doneDish) {
        dNode *newNode = (dNode*)malloc(sizeof(dNode));
        if (newNode == NULL) {
                printf("\nDanh sach mon an da day !!");
                return NULL;
        }
        newNode -> dish = doneDish;
        newNode -> next = NULL;
        newNode -> prev = NULL;
        return newNode;
}

// push vao ds lk don
Node *pushToSingle(Node *head, Dish *newDish) {
        // Tao mon an moi
        Node *newNode = createNode(newDish);
        if (newNode != NULL) {
                if (head == NULL) {
                        return newNode;
                }else {
                        Node *current = head;
                        while (current -> next != NULL) {
                                current = current -> next;
                        }
                        // current hien tai dang tro den NULL
                        current -> next = newNode;
                        return head;
                }
        }
}

// push vao dslk doi, bao gom d-head va mon an can day vao
dNode *pushToDouble(dNode *d_head, Dish *dish) {
        // tao dNode moi
        dNode *doneNode = create_dNode(dish);

        if (doneNode == NULL) {
                printf("Danh sach mon ngung ban da day !!");
                return d_head;
        }
        if (d_head == NULL) {
                return doneNode;
        }else {
                dNode *current = d_head;
                while (current -> next != NULL) {
                        current = current -> next;
                }
                current -> next = doneNode;
                return d_head;
        }
}
// Cap nhat thong tin mon an Theo ID (Tên,danh mục và giá)
Node * updateDish(Node *head, int ID) {
        if (head == NULL) {
                printf("Danh sach mon an rong");
                return NULL;
        }
        // lay thong tin moi
        char newName[30], newCategory[30];
        int newPrice;
        fflush(stdin);
        printf(" - Nhap ten moi cho mon an: ");
        fgets(newName, 30, stdin);
        newName[strlen(newName) - 1] = '\0';
        printf(" - Nhap danh muc cho mon an: ");
        fgets(newCategory, 30, stdin);
        newCategory[strlen(newCategory) - 1] = '\0';
        printf(" - Nhap gia cho mon an: ");
        scanf("%d", &newPrice);

        // TH mon can cap nhat la head
        if (head -> dish ->id == ID) {
                strcpy(head -> dish -> name, newName);
                strcpy(head -> dish -> category, newCategory);
                head -> dish -> price = newPrice;
                printf("Cap nhat mon an thanh cong!!");
                return head;
        }
        // TH mon an can cap nhat nam o giua hoac cuoi
        Node *current = head;
        while (current != NULL) {
                if (current -> dish -> id == ID) {
                        strcpy(current -> dish -> name, newName);
                        strcpy(current -> dish -> category, newCategory);
                        current -> dish -> price = newPrice;
                        printf("Cap nhat mon an thanh cong!!");
                        return head;
                }
                current = current -> next;
        }
}

// Tra ve mon an da ban het
Dish *saleOffDish(Node *head, int ID) {
        // check rong
        if (head == NULL) {
                printf("\nDanh sach mon an rong !!");
                return NULL;
        }
        // TH mon an da ban het nam o dau
        if (head -> dish -> id == ID) {
                Dish *doneDish = head -> dish;
                Node *temp = head;
                head = head -> next;
                free(temp);

                return doneDish;
        }
        // TH mon an da ban het nam o giua hoac cuoi
        Node * current = head;
        while (current -> next != NULL) {
                if (current -> next -> dish -> id == ID) {
                        Dish *donedish = current -> next ->dish;
                        Node *temp = current -> next;
                        current -> next = temp -> next;
                        free(temp);
                        return donedish;
                }
                current = current -> next;
        }
}

// Hien thi danh sach mon an
void displayDish(Node *head) {
        if (head == NULL) {
                printf("\nDanh sach mon an rong");
                return;
        }
        Node *current = head;
        printf("\tDanh sach mon an\n");
        while (current != NULL) {
                printf("\n %d - %s -  %s -  %d",
                        current->dish->id,
                        current->dish->name,
                        current->dish->category,
                        current->dish->price);
                current = current -> next;
        }
}
void displayDoneDish(dNode *dHead) {
        if (dHead == NULL) {
                printf("Danh sach mon an rong");
                return;
        }
        dNode *current = dHead;
        printf("\tDanh sach mon an\n");
        while (current != NULL) {
                printf("\n %d - %s -  %s -  %d",
                        current->dish->id,
                        current->dish->name,
                        current->dish->category,
                        current->dish->price);
                current = current ->next;
        }
}

// Tim kiem mon an theo ten
Dish *findTargetDish(Node *head, char target[30]) {
        if (head == NULL) {
                printf("\nDanh sach mon an trong !");
                return NULL;
        }
        Node *current = head;
        while (current != NULL) {
                if (strcmp(current -> dish ->name, target) == 0 ) {
                        return current -> dish;
                }
                current = current -> next;
        }
}

// sap xep
Node *sort(Node *head) {
        Node *i = head;
        while (i!=NULL) {
                Node *j = head;
                while (j -> next != NULL) {
                        if (j -> dish -> price > j-> next -> dish -> price) {
                                Dish *temp = j -> dish;
                                j -> dish = j -> next -> dish;
                                j -> next -> dish = temp;
                        }
                        j = j -> next;
                }
                i = i -> next;
        }
        printf("\nSap xep danh sach mon thanh cong !!");
        return head;
}




int main() {
        Node *head = NULL;
        dNode *dHead = NULL;
        int choice;
        do {
                printf("\n-------RESTAURANT--------");
                printf("\n1. Them mon an");
                printf("\n2. Hien thi danh sach mon dang ban");
                printf("\n3. Cap nhat thong tin mon an");
                printf("\n4. Danh dau mon ngung ban");
                printf("\n5. Hien thi danh sach mon da ngung ban");
                printf("\n6. Tim kiem mon theo ten");
                printf("\n7. Sap xep mon theo gia tang dan");
                printf("\n8. Thoat chuong trinh");
                printf("\nLua chon cua ban: ");
                scanf("%d", &choice);
                switch (choice) {
                        case 1:
                                Dish *newDish = createDish();
                                head = pushToSingle(head, newDish);
                                if (head != NULL) {
                                        printf("Them moi mon an thanh cong !!");
                                }
                                break;
                        case 2:
                                displayDish(head);
                                break;
                        case 3:
                                int ID;
                                printf("Nhap ID mon an can cap nhat: "); scanf("%d", &ID);
                                updateDish(head, ID);
                                break;
                        case 4:
                                int offDishID;
                                printf("Nhap ID mon an da ngung ban: "); scanf("%d", &offDishID);
                                Dish *saleOff = saleOffDish(head, offDishID);
                                printf("Mon an ngung ban %s", saleOff ->name);
                                dHead = pushToDouble(dHead, saleOff);
                                if (dHead -> dish == saleOff) {
                                        printf("Cap nhat trang thai thanh cong");
                                        break;
                                }
                                break;
                        case 5:
                                displayDoneDish(dHead);
                                break;
                        case 6:
                                char target[30];
                                fflush(stdin);
                                printf("Nhap ten mon can tim: ");
                                fgets(target, 30, stdin); target[strlen(target) - 1] = '\0';
                                if (findTargetDish(head, target) == NULL) {
                                        printf("Khong thay mon an can tim!!");
                                        break;
                                }
                                Dish *targetDish =  findTargetDish(head, target);
                                printf("Mon an can tim: \n");
                                printf("\n %d - %s -  %s -  %d",
                                targetDish->id,
                                targetDish->name,
                                targetDish->category,
                                targetDish->price);
                                break;
                        case 7:
                                head = sort(head);
                                break;
                        case 8:
                                break;
                        default:
                                printf("Vui long chon yeu cau hop le");
                                break;
                }
        }while (choice != 8);
        printf("Thoat chuong trinh");
        free(head);
        free(dHead);
}
