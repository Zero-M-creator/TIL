
```py
import time
start = time.time()

n = int(input())

used1 = [0] * 30 #열 점령
used2 = [0] * 30 #x + y 동일, 왼쪽에서 위 대각선 점령
used3 = [0] * 30 #x - y 동일, 오른쪽에서 아래 대각선 점령 -> 음수 인덱스 방지를 위해 + (n - 1)

count = 0
def backtracking(cur):
    global count
    if cur == n:
        count += 1
        return
    for i in range(n): #cur줄 i번째 놓기
        if used1[i] or used2[i + cur] or used3[cur - i + n - 1]:
            continue
        used1[i] = 1
        used2[i + cur] = 1
        used3[cur - i + n - 1] = 1
        backtracking(cur + 1)
        used1[i] = 0
        used2[i + cur] = 0
        used3[cur - i + n - 1] = 0

backtracking(0)     
print(count)


print("time :", time.time() - start)
```