```py
import sys
from collections import deque 
def fastInput():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split()) #nPm
arr = [0] * m
used = [0] * (n + 1)
def backtraking(k): #k 현재 선택개수
    if k == m:
        for x in arr:
            print(x, end=' ')
        print()
        return

    for i in range(1, n + 1):
        if not used[i]:
            arr[k] = i
            used[i] = 1
            backtraking(k + 1)
            used[i] = 0

backtraking(0)


```