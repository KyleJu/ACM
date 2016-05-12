#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,k;
vector<ll> needs;
vector<ll> owns;
bool make(ll mid){
	//cout << k << "dfad";
	ll  mp = k;
	for(int i = 0; i <n; i++){
		if (mp <0) return false;
		ll  ne = owns[i] - needs[i] * mid;
		if (ne >=0) continue;
		mp +=ne;
	}
   // cout << mid << " " << mp << endl;
	return mp >=0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	cin >> n >>k;
	for(int i = 0; i < n; i++){
		int x; cin >>x;
		needs.push_back(x);
	}
	for(int i = 0; i <n; i++){
		int y; cin>>y;
		owns.push_back(y);
	}
	long long left = 0;
	long long right = 2*(1e9 +5);
	while(left + 1 < right){
		int mid = (left + right)/2;
	//	cout << mid <<endl;
		if (make(mid)){
			left = mid;
		} else {
			right = mid;
		}
	}
	cout << left;

}
