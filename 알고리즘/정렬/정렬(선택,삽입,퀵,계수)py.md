#선택정렬 O(N^2)

```py
arr[]

for i in range(len(arr)):
    min_index = i 
    for j in range(i + 1, len(arr)):
        if arr[i] > arr[j]:
            min_index = j
    arr[i], arr[min_index] = arr[min_index], arr[i]

```

#삽입정렬 O(N^2)
데이터가 거의 정렬 되었을 때 효율정임

```py
arr = []

for i in range(1, len(arr)):
    for j in range(i, 0, -1):
        if arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
        else:
            break
```

#퀵정렬 O(NlogN) 정렬된 데이터에서 O(N^2)
```py
arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(arr, start, end):
    if start >= end: #원소 1개
        return 
    pivot = start
    left = start + 1
    right = end
    while left <= right: 
        while left <= end and arr[left] <= arr[pivot]: #기준보다 큰거 찾기;
            left += 1
        while right > start and arr[right] >= arr[pivot]:
            right -= 1
        if left > right: #교차
            arr[right], arr[pivot] = arr[pivot], arr[right]
        else:
            arr[right], arr[left] = arr[left], arr[right]
    quick_sort(arr, start, right - 1)
    quick_sort(arr, right + 1, end)

#quick_sort(arr, 0, len(arr) - 1)
#print(arr)


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    tail = arr[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

print(quick_sort(arr))

```

#계수정렬 O(N + K)
모든데이터 양의 정수일 때 사용 데이터 개수 N 최댓값 K
```py
arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

count = [0] * (max(arr) + 1)

for i in range(len(arr)):
    count[arr[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')
```