```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size; //enemy는 i노드에 적대관계에 있는 루트노드 저장
	BipartiteUnionFind(int n) : parent(n), rank(n, 1), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]); //모든 경로에 노드를 최종 루트로 바꿔준다. 
	}
	int merge(int u, int v) {
		if (u == -1 || v == -1) return max(u, v);// u v 공집합일때 ex적대집합이없음
		u = find(u); v = find(v);
		if (u == v) return u; //이미 같은 트리면 리턴
		if (rank[u] > rank[v]) swap(u, v); //기울어짐 방지 
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v]) ++rank[v]; //높이가 같은 걸 합칠 때 만 높이가 1증가
		return v;
	}
	//u,v 가 적대한다고 할때
	bool dis(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		int a = merge(u, enemy[v]);
		int b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if (enemy[u] == v) return false;
		int a = merge(u, v);
		int b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
};
//적대관계 집합 쌍 중 더 큰 쪽을 모두 더한다. 
int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	for (int node = 0; node < N; node++) {
		if (buf.parent[node] == node) { //루트 노드일 때
			int enemy = buf.enemy[node];
			if (enemy > node) continue; //중복해서 더하지 않기 위해
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		cin >> N >> M; //사람 수, 댓글
		bool is_contradiction = false;
		int contradiction_index = 0;
		BipartiteUnionFind s = BipartiteUnionFind(N);
		for (int i = 1; i <= M; i++) {
			string str; int u, v;
			cin >> str >> u >> v;
			if (is_contradiction) continue;
			if (str == "ACK") {
				if (!s.ack(u, v)) {
					is_contradiction = true;
					contradiction_index = i;
				}
			}
			if (str == "DIS") {
				if (!s.dis(u, v)) {
					is_contradiction = true;
					contradiction_index = i;
				}
			}
		}
		if(is_contradiction){
			cout << "CONTRADICTION AT " << contradiction_index << endl;
		}
		else {
			cout << "MAX PARTY SIZE IS " << maxParty(s) << endl;
		}
	}
}
```