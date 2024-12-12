//
//  bai5.c
//  cautrucdulieuXcode
//
//  Created by USED on 11/12/24.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int priority;
    int data;
} Element;

typedef struct {
    Element array[MAX];
    int size;
} PriorityQueue;

// Khởi tạo hàng đợi ưu tiên
void initPriorityQueue(PriorityQueue* pq) {
    pq->size = 0; // Đặt kích thước hàng đợi về 0
}

// Kiểm tra xem hàng đợi có rỗng không
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0; // Nếu kích thước bằng 0, hàng đợi rỗng
}

// Thao tác enqueue (thêm phần tử vào hàng đợi với mức độ ưu tiên)
void enqueue(PriorityQueue* pq, int priority, int data) {
    if (pq->size >= MAX) {
        printf("Hàng đợi ưu tiên đã đầy!\n");
        return; // Không thể thêm nếu hàng đợi đã đầy
    }

    // Tạo phần tử mới
    Element newElement = {priority, data};

    // Tìm vị trí để chèn phần tử mới theo thứ tự ưu tiên
    int i;
    for (i = pq->size - 1; (i >= 0 && pq->array[i].priority < priority); i--) {
        pq->array[i + 1] = pq->array[i]; // Di chuyển phần tử xuống
    }
    pq->array[i + 1] = newElement; // Chèn phần tử mới
    pq->size++; // Tăng kích thước hàng đợi

    // Hiển thị trạng thái hiện tại của hàng đợi
    printf("Đã thêm phần tử với ưu tiên %d và dữ liệu %d.\n", priority, data);
    printf("Trạng thái hàng đợi:\n");
    for (int j = 0; j < pq->size; j++) {
        printf("Ưu tiên: %d, Dữ liệu: %d\n", pq->array[j].priority, pq->array[j].data);
    }
}

// Thao tác dequeue (lấy phần tử có ưu tiên cao nhất ra khỏi hàng đợi)
Element dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hàng đợi ưu tiên rỗng!\n");
        return (Element){-1, -1}; // Trả về phần tử không hợp lệ
    }

    Element highestPriorityElement = pq->array[0]; // Lấy phần tử có ưu tiên cao nhất
    for (int i = 0; i < pq->size - 1; i++) {
        pq->array[i] = pq->array[i + 1]; // Di chuyển phần tử xuống
    }
    pq->size--; // Giảm kích thước hàng đợi

    // Hiển thị trạng thái hiện tại của hàng đợi
    printf("Đã xóa phần tử với ưu tiên %d và dữ liệu %d.\n", highestPriorityElement.priority, highestPriorityElement.data);
    printf("Trạng thái hàng đợi:\n");
    for (int j = 0; j < pq->size; j++) {
        printf("Ưu tiên: %d, Dữ liệu: %d\n", pq->array[j].priority, pq->array[j].data);
    }

    return highestPriorityElement; // Trả về phần tử đã xóa
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq); // Khởi tạo hàng đợi ưu tiên

    int choice, priority, data;

    do {
        printf("\n================MENU================\n");
        printf("0. Thoát\n");
        printf("1. Thêm phần tử vào hàng đợi ưu tiên\n");
        printf("2. Lấy phần tử có ưu tiên cao nhất ra khỏi hàng đợi\n");
        printf("Bạn chọn từ 0-2: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Mời bạn nhập mức độ ưu tiên và dữ liệu: ");
                scanf("%d %d", &priority, &data);
                enqueue(&pq, priority, data);
                break;
            case 2:
                dequeue(&pq);
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
                break;
        }
    } while (1);

    return 0;
}
