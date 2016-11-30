#include<bits/stdtr1c++.h>

using namespace std;
__int128 f(int xx) {
	__int128 res =1;
	for(__int128 i = xx; i>=1; i--) {
		res *=i;
	}
	return res;
}
int main() {
	int n; cin >>n;
	int k,s;
	for(int i = 0; i < n; i++) {
		cin >> k >>s;
		__int128 res = 0;
		for(int x = 0; x <=25; x++) {
			for(int j = x; j>=0; j--) {
				if (4*x + 2*j != s) continue;
				__int128 tm = f(x+j)/(f(x)*f(j));
				//cout << tm << endl;
				res += (tm*tm);
			}
		}
		cout << k << " " <<(long long) res << endl;
	}
}
