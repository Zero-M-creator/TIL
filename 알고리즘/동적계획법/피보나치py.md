```py
#피보나치 탑다운(재귀) 큰문제를 쪼개서 작은 문제를 호출

cache = [0] * 100

def fibo(x):
    if x == 1 or x == 2: return 1

    if cache[x] != 0: return cache[x]

    cache[x] = fibo(x - 1) + fibo(x - 2)
    return cache[x]

#피보나치 보텀업(반복문) 작은문제 값으로 큰문제를 해결

cache = [0] * 100

cache[1] = 1
cache[2] = 1

for i in range(3, n + 1):
    cache[i] = cache[i - 1] + cache[i - 2]
```