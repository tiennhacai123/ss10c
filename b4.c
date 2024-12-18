#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Da them %d vao hang doi.\n", value);
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong, khong the xoa phan tu!\n");
        return -1;
    }

    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Da xoa %d khoi hang doi.\n", value);
    return value;
}

int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong, khong co phan tu nao dau tien!\n");
        return -1;
    }
    return queue->front->data;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void freeQueue(Queue* queue) {
    Node* temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
    printf("Da giai phong bo nho cua hang doi.\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Phan tu dau tien trong hang doi: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);

    if (isEmpty(queue)) {
        printf("Hang doi dang rong.\n");
    } else {
        printf("Hang doi khong rong.\n");
    }

    freeQueue(queue);

    return 0;
}
