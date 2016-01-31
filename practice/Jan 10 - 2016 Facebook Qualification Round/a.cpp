#include<iostream>
#include<unordered_map>
using namespace std;
#define ll long long 
struct po {
	ll x; ll y;
};

ll cdis(po a, po b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)* (a.y - b.y);
}
po ar[2005];
unordered_map<ll,ll> om;
int main(){
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc ++) {
		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> ar[i].x >> ar[i].y;
		}
		ll res = 0;
		for (int i = 0; i < n; i++) {
			om.clear();
			for (int j = 0; j <n; j++) {
				if (i == j) continue;
				ll dis = cdis(ar[i], ar[j]);
				//cout << dis << endl;
				om[dis]++;
			}

			for (auto ev: om) {
				res+= ((ev.second * (ev.second -1))/2);
			}
		}


		cout << "Case #" << tc << ": " << res << "\n";
	}
}