
```c++
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
	//key 값과 value 값을 서로 맵핑시켜주는 것이 hashTable,hashMap
	map<int, string> myMap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		string str;
		cin >> str;
		myMap[num] = str;
	}
	//auto = pair<int, string>
	for (auto item : myMap) {
		cout << item.first << " = " << item.second;
	}
}

int main() {
	//단어 카운트
	map<string, int> myMap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (myMap.find(str) == myMap.end()) { //처음발견
			myMap[str] = 1;
		}
		else
			myMap[str] = myMap[str] + 1;
	}
}
```