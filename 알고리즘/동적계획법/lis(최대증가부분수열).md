```c++
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int arr[500];
int cache[500];
int n;

//start 부터 시작하는 부분 증가 수열을 리턴  
int lis(int start) {
    int &ret = cache[start];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (arr[start] < arr[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}

int main()
{
    int testCase;
    
    cin >> testCase;
    while (testCase--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int maxLen = 0;
        for (int i = 0; i < n; i++) {         
            maxLen = max(maxLen, lis(i));
        }
        cout << maxLen << endl; 
    } 
}
```
```py
# lis O(n^2) 알고리즘 #[n] = n번째 수로 끝나는 최대 증가 부분수열 길이
import sys
from bisect import bisect_left
from collections import deque
def fastInput():
    return sys.stdin.readline().rstrip()

n = int(fastInput())
arr = list(map(int, fastInput().split()))

d = [1] * n
for i in range(1, n):
    for j in range(0, i):
        if arr[i] > arr[j]:
            d[i] = max(d[i], d[j] + 1)

print(max(d))
```
```py
import sys
from bisect import bisect_left
from collections import deque
def fastInput():
    return sys.stdin.readline().rstrip()

# 최대증가부분수열 nlogn 알고리즘
# d = 증가 수열의 길이를 최대한 늘리는데 가장 유리한 수열
# d[n] = 길이가 n 인 증가부분수열을 만들수 있는 마지막 원소중 가장 작은값
# 수열 길이가 같다면 작은게 더 유리 하기 때문에 d[-1] 값이 바뀌면 유리
# 마지막 값이 아닌 값이 바뀔때는 수가 작아짐으로 마지막값이 바뀌기 유리해짐
# 알고리즘 : d의 마지막 값과 비교하면서 d[-1] 보다 크다면 길이가 늘어남으로 append하고 
# d[-1] 보다 작다면 bisect_left를 사용해서 해당 값이 들어갈 수 있는 자리를 찾아서 교체해준다
# 교체가 일어나면 수열을 유지한체 작은값으로 바뀌게 됨

#경로 역추적 path[x] = arr[x] 의 seq(부분수열에서의 위치)
#맨오른쪽 최댓값부터 시작하여 가장 최선으로 갱신된 지점을 선택
import sys
from bisect import bisect_left
def fastInput():
    return sys.stdin.readline().rstrip()

n = int(fastInput())
arr = list(map(int, fastInput().split()))

d = [arr[0]]
path = [0] * (n)

for i in range(1, n):
    if d[-1] < arr[i]:
        d.append(arr[i])
        path[i] = len(d) - 1
    else:
        index = bisect_left(d, arr[i])
        d[index] = arr[i]
        path[i] = index

count = len(d) - 1
result = []

for i in range(n - 1, -1, -1):
    if count == path[i]:
        result.append(arr[i])
        count -= 1
result.sort()
print(result)
print(len(d))
```
