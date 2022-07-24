O(NlogN)보장 
```py
import sys
import heapq
def fastInput():
    return sys.stdin.readline().rstrip()

def heapSort(nums):
  heapq.heapify(nums)
  sorted = []
  
  for _ in range(len(nums)):
      num = heapq.heappop(nums)
      sorted.append(num)
  return sorted

n = int(fastInput())
arr = []
for _ in range(n):
    arr.append(int(fastInput()))

r = heapSort(arr)
for x in r:
    print(x)
```