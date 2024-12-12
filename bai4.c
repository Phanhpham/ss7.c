//
//  bai4.c
//  cautrucdulieuXcode
//
//  Created by USED on 11/12/24.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int array[MAX];
    int front;
    int rear;
} Queue;

// Khởi tạo hàng đợi
void initalQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiểm tra xem hàng đợi có rỗng không
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Kiểm tra xem hàng đợi có đầy không
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Thao tác enqueue (thêm phần tử vào hàng đợi)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Xin lỗi, hàng đợi đã đầy!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;

    // Kiểm tra trạng thái hàng đợi sau khi thêm phần tử
    printf("Hàng đợi không rỗng sau khi thêm phần tử: %d\n", value);
}

// Thao tác dequeue (xóa phần tử khỏi hàng đợi)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng!\n");
        return -1;
    }
    int dequeuedValue = queue->array[queue->front];
    if (queue->front >= queue->rear) { // Nếu hàng đợi chỉ có 1 phần tử
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return dequeuedValue;
}

// Hàm peek (trả về phần tử đầu tiên mà không xóa)
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng, không có phần tử đầu tiên để trả về!\n");
        return -1; // Trả về -1 nếu hàng đợi rỗng
    }
    return queue->array[queue->front];
}

// Hiển thị hàng đợi
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng!\n");
        return;
    }
    printf("Các phần tử trong hàng đợi: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initalQueue(&queue);
    int value;
    do {
        printf("\n================MENU================\n");
        printf("0. Thoát\n");
        printf("1. Thêm phần tử vào cuối hàng đợi\n");
        printf("2. Hiển thị hàng đợi\n");
        printf("3. Xóa phần tử khỏi hàng đợi\n");
        printf("4. Xem phần tử đầu tiên trong hàng đợi (peek)\n");
        printf("Bạn chọn từ 0-4: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Mời bạn nhập vào giá trị: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                // Kiểm tra và in ra phần tử đầu tiên sau khi thêm
                printf("Phần tử đầu tiên trong hàng đợi: %d\n", peek(&queue));
                break;
            case 2:
                displayQueue(&queue);
                break;
            case 3:
                dequeue(&queue);
                break;
            case 4:
                printf("Phần tử đầu tiên trong hàng đợi: %d\n", peek(&queue));
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
                break;
        }
    } while (1);
    
    return 0;
}
