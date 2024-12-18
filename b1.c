#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void addAtTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void removeHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa phan tu!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeTail(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa phan tu!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

Node* search(Node* head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    addAtHead(&head, 10);
    addAtHead(&head, 20);
    addAtTail(&head, 30);
    addAtTail(&head, 40);

    printf("Danh sach sau khi them cac phan tu:\n");
    printList(head);

    removeHead(&head);
    printf("Danh sach sau khi xoa phan tu dau:\n");
    printList(head);

    removeTail(&head);
    printf("Danh sach sau khi xoa phan tu cuoi:\n");
    printList(head);

    int value = 30;
    Node* foundNode = search(head, value);
    if (foundNode) {
        printf("Tim thay gia tri %d trong danh sach.\n", value);
    } else {
        printf("Khong tim thay gia tri %d trong danh sach.\n", value);
    }

    freeList(&head);
    printf("Da giai phong danh sach lien ket.\n");

    return 0;
}
