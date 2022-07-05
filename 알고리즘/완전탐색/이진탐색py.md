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

```