# 다익스트라 알고리즘

특정 한 정점에서 다른 정점들 까지의 최단 경로를 찾는 알고리즘

1. 출발 노드 설정
2. 출발 노드를 기준으로 인접 노드의 최소비용을 저장
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
4. ***선택한 노드를 거쳐서 다음 노드로 가는 경우를 고려하여 비용이 더 작다면 최소비용 갱신
5. 3~4 과정 반복 

최소값을 찾아야되기때문에 최대 최소를 빨리 찾을 수 있는 힙을 사용
순차적으로 넣을 경우 현재 지점이 최소가 아닌 상태로 다른 지점을 갱신해버릴 수 있음.

<다익스트라 구현>

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector < pair<int, int> > a[7]; //시작노드 에서 pair< next 노드, 로 가는 비용> //두번째 값 따라서 내림차순 정렬
int d[7];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq; //최대 힙
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        int current = pq.top().first; //현재 위치한 노드 
        int distance = -pq.top().second; //거리를 음수로 저장했기때문에 다시 -
        pq.pop();
        if (d[current] < distance) continue; // 최단거리가 아닌경우는 스킵
        //노드로 거쳐 인접한 다음 노드로 가는 비용을 계산해서 적으면 갱신
        for (int i = 0; i < a[current].size(); i++) {
            int next = a[current][i].first; 
            int nextDistance = distance + a[current][i].second; //거쳐서가는 길이
            if (nextDistance < d[next]) { //next로 갈때 current를 거처서가는게 더 짧으면 갱신
                d[next] = nextDistance; 
                pq.push(make_pair(next, -nextDistance)); // Queue에 next노드까지 갱신된 거리를 넣는다(갱신 된, 짧은 루트를 기준으로 다음을 봄), 음수로 저장해서 거리가 짧은 순으로 정렬  
            } 
        }
    }
}
int main()
{
    for (int i = 1; i <= number; i++) { //거리는 무한으로 초기화 한다.
        d[i] = INF;
   }
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(1);
    
    for (int i = 1; i <= number; i++) {
        printf("%d ", d[i]);
    }
}


```