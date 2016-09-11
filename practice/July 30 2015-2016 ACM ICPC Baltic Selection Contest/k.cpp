#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;
ll arr[23];
set<ll> se;
ll hold[1000000];
void gen() {
	arr[0] = 1;
	arr[1] = 1;

	for(int i =2; i < 20; i++) {
		arr[i] = i * arr[i-1];
	}
}

void gen1() {
	ll tm, cur;
	se.insert(1);
	set<ll>::iterator it;
	for (int i = 2; i < 20; i++) {
		int num = 0;
		for(it = se.begin(); it != se.end(); ++it) {
			hold[num++] = *it;
		}
		tm = arr[i];
		for(int j = 0; j < num; j++) {
			cur = hold[j];
			while(1e18/cur >= tm) {
				cur *= tm;
				se.insert(cur);
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	gen();
	gen1();
	int n; cin >>n;
	ll num;
	for(int i = 0; i < n; i++) {
		cin >> num;
		if (se.find(num) != se.end()) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";	
		}
	}
}

