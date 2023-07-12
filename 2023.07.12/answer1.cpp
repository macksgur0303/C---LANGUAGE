#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 큐 초기화
void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// 큐가 비어있는지 확인
bool isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// 큐가 가득 찼는지 확인
bool isFull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// 큐에 데이터 삽입
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
}

// 큐에서 데이터 삭제 및 반환
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("큐가 비어있습니다.\n");
        return -1;  // 오류 값
    }
    int dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front++;
    }
    return dequeuedItem;
}

// 큐의 맨 앞 데이터 확인
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("큐가 비어있습니다.\n");
        return -1;  // 오류 값
    }
    return queue->items[queue->front];
}


int main() 
{
    Queue queue;
    initialize(&queue);

    int code,a ,b;
    int cnt1 = 0, cnt2 =0, k = 0, sum = 0;

    while (1)
    {
        code = getchar();
        getchar();
        if (code == 'q')
        {
            break;
        }
        else if (code >= 42 && code <= 47)
        {
            enqueue(&queue, code);
            cnt1++;
        }
        else
        {
            enqueue(&queue, code - 48);
            cnt1++;
        }
    }

    for(int i = 0; i < cnt1; i++)
    {
        if (queue.items[i - 1] < 48 && queue.items[i - 1] > 41 && queue.items[i] < 48 && queue.items[i] > 41)
        {
            enqueue(&queue, peek(&queue));
            dequeue(&queue);
            cnt1++;
        }

        else if (queue.items[i] < 48 && queue.items[i] > 41)
        {
            a = peek(&queue);
            dequeue(&queue);

            b = peek(&queue);
            dequeue(&queue);

            switch (queue.items[i])
            {
            case '+':
                enqueue(&queue, a + b);
                printf("+ ");
                break;
            case '-':
                enqueue(&queue, a - b);
                printf("- ");
                break;
            case '*':
                enqueue(&queue, a * b);
                printf("* ");
                break;
            case '/':
                enqueue(&queue, a / b);
                printf("/ ");
                break;
            case '%':
                enqueue(&queue, a % b);
                printf("% ");
                break;
            }

            dequeue(&queue);
            cnt1++;
        }

        else
        {
            printf("%d ", queue.items[i]);
        }
    }
    printf(" = %d", peek(&queue));
    printf("\n결과값: %d", peek(&queue));

    return 0;
}
