# 선형큐, 원형큐

Queue 자료구조는 FIFO 선입선출방식이다. 전단인 front와 후단인 rear를 가지고 작동하고 front에서 삭제 rear에서 삽입이 일어난다. 선형큐는 배열로 이루어진 큐로 사용할수록 front와 rear값이 증가함으로 주기적으로 배열의 요소를 앞쪽으로 이동시켜 주어야하는데 이를 해결하기위해 사용하는 것이 원형큐이다. 원형큐는 배열의 마지막 인덱스를 사용하고 나면 다시 처음으로 돌아가는 형태를 갖춘다. 

<원형큐 구현>
```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue(QueueType* q, element input) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 모두 찼습니다."); exit(1);
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = input;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void queue_print(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	int i = q->front;
	do {
		printf("%d | ", (q->data[(i + 1) % MAX_QUEUE_SIZE]));	
	} while ((i++ + 1) % MAX_QUEUE_SIZE != q->rear);
}
```

* front 는 첫번째 요소의 하나 앞, rear은 마지막 요소의 위치를 가르킨다.
* queue_print() 메서드 : front+1 인덱스 부터 증가시키면서 rear과 같아질떄까지 출력한다.  
* 포화상태 공백상태를 구분하기위해 큐 자리 하나는 비워둔다.

