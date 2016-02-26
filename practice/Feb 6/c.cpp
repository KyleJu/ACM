#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> arr;
bool cmp(const pii & p1, const pii & p2){
	return (p1.first + p1.second) < (p2.first + p2.second); 
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for (int i =0; i< n; i++) {
		ll x, y; cin>>x >>y;
		arr.push_back(make_pair(x, y));
	}
	sort(arr.begin(), arr.end(), cmp);

	long long res = 0 - arr[0].second;
	long long tw = arr[0].first;
	for (int i = 1; i < n; i ++) {
		res = max(res, tw - arr[i].second);
		tw += arr[i].first;
	}
	cout << res << "\n";
}