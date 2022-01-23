# 덱큐

덱(double ended queue) : 전단과 후단 모두 삽입 삭제가 가능한 자료구조

<덱 구현>

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} DequeType;

void init_deque(DequeType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

int is_full(DequeType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void add_rear(DequeType* q, element input) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 모두 찼습니다."); exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = input;
}

void add_front(DequeType* q, element input) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 모두 찼습니다."); exit(1);
	}
	q->data[q->front] = input;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //front 변수관리 
}

element delete_rear(DequeType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	int tmp = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[(tmp)];
}

element delete_front(DequeType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front)];
}

element get_rear(DequeType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	return q->data[q->rear];
}

element get_front(DequeType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	return q->data[q->front + 1 % MAX_QUEUE_SIZE];
}

void deque_print(DequeType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	int i = q->front;
	do {
		printf("%d | ", (q->data[(i + 1) % MAX_QUEUE_SIZE]));
	} while ((i++ + 1) % MAX_QUEUE_SIZE != q->rear);
	printf("\n");
}
```

* front 와 rear 변수를 관리할때 주의! 원형큐와 다르게 변수를 뒤로 보내는 경우가 있음