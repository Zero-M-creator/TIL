```c++
#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
double cache[1001][2001];

double climb(int days, int climbed) {
	if (days == m) {
		return climbed >= n ? 1 : 0;
	}
	double& ret = cache[days][climbed];
	if (ret != -1.0) return ret;
	return ret = 0.75 * climb(days + 1, climbed + 2) + 0.25 * climb(days + 1, climbed + 1);
}

int main()
{ 
	int testCase;
	cin >> testCase;
	while (testCase--) {
		//double 이라 memset 불가 
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 2001; j++) {
				cache[i][j] = -1.0;
			}
		}
		cin >> n >> m;
		cout << fixed; //소수점 고정
		cout.precision(11); //소수점 11자리 출력
		cout << climb(0, 0) << endl;
	}
}
```