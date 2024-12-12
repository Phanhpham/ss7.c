//
//  hangdoi.c
//  cautrucdulieuXcode
//
//  Created by USED on 11/12/24.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

 typedef struct Queue{
    int array[MAX];
    int front;
    int rear;
}Queue;

//khoi tao hang doi
void initalQueue(Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}
//khoi tao ham ktra rong hay ko
int isEmpty(Queue* queue){
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}
//khoi tao ham ktra hang doi day
int isFull(Queue* queue){
    if (queue->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

//enqueue(them phan tu vao hang doi )
void enqueue(Queue* queue,int value){
    if (isFull(queue)== 1) {
        printf("xin loi het cho roi!");
        return;
    }
    if (isEmpty(queue)==1) {
        queue->front=0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    
}
// dequeue(xoa phan tu vao hang doi)
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



//display queue
void displayQueue(Queue* queue){
    for (int i = queue->front; i<=queue->rear; i++) {
        printf("%d\t",queue->array[i]);
    }
}
int main (){
    Queue queue;
    initalQueue(&queue);
    int value;
    do {
        printf("\n================MENU================\n");
        printf(".0 Thoat\n");
        printf(".1 Them phan tu vao cuoi hang doi\n ");
        printf(".2 Hien thi hang doi\n");
        printf("Moi lua chon tu 0-2:");
        int choice;
        scanf("%d",&choice);
        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("moi ban nhap vao gia tri:");
                scanf("%d",&value);
                enqueue(&queue, value);
                break;
            case 2:
                displayQueue(&queue);
                break;
            
            default:
                break;
        }
    } while (1==1);
    return 0;
}
