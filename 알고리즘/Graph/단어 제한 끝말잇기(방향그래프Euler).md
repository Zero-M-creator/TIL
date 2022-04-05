```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;

vector<string> graph[26][26];

vector<int> indegree, outdegree; //indegree[i] i로 시작하는 단어 수, outdegree[i] i로 끝나는 단어 수

//방향그래프에서 오일러 서킷, 트레일이 존재하는지 확인
//서킷 : 모든 정점에서 나가는 간선과 들어오는 간선의 개수가 같다.
//트레일 : 모든 정점에서 나가는 간선과 들어오는 간선의 개수가 같고 시작정점(indegree + 1 == outdegree), 끝정점(indegree == outdegree + 1);
//방향그래프 오일러 서킷

bool checkEuler() {
    int plus1 = 0;
    int minus1 = 0;
    for (int i = 0; i < 26; i++) {
        int delta = outdegree[i] - indegree[i];
        if (delta < -1 || delta > 1) return false;
        if (delta == 1) plus1++;
        if (delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0); //트레일 / 서킷
}

string solve(const vector<string>& words) {
    makeGraph(words);
    if (!checkEuler()) return "IMPOSSIBLE";

    vector<int> circuit = getEulerTrailOrCircuit();

    if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

    reverse(circuit.begin(), circuit.end());
    string ret;
    for (int i = 1; i < circuit.size(); i++) {
        int a = circuit[i - 1];
        int b = circuit[i];
        if (ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}

void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there = 0; there < adj.size(); there++) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;
    //트레일 시작점 찾기
    for (int i = 0; i < 26; i++) {
        if (outdegree[i] == indegree[i] + 1) { //나가는 간선이 들어오는 간선보다 1개많아야함
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    //서킷, 아무 정점에서 시작
    for (int i = 0; i < 26; i++) {
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
        }
    }
    return circuit;
}

void makeGraph(const vector<string>& words) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            graph[i][j].clear();
        }
    }
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);

    for (int i = 0; i < words.size(); i++) {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size() - 1] - 'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

int main()
{
    int testCase;
    int n;
    cin >> testCase;
    while (testCase--) {
        cin >> n;
        vector<string> words(n);
        for (auto& w : words) {
            cin >> w;
        }
    }
}
```