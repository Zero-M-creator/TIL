```py
#이진 탐색
def binary_search(arr, target, start, end):
    if start > end: return None #찾지 못했을 때
    mid = (start + end) // 2
    if arr[mid] == target: return mid
    if arr[mid] > target: 
        binary_search(arr, target, start, mid - 1)
    elif arr[mid] < target:
        binary_search(arr, target, mid + 1, end)


def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        # 찾은 경우 중간점 인덱스 반환  
        if array[mid] == target:
            return mid
        # 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        elif array[mid] > target:
            end = mid - 1
        # 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else:
            start = mid + 1
    return None
```
