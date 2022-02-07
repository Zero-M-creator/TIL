모든 정점에서 모든 정점으로의 최단 경로를 구하는 알고리즘 

1. 2차원 배열에 현재까지 계산된 최소 비용을 담는다.
2. 각 노드를 거쳐가는 경우의 비용을 비교해서 작으면 갱신한다.
(x 2 y) VS (x 2 n) + (n 2 y )

```c
#include <stdio.h>

const int number = 4;
int INF = 1000000000;

int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0},
};

void floydWarshall() {
    int d[number][number]; // 결과 그래프 

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }
    for (int k = 0; k < number; k++) { //거쳐가는 노드
        for (int i = 0; i < number; i++) { //출발 노드
            for (int j = 0; j < number; j++) { //도착 노드
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    floydWarshall();
}


```