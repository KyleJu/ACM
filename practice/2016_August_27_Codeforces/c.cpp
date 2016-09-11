#include<bits/stdtr1c++.h>
using namespace std;
typedef long long ll;
map<int,ll> ma;
int main() {
	int n,m; cin >> n>>m;
	int tm,tt,c;
	for(int i = 0; i< n; i++) {
		tm = 0;
		cin >>c;
		for(int j = 0; j < c; j++) {
			cin>>tt;
			tm = tm | (1<<tt);
		}	
		ma[tm]++;
		//cout << ma[tm] << " " << tm <<endl;
	}
	ll res = 0;
	for(auto mm: ma) {
		res +=((mm.second *(mm.second -1))/2);
	}
	//cout << res << endl;
	double check; cin >> check;
	map<int,ll>::iterator ii = ma.begin();
	for(; ii != ma.end(); ii++) {
		map<int,ll>::iterator jj = ii;
		jj++;
		for(; jj != ma.end(); jj++) {
			double bc = __builtin_popcount(ii->first&jj->first);	
			double ic = __builtin_popcount(ii->first);
			double jc = __builtin_popcount(jj->first);
			double dd;
			if( ic+jc - 2*bc ==0) {
				dd = 1.0;
			} else {
			
			dd = bc/(ic+jc - bc);
			}
			//cout << dd <<" " << check <<  endl;
			//cout << ic << " " << ii->first << " " << jc << " " << jj->first << endl;
			if(dd >=check) res +=(ii->second * (jj->second));
		}
	}
	cout << res << "\n";
}
