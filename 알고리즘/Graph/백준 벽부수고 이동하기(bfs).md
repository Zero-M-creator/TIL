bfs를 수행하되 해당 지점을 벽을 부수고 왔을 경우와 부수지 않고 왔을 경우를 모두 저장한다. 빨리 도착한 쪽이 최소임으로 어떤벽을 부쉈는지는 상관할 필요없다. 
```py
import sys
import copy
from collections import deque
def fastInput():
    return sys.stdin.readline().rstrip()

n, m = map(int, fastInput().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, fastInput())))

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
def bfs(y, x, flag):
    q = deque([(y, x, flag)])
    visited[y][x][0] = 1
    while q:
        y, x, flag = q.popleft()
        if y == n - 1 and x == m - 1:
                return visited[n - 1][m - 1][flag]
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny >= n or ny < 0 or nx >= m or nx < 0:
                continue
            if graph[ny][nx] == 1 and flag == 0:
                visited[ny][nx][1] = visited[y][x][0] + 1
                q.append((ny, nx, 1))
            if graph[ny][nx] == 0 and visited[ny][nx][flag] == 0:
                visited[ny][nx][flag] = visited[y][x][flag] + 1
                q.append((ny, nx, flag))
    return -1

print(bfs(0, 0, 0))
```