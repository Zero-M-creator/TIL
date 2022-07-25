다이나믹 프로그래밍 
1. 최적 부분 구조 : 큰 문제를 작은 문제로 나눌 수 있다.
2. 중복되는 부분 문제 : 동일한 문제를 반복적으로 해열

순서
1. 테이블정하기
2. 점화식 찾기
3. 초기값 설정
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
