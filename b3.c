#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Da them %d vao ngan xep.\n", value);
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong, khong the xoa phan tu!\n");
        return -1; 
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Da xoa %d khoi ngan xep.\n", value);
    return value;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngan xep rong, khong co phan tu nao tren cung!\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void freeStack(Stack* stack) {
    Node* temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
    printf("Da giai phong bo nho cua ngan xep.\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Phan tu tren cung cua ngan xep: %d\n", peek(stack));

    pop(stack);
    pop(stack);

    if (isEmpty(stack)) {
        printf("Ngan xep dang rong.\n");
    } else {
        printf("Ngan xep khong rong.\n");
    }

    freeStack(stack);

    return 0;
}
