
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //반복자 : 컨테이너에 보관된 원소에 접근할 수 있다.
    //it 가 v.begin()을 리턴한다. * 포인터랑 비슷

    vector<int>::iterator it = v.begin(); 
    for (; it != v.end(); it++) {
        cout << *it << " ";
    }
    
    // auto 는 리턴하는 것의 타입과 자동으로 맞춰준다.
    
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    
    /*
    범위기반 for루프
       for (element_declaration : array) 
        statement;
    루프를 반복해 element_declaration에 선언된 변수에 현재 배열 요소값을 할당(복사)하기 때문에 auto로 타입을 맞추는게 좋다.
    참조자를 사용해서 복사하지 않고 바로 접근해서 성능을 높일 수 있다. 단 for문에서 배열의 요소를 바꿀 수 있기때문에 읽기 전용이라면 const를사용한다.
    */
       
    for (auto& it : v) {
        cout << it << " ";
    }
    
    for (const auto& i : v) {
        cout << i << " ";
    }
    
    //정렬
    sort(v.begin(), v.end()); //오름차순

    //탐색 3번째 매개변수 값을 찾아서 iterator를 리턴 
    auto it = find(v.begin(), v.end(), x);
    if (it != v.end()) //못찾으면 이터레이터가 end를 가리킴;
        cout << "find " << x // << *it;
}
```