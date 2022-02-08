# 계수정렬

특정한 범위조건이 있을때, 데이터 크기가 작을 때 사용하는 알고리즘 O(N)

```c
#include <stdio.h>

int main(void)
{
	int temp;
	int count[5];
	int arr[30] = {
		1, 3, 3, 2, 2, 4, 5, 5, 2, 3,
		1, 3, 5, 3, 4, 3, 4, 4, 3, 2,
		1, 3, 3, 2, 2, 4, 5, 5, 2, 3
	};
	for (int i = 0; i < 5; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 30; i++) {
		count[arr[i] - 1]++;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}
	return 0;
}
```