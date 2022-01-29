# 우선순위큐

Heap은 완전이진트리의 일종으로 가장 큰값과 작은값을 빠르게 찾기위한 자료구조이다.(우선순위를 빠르게 찾기) 부모노드 >= 자식노드(최대 히프), 반대는(최소 히프), 중복된 값을 허용한다. 완전이진트리임으로 배열로 구현가능하다.


```c
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size; //요소 개수 
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType* h) {
	h->heap_size = 0;
}
// 완전이진트리 끝에 값을 넣고 부모랑 비교하면서 위치를 찾는다. 
void insert_max_heap(HeapType* h, element input) { 
	int i = ++(h->heap_size);
	while ((i != 1) && (input.key > h->heap[i / 2].key)) { //heap이 비어있으면 바로 넣고 input이 부모값보다 크면
		h->heap[i] = h->heap[i / 2]; // 부모값을 내린다.
		i /= 2; // i 부모 자리로 이동 >> 부모부모랑 비교 
	}
	h->heap[i] = input; 
}

// 완전이진트리 끝에 값을 루트에 넣고 자식과 비교하면서 위치를 찾는다. heaptree에서 삭제는 루트에서만 일어난다. 
element delete_max_heap(HeapType* h) {
	int parent = 1; //인덱스 i
	int child = 2;  //2i
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--]; //마지막 값 저장, 사이즈 줄임
	while (child <= h->heap_size) {
		if (h->heap[child].key < h->heap[child + 1].key) child++; //오른쪽 자식이 더 크면 >> 2i+1 변경
		if (h->heap[child].key < h->heap[parent].key) break;
		h->heap[parent] = h->heap[child]; //값을 올린다.
		parent = child;
		child = parent * 2;
	}
	h->heap[parent] = temp;
	return item;
}
```

히프트리에서 삽입삭제를 할때 내부적으로 키값은 계속 바꾸는게 아니라 다른 변수로 저장해놓고 자리를 찾는 느낌; key값을 제외하고 다른 값은 자리를 바꿔줌.

<히프 정렬(heap sort)>(최대 히프) n개 정렬 O(nlogn)
히프트리에서 하나씩 delete해서 배열의 끝부터 저장(오름차순) 후 출력
