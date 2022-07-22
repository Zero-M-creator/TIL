BFS
1. 시작칸을 큐에 넣고 방문
2. 큐에서 원소를 꺼낸뒤 상하좌우 방문하지 않고 조건에 맞는 칸을 방문 후 큐에 삽입
```py
from collections import deque

n, m, v = map(int,input().split())

visited = [False] * (n+1)

graph=[[] for _ in range(n + 1)]


for _ in range(m):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(len(graph)):
    graph[i].sort()

def dfs(v):
    print(v, end=' ')
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(i)
            visited[i] = True

def bfs(v):
    q = deque([v])
    visited[v] = True
    while q:
        cur = q.popleft()
        print(cur, end=' ')
        for i in graph[cur]:
            if not visited[i]:
                q.append(i)
                visited[i] = True

dfs(v)
visited = [False] * (n+1)
print()
bfs(v)
```
