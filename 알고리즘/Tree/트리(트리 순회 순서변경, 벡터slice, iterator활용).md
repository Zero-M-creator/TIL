트리는 계층 관계를 갖는 객체들을 표현하기 위해 만들어진 자료구조이다.
*실제 계층관계가 없는 자료들을 트리로 표현해서 같은 연산을 더 빠르게 할 수 있는 경우가 많다. //이후 사이클 없는 그래프(루트없는 트리)

트리 순회 순서변경

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//벡터 slice 방법
vector<int> slice(const vector<int> &v, int a, int b) {
	//vector<int>::iterator it = v.begin();
	return vector<int>(v.begin() + a, v.begin() + b); //copy elements, vector<T>(literator, literator);
}

//전위탐색 중위탐색 결과가 주어질 때 후위탐색 결과 출력
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size(); //트리 노드 개수
	if (N == 0) return; //노드가 없으면 종료

	const int root = preorder[0]; //전위순회의 첫번째 원소는 루트이다.
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin(); //root iterator에서 시작 iterator를 빼서 사이즈를 구한다.

	//왼쪽 재귀호출 되면서 왼쪽 출력 -> 오른쪽 -> 루트 순으로 출력
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L)); //현재 루트 기준 왼쪽트리 
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N)); //현재 루트 기준 오른쪽트리

	cout << root << " ";
}
```