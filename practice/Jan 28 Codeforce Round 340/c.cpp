#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> ps;
pii r1;
pii r2;
ll dis(const pii& p1, const pii&p2) {
	return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}


bool cmp(const pii& p1, const pii& p2) {
		return dis(p1,r1) > dis(p2, r1);
	}

int main(){
	ios::sync_with_stdio(0);
	ps.clear();
	int n, x1,y1,x2,y2; cin >>n >> x1 >> y1>>x2 >>y2;
	r1 = make_pair(x1, y1);
	r2 = make_pair(x2,y2);
	for (int i = 0; i < n; i ++) {
		ll tx, ty; cin >> tx >> ty;
		ps.push_back(make_pair(tx, ty));
	}
	sort(ps.begin(), ps.end(), cmp);
	ll res = dis(ps[0], r1);
	ll mr2 = dis(ps[0], r2);
	if (n ==1) {
			cout << min(res, mr2) << "\n";
			return 0;
	}
	for (int i = 1; i <ps.size(); i++){
		//cout << res << " " << mr2 << " "  << ps[i].first <<endl;
		res = min(res, (dis(ps[i], r1) + mr2));
		mr2 = max(mr2, dis(ps[i], r2));
	}
	cout << min(res, mr2) << "\n";


}