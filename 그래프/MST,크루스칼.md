# 최소스패닝트리

스패닝트리
1. 모든 정점을 포함
2. 사이클 미포함
3. n개의 정점을 n-1개의 간선으로 연결

MST(최소스패닝트리)

스패닝 트리에서 간선의 가중치의 합이 최소가되는 트리.
MST를 찾는 방법으로 Kruskal, Prim 이있다. 

union-find(합치고 찾기)

여러개의 노드가 존재할 때 2개의 노드를 선택해서 두 노드가 같은 집합에 속하는지 판별하는 알고리즘(연결성을 컴퓨터 상으로 표현한 것)

1. 노드들의 초기 값은 자신을 갖는다.
2. 연결되면 (일반적으로) 작은 값을 부모로 갖도록 익덱스값이 변경(합친다)한다.(Union), 과정에서 재귀함수 사용
3. find 두 노드를 비교해서 같은 부모를 갖는지 확인
Kruskal에서 사이클 발생을 확인하기위해 사용

```c
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) { 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) { //같은 부모를 가지면 연결돼있다. 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}
```


Kruskal
1. 가중치를 오름차순으로 정렬
2. 정렬된 간선을 순서대로 선택한다.
3. 사이클을 형성하지 않으면 MST에 포함시킨다.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
	int node[2]; //서로 연결된 노드 정보
	int distance; // 비용정보
	Edge(int a, int b, int distance) { //생성자 초기화
		this->node[0] = a; 
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge& edge) { //간선과 비교할때 가중치가 낮은게 우선순위가 높음
		return this->distance < edge.distance;
	}
};

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return getParent(parent, parent[x]); //자신이 루트노드가 아니면 부모를 넣어서 다시 확인.
}

void unionParent(int parent[], int a, int b) { 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) { //같은 부모를 가지면 연결돼있다. 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main()
{
	const int n = 7;  //정점
	int e = 11; // 간선
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(4, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(6, 7, 73));
	sort(v.begin(), v.end()); 
	int parent[n]; //유니온 파인드를 위한 배열
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) { 
			sum += v[i].distance;
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
		}
	}
	printf("%d", sum);
}

```
Kruskal.py
```py
n, e = map(int, input().split())

parent = [0] * (n + 1)
for i in range(1, n + 1):
    parent[i] = i

edges = []
for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

rank = [1] * (n + 1) 

def find(parent, u):
    if u != parent[u]:
        parent[u] = find(parent, parent[u])
    return parent[u]

def merge(parent, u, v):
    u = find(parent, u)
    v = find(parent, v)
    if u == v: return
    if rank[u] > rank[v]:
        u, v = v, u
    parent[u] = v
    if rank[u] == rank[v]:
        rank[v] += 1

result = 0

for edge in edges:
    cost, a, b = edge
    if find(parent, a) != find(parent, b): #사이클 발생 X
        merge(parent, a, b)
        result += cost

print(result)

"""
7 9
1 2 29
1 6 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25
"""
```
Prim 
1. 임의의 노드를 고르고 트리에 넣는다.
2. 트리의노드와 연결된 노드 중 간선의 가중치가 최소인 노드를 고른 후 트리에 넣는다.
3. 모든 노드가 트리에 속할때까지 위 1, 2를 반복한다.
