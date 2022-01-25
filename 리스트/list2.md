# 리스트

원형연결리스트

하나의 노드에서 모든 노드 접근이가능한 리스트이다. 원형연결리스트를 변형 시켜서 head를 마지막 노드를 가르키게 하면 처음 끝 사입시 O(1) 으로 끝낼 수 있다. 마지막노드는 주소는 head가, 첫번째 노드는 head->link에 있다. 

<변형원형연결리스트 구현>
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;	
		head = p;		
	}
	return head;	
}
```

이중연결리스트

단순연결리스트와 원형연결리스트는 후속노드를 찾는 것은 쉽지만 선행노드를 찾는게 어렵다. 그래서 양방향성 움직임이 필요하다면 사용한다. 노드에 선행노드 주소와 후속노드 주소가 모두 들어가기 때문에 메모리를 많이 차지하고 구현이 어렵다. 실제로 원형연결리스트 + 이중연결리스트의 노드를 많이 사용한다.
cf) 알고리즘을 간단히 하기위해 아무런 데이터가없는 head노드를 사용하기도 한다. 

<이중연결리스트 구현>
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* rlink;
	struct DListNode* llink;
} DListNode;

void init_Dlist(DListNode* head) {
	head->rlink = head;
	head->llink = head;
}

void insert(DListNode* before, element input) { //before이후 삽입
	DListNode* p = (DListNode*)malloc(sizeof(DListNode));
	p->data = input;
	p->rlink = before->rlink;
	p->llink = before;
	before->rlink->llink = p;
	before->rlink = p;
}

void delet(DListNode* head, DListNode* removed) {
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf(" <- %d -> ", p->data);
	}
	printf("\n");
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init_Dlist(head);

    free(head); //사용한 뒤 head도 동적메모리니까 삭제!!
}
```

일단은 head노드를 사용하니 1개만 가리키는 포인터보다 편했다...?
링크를 잃어버리지 않도록 주의하자.

연결리스트를 이용한 스택

저장공간에 제한이 없다. 저장 삽입시 동적메모리 할당과 삭제가 일어나서 조금느리다.

<linked stack 구현>

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link; 
} StackNode;

typedef struct {
	StackNode* top; //head 포인터 
} LinkedStackType; //스택구현!

void init_stack(LinkedStackType* s) {
	s->top = NULL;
}

bool is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

bool is_full() {
	return false;
}

void push(LinkedStackType* s, element input) {
	StackNode* sn = (StackNode*)malloc(sizeof(StackNode));
	sn->data = input; 
	sn->link = s->top;
	s->top = sn;
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있습니다."); exit(1);
	}
	StackNode* pop;
	pop = s->top;
	element data = pop->data; //free 하면 return할 데이터를 잃어 버림
	s->top = s->top->link;
	free(pop);
	return data;
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있습니다."); exit(1);
	}
	return s->top->data;
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
```

연결리스트로 구현한 큐

<linked queue 구현>

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode { //노드 설계도
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { //queue 설계도 
	QueueNode* front; //head 포인터 노드
	QueueNode* rear;
} LinkedQueueType;

void init_queue(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

bool is_empty(LinkedQueueType* q) {
	return (q->front == NULL && q->rear == NULL); //q->front == q->rear; 하나일 때도 같음
}

bool is_full() {
	return false;
}

void enqueue(LinkedQueueType* q, element input) {
	QueueNode* qn = (QueueNode*)malloc(sizeof(QueueNode));
	qn->data = input;
	qn->link = NULL;
	if (is_empty(q)) {
		q->front = qn;
		q->rear = qn;
	}
	else {
		q->rear->link = qn; //마지막 노드의 링크를 새로운노드로 변경,,,,갖고있는 링크를 따라가면 qn
		q->rear = qn; //rear 포인터 관리 새로운 노드를 가리킴
	}
}

element dequeue(LinkedQueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다."); exit(1);
	}
	QueueNode* removed;
	removed = q->front;
	element data = removed->data;
	q->front = removed->link;
	if (q->front == NULL) //front를 옴겼을때 NULL 즉 큐가 비면 rear 값도 변경해주어야 한다. 
		q->rear = NULL;
	free(removed);
	return data;
}

void print_queue(LinkedQueueType* q) {
	for (QueueNode* qn = q->front; qn != NULL; qn = qn->link)
		printf("%d->", qn->data);
	printf("NULL \n");
}

//삽입 삭제시 rear과 front 신경;
```