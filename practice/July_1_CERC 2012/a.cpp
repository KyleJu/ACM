#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
const int SIZE = 21;
int ma[SIZE][SIZE];
int sum[SIZE];
int N;		
set<int> list;
bool memo[(1<<SIZE)];
// log2 has precision loss, logs(64) = 5.99999
void ba(int bm, int ii) {
	for(int i = 0 ; i < N; i ++) {
		if (bm & (1<<i))
		sum[i] += ma[ii][i];
	}
	sum[ii] = 0;
}
void iba(int bm, int ii) {
	int tm = 0;
	for(int i = 0; i < N; i++) {
		if (bm &(1<<i)) {
			sum[i] -= ma[ii][i];
			tm += ma[ii][i];
		}
	}
	sum[ii] = tm;
}
void recur(int bm) {
	if (memo[bm]) return;
	memo[bm] = true; 
	if (bm == 0) return;
	/*
	cout << bm << endl;
	for(int i = 0; i < N; i++) {
		cout << sum[i] << " ";
	}
	cout << "\n";
	*/
	for(int i = 0; i < N;i++) {
		if ((bm & (1<<i)) && (sum[i] >0) && !memo[bm - (1<<i)]) {
			ba(bm,i);
			recur(bm - (1<<i));
			iba(bm,i);
		}
	}

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ts; cin>>ts;
	while(ts--) {
		cin >>	N;
		list.clear();
		memset(ma,0,sizeof ma);
		memset(memo, 0, sizeof memo);
		memset(sum, 0, sizeof sum);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j <N; j++) {
				cin>>ma[i][j];
				sum[i] +=ma[i][j];
			}
		}
		int ss = (1<<N) -1;
		recur(ss);
		bool has= false;
		for(int i = 0; i < N; i++) {
			if (memo[1<<i]) {
			cout << i+1 << " ";
			has = true;
			}
		}
		if (!has) cout << 0;
		cout << "\n";
	}
}
