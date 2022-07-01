공통원소가 없는 상호베타적인 부분 집합들로 나누어진 원소들을 저장하는 자료구조
두 원소가 같은 집합에 포함되어있는지 확인.
```c++
#include <iostream>
#include <vector>
using namespace std;

//트리를 이용한 상호배타적 집합 자료구조 
//부모가 같으면 같은 집합
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