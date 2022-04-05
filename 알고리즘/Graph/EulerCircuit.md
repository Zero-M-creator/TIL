```c++
#include <iostream>
#include <vector>
using namespace std;

/*오일러 서킷 : 모든 간선을 한번 씩 지나서 시작점으로 돌아오는 경로 찾기
오일러 서킷 존재 조건 : 모든 정점은 한 컨포넌트에 있고 모든 정점의 차수는 짝수여야한다.
구현 현재정점에서 간선을 따라가다 따라갈 간선이 없으면 종료
정점 차수가 짝수임으로 시작 정점에서 종료된다.
아직 사용하지 않은 간선을 찾아서 반복 후 경로를 합친 후 reverse. 
*/

vector<vector<int>> adj; //adj[i][j] i j 간선 수
//무향 그래프 오일러 서킷

void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there = 0; there < circuit.size(); there++) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
/*오일러 트레일 : 시작점과 끝점이 다른 경우
(end, start) 간선을 긋고 오일러 서킷을 찾은 후 간선을 끊는다.
이때 물론 모든 정점은 짝수 차수를 갖는다. 
*/

```