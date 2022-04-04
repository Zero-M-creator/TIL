```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeGraph(const vector<string>& words);
void dfs(int here);
vector<int> topologicalSort();

//순서의 표현 -> 방향 그래프, 정렬 -> 위상 정렬 

vector<vector<int>> adj; 
vector<int> seen, order;

int main()
{
	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		vector<string> words(n);		
		for (auto& w : words) {
			cin >> w;
		}
		makeGraph(words);
		vector<int> result = topologicalSort();
		if (result.empty()) {
			cout << "INVALID HYPOTHESIS" << endl;
		}
		else {
			for (auto& value : result) {
				char c = value +'a';
				cout << c;
			}
			cout << endl;
		}
	}
	return 0;
}

void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());

		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; //a -> b 방향 그래프 
				break;
			}
		}
	}
}

void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); there++) {
		if (adj[here][there] && !seen[there]) {
			dfs(there);
		}
	}
	order.push_back(here);
}

//dfs를 이용한 위상정렬 
//dfs를 종료 할 때 마다 현재 정점을 기록한 후 dfsAll 종료 후 기록을 뒤집음 늦게 종료 할 수록 깊게 있음
vector<int> topologicalSort() { 
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear(); //size 0
	for (int i = 0; i < m; i++) {
		if (!seen[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	//역방향 간선이 있는지 확인으로 사이클 확인
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (adj[order[j]][order[i]]) {
				return vector<int>();
			}
		}
	}
	return order;
}
```
