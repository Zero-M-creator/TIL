공통원소가 없는 상호베타적인 부분 집합들로 나누어진 원소들을 저장하는 자료구조
두 원소가 같은 집합에 포함되어있는지 확인.
```c++
#include <iostream>
#include <vector>
using namespace std;

//트리를 이용한 상호배타적 집합 자료구조 
//부모가 같으면 같은 집합
//무향그래프 사이클 판단, 루트노드가 다른 노드를 합쳐서 최종적으로 같은 부모를 갖는지 확인
//방향 -> DFS
struct OptimizedDisjointSet {
	vector<int> parent, rank, size; 
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]); //모든 경로에 노드를 최종 루트로 바꿔준다. 
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return; //이미 같은 트리면 리턴
		if (rank[u] > rank[v]) swap(u, v); //기울어짐 방지 
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v]) ++rank[v]; //높이가 같은 걸 합칠 때 만 높이가 1증가
	}
};
```

```py
n = int(input())
parent = [i for i in range(1, n + 1)]
size = [1] * (n + 1)

def find(parent, u):
    if u != parent[u]: 
        parent[u] = find(parent, parent[u])    
    return parent[u]

def merge(parent, u, v):
    u = find(parent, u)
    v = find(parent, v)
    if u == v: return
    if u > v:
    	u, v = v, u
    parent[u] = v
    size[v] += size[u]

#모든간선을 확인하는데 두 노드의 부모가 이미 같다면 사이클이 발생한 것이다.
for i in range(e):
    if find(parent, u) == find(parent, v):
        cycle = True
        break
    else:
        merge(parent, u, v)


```
