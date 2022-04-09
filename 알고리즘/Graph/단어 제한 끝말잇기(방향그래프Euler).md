```c++
#include <iostream>
#include <vector>
using namespace std;

/*
무향그래프 절단점 찾기
절단점 : 해당 정점에 간선을 제거했을 때 그래프가 2개이상의 컴포넌트로 나누어지는 점
*/

/*
구현
DFS로 그래프를 스패닝 트리로 만!든!다!. 스패닝 트리에서!
정점 n이 절단점인지 확인
n과 연결된 정점은 모두 선조 or 자손
n의 자손을 루트노드로 하는 모든 서브트리에서 n의 선조로 가는 역방향간선이 존재해야 절단점 X
dfs가 서브트리에서 역방향 간선을 통해 갈 수 있는 정점의 최소 깊이 반환
모두 역방향 간선으로 n의 선조로 올라갈 수 있다면 절단점 X
발견 순서를 통해 순방향간선 역방향간선 확인
***자손이 하나도 없거나 하나 일때는 절단점이 아님 
*/

vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter;

//here 루트에서 서브트리를 검사해서 절단점을 찾는 함수
//해당 정점에서 역방향으로 가장 높게 갈 수 있는 정점을 리턴한다. 
int findCutVertex(int here, bool isRoot) {
	discovered[here] = counter++;
	int ret = discovered[here];
	
	int children = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			children++;
            //서브트리에서 갈 수 있는 높은 번호 
			int subtree = findCutVertex(there, false);
			if (!isRoot && subtree >= discovered[here]) { //역방향 간선이 없으면 
				isCutVertex[here] = true;
			}
			ret = min(ret, subtree); //해당 정점에서 역방향으로 가장 높이 갈 수 있는 정점을 리턴
		}
		else {
            //방문한 정점이라면 그 정점에서 최대 높게 갈 수 있는 정점과 자신을 비교해 높은걸 리턴 
			ret = min(ret, discovered[there]);
		}
	}
    //루트 노드일 경우
	if (isRoot) {
		isCutVertex[here] = children >= 2;
	}
	return ret;
}
