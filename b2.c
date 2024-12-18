#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtHead(Node **head, Node **tail, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void addAtTail(Node **head, Node **tail, int value) {
    Node *newNode = createNode(value);
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void printForward(Node *head) {
    Node *temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printBackward(Node *tail) {
    Node *temp = tail;
    printf("Backward Traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void deleteAtHead(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = *head;
    if (*head == *tail) { 
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Da xoa node o dau danh sach.\n");
}

void deleteAtTail(Node **head, Node **tail) {
    if (*tail == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = *tail;
    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
    free(temp);
    printf("Da xoa node o cuoi danh sach.\n");
}

int main() {
    Node *head = NULL, *tail = NULL;
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them node vao dau danh sach\n");
        printf("2. Them node vao cuoi danh sach\n");
        printf("3. In danh sach tu dau den cuoi\n");
        printf("4. In danh sach tu cuoi ve dau\n");
        printf("5. Xoa node o dau danh sach\n");
        printf("6. Xoa node o cuoi danh sach\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri node muon them vao dau: ");
                scanf("%d", &value);
                addAtHead(&head, &tail, value);
                break;
            case 2:
                printf("Nhap gia tri node muon them vao cuoi: ");
                scanf("%d", &value);
                addAtTail(&head, &tail, value);
                break;
            case 3:
                printForward(head);
                break;
            case 4:
                printBackward(tail);
                break;
            case 5:
                deleteAtHead(&head, &tail);
                break;
            case 6:
                deleteAtTail(&head, &tail);
                break;
            case 7:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
        }
    } while (choice != 7);

    return 0;
}
