#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

//mistakes
// when do the prefix sum, you need to start from the index L-1
// because For each L,R = K, you use arr[R] ^/- arr[L-1] to figure out what the result of this range
// for prefix use arr[x]^k or arr[x] - k to find the result
// and c[arr[x]]++;
// const for the function
int n, m, k;
typedef long long ll;
struct q{
	int s, e, i;
	bool operator<(const q& o) const {
		if ((int)(s/sqrt(n)) == (int)(o.s/sqrt(n))) return e <o.e;
		return (int)(s/sqrt(n)) < (int)(o.s/sqrt(n));
	}
};
vector<int> arr;
vector<q> qs;
ll res[100001];
ll A;
// frequency count
// (note xor values can exceed 1000000, and the upper limit is 2^20-1)
int c[1<<20];


inline void inc(int x) {
	A += c[arr[x]^k];
	c[arr[x]]++;
}

inline void dec(int x) {
	c[arr[x]]--;
	A -= c[arr[x]^k];
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	arr.push_back(0);
	for (int i =1; i <= n; i++) {
		int temp; cin >> temp;
		arr.push_back(temp);
	}
	//prefix xor array
	for(int i = 1; i <= n; i++) {
		arr[i] = arr[i-1]^arr[i];
	}
	// queries
	for(int i = 0; i < m;i ++) {
		q t; cin>> t.s >> t.e;
		t.i = i;
		qs.push_back(t);
	}
	sort(qs.begin(), qs.end());
	int L = qs[0].s; int R = qs[0].e;
	// think about left index
	for (int i = L -1; i <= (R);i++)
		inc(i);
	res[qs[0].i] = A;
	for (int i = 1; i < m; i++) {
		while(L < qs[i].s){
			dec(L-1); 
			L++;
		}
		while (L> qs[i].s) {
			L--;
			inc(L-1);
		}
		while (R > qs[i].e) {
			dec(R);
			R--;
		}
		while(R<qs[i].e) {
			R++;
			inc(R);
		}
		res[qs[i].i] = A;

	}
	for (int i = 0; i <m; i++){
		cout << res[i] <<"\n";
	}
	return 0;
}