```c++
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int arr[500];
int cache[500];
int n;

//start 부터 시작하는 부분 증가 수열을 리턴  
int lis(int start) {
    int &ret = cache[start];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (arr[start] < arr[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}

int main()
{
    int testCase;
    
    cin >> testCase;
    while (testCase--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int maxLen = 0;
        for (int i = 0; i < n; i++) {         
            maxLen = max(maxLen, lis(i));
        }
        cout << maxLen << endl; 
    } 
}
```