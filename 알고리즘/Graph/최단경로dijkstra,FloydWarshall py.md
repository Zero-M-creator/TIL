```py
#다익스트라 시작노드에서 다른 노드들 사이의 거리를 구하는 알고리즘 O(ElogV)
비용이 가장 작은 노드를 선택하면서 수행 -> 다른 인접 노드를 통해서 가면 비용이 더 많이 드니까... 즉 작은걸 선택하면 선택된 노드까지의 최단거리 최소가 유지

import heapq #파이썬 기본 최소힙
import sys
input = sys.stdin.readline
INF = int(1e9)

n,m = map(int, input().split()) #노드, 간선

start = int(input)

graph = [[] for i in range(n + 1)] #각 노드에 연결된 노드
distance = [INF] * (n + 1)


for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c)) #a에서 (b 까지 비용 c) 튜플

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start)) #비용, 노드
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q) #현재 노드까지의 최소 비용, 현재 노드
        if distance[now] < dist: #비용이 더 크면 아래 수행 할 필요 없음 
            continue
        for i in graph[now]: 
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        pass
    else:
        print(distance[i])

```py
#플로이드 와샬 모든 노드에서 모든 노드로  O(N^3)

INF = int(1e9)

n = int(input()) #노드
m = int(input()) #간선

graph = [[INF] * (n + 1) for _ in range(n + 1)]
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

for _ in range(n):
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, n + 1): #거쳐가는 노드
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            pass
        else:
            pass

```
