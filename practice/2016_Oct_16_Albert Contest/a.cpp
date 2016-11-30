#include<bits/stdtr1c++.h>

using namespace std;

int main() {
	int ts; cin >> ts;
	for(int i = 0; i <ts ;i ++) {
		string cur; cin >> cur;
		int in = 0;
		int res = 0;
		for(int i = 0; i < cur.length(); i++) {
			in = in*10 + cur[i] - '0';
			res = max(res, __builtin_popcount(in));
		}
		cout << res << endl;
	}
}
