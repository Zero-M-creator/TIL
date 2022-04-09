```c++
#include <iostream>
#include <vector>
using namespace std;

/*
DFS 스패닝트리 간선 확인
dfs 탐색 중 아직 발견된 노드가 아니면 트리간선
발견 된 노드인데 선조->자손 : 순방향간선
발견 된 노드인데 자손->선조 : 역방향간선
이외 : 교차 간선
무향그래프에서는 교차간선이 없음 <교차간선은 한노드가 종료된 후 이후 dfs에서 노드를 찾아야되는데
양방향으로 이동가능한 무향에서는 dfs종료 없이 찾는다. 
*방향그래프 사이클 존재 여부는 역방향 간선의 존재 여부로 알 수 있다.
*/

/*
구현
u->v 가 순방향 간선이면 발견 순선 v <- u
u->v 가 역방향 간선이면 발견 순선 v -> u
u->v 가 교차 간선이면 발견 순선 dfs(v) 종료 후 dsf(u) 호출시 발견 발견순선 v->u
발견 순서가 역방향간선과 같기때문에 dfs(v) 종료를 확인한다. 
*/
vector<vector<int>> adj; //그래프
//discovered[i]정점 발견 순서 finished[i] -> dfs(i) 종료
vector<int> discovered, finished;
//발견 정점 수
int counter;

void dfs(int here) {
    discovered[here] = counter++; //counter번째 방문
    for (int i = 0; i < adj[here].size(); i++) { //인접 노드 방문
        int there = adj[here][i]; 
        cout << "(" << here << "," << there << "is a";
        if (discovered[there] == -1) {
            cout << "tree dege";
        }
        else if (discovered[here] < discovered[there]) {
            cout << "forward edge" << endl;
        }
        else if (discovered[here] > discovered[there] && finished[there] == 0) {
            cout << "backward edge" << endl;
        }
        else {
            cout << "cross edge";
        }
    }
    finished[here] = 1;
}
```