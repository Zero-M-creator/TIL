# List

리스트는 삽입 연산, 삭제 연산, 탐색 연산을 갖는다. 
1. 배열을 이용한 리스트는 크기가 고정되고 중간 값을 삽입 삭제 O(n)를 수행한 후 다른 값들의 이동이 필요하다. 배열에 저장하기 때문에 데이터가 순차적으로 저장된다.


<배열로된 리스트 구현>
```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 20

typedef int element;

typedef struct {
	element data[MAX_LIST_SIZE];
	int size; //저장 항목 개수
} ListType;

void init_list(ListType* L) {
	L->size = 0;
}

bool is_empty(ListType* L) {
	return L->size == 0;
}

bool is_full(ListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ListType* L, int pos) {
	if (pos < 0 || pos >= L->size) { 
		fprintf(stderr, "위치 오류"); exit(1);
	}
	return L->data[pos];
}

void print_list(ListType* L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d->", L->data[i]);
	}
	printf("\n");
}

void insert_last(ListType* L, element input) {
	if (is_full(L)) {
		fprintf(stderr, "리스트가 가득 찼습니다."); exit(1);
	}
	L->data[L->size++] = input;
}

void insert(ListType* L, int pos, element input) {
	if (!is_full(L) && pos >= 0 && pos <= L->size) { 
		for (int i = L->size-1; i >= pos; i--) {    
				L->data[i+1] = L->data[i];
		}
		L->data[pos] = input;
		L->size++;
	}
}

element delet(ListType* L, int pos) {
	if (pos < 0 || pos >= L->size) { 
		fprintf(stderr, "위치 오류"); exit(1);
	}
	for (int i = pos; i <= L->size - 1; i++) {
		L->data[i] = L->data[i + 1];		
	}
	L->size--;
	return L->data[pos];	
}
```

* insert() 함수에서 pos <= L->size에서 등호는 pos와 size가 00인경우를 위해서 들어간다. 그렇게되면 pos가 max_size 일때 문제가발생하고 이를 위해서 !is_full을 추가로 검사한다.

* pos를 매개변수로 받을 경우 pos값의 적절성을 검사해야한다. ex) pos 위치에 값을 꺼낼때 is_empty 로 검사를 하더라고 pos가 리스트 밖에 값이 라면 오류를 발생시킨다.

2. 포인터를 이용한 연결 리스트는 중간에 값을 삽입 삭제하는데 더 유연하고 데이터 저장공간을 필요한 만큼만 사용한다. O(1) 하지만 같은양의 데이터를 저장할때 연결리스트는 노드(데이터 필드, 링크 필드)에 포인터(주소값)을 저장하기 때문에 더많은 메모리를 요구한다. 또한 구현이 더 복잡하고 임의의 항목 추출 시 o(n) 배열 리스트(o(1))보다 성능이 떨어진다. 연결리스트의 구별은 첫번째 데이터를 통해서 하고 이 것을 가르키는 변수를 헤드 포인터라고한다. linked_list 를 구현할때 링크 훼손 손실이 일어나지 않도록 주의한다. 삭제나 삽입시 선행 노드를 가리키는 포인터가 필요하다!!

<단순 연결리스트 구현>
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{ //이 구조체가 노드임!
	element data;
	struct ListNode* link; //ListNode 다음노드 주소를 담는 포인터 변수 link
} ListNode;

ListNode* insert_first(ListNode* head, element input) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode)); //노드를 생성 
	p->data = input;
	p->link = head; // head가 가르키는 노드를 이어 받는다. 단순연결리스트에서는 마지막 노드가 NULL을 가르켜야함
	head = p; //헤드는 새로 생긴 노드를 가르킨다. 
	return head; 
}

ListNode* insert(ListNode* head, ListNode* pre, element input) { //pre다음에 삽입
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = input;
	p->link = pre->link; //pre 가르키는 노드를 p가 이어받는다.
	pre->link = p; //pre는 p를 가르킨다. 
	return head;
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* removed; // 
	removed = head; //삭제할 노드 생성? 정보 복사? 특정화? 
	head = removed->link; //삭제할 노드가 가르키던 노드 주소를 받느다.
	free(removed); //삭제 
	return head;
}

ListNode* delet(ListNode* head, ListNode* pre)
{
	ListNode* removed; 
	removed = pre->link; //삭제할게 pre가 가르키는 노드임
	pre->link = removed->link;		
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link) //p는 head가 가르키는 주소 p->link는 head가 가르키는 주소의 링크값 즉 연결된 노드의 주소
		printf("%d->", p->data);
	printf("NULL \n");
}
```

잡담.. 구조체 포인터를 매개변수로 사용할 때 -> 사용하는데 ex) p->data 를 p가 가르기는 곳의 data 라고 이해야면 편해서인듯... 
