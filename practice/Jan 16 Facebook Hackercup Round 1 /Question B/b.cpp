#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>	
#include<vector>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

struct cmp {
	bool operator()(const pii& a, const pii& b) const{
		if ((a.first + a.second) ==  (b.first + b.second)) return a.first > b.first;
		return a.first + a.second > b.first + b.second;
	}
};
priority_queue<pii, vector<pii>, cmp> avaWM;
priority_queue<pii, vector<pii>, cmp> avaD;

int main() {
	int t; cin >> t;
	for (int ts = 1 ; ts <= t; ts ++) {
		int la,wash, dr, di;
		avaWM = priority_queue<pii,vector<pii>, cmp>();
		avaD = priority_queue<pii, vector<pii>,cmp>();
		cin >> la >> wash >> dr >> di;
		for (int i = 0; i < wash; i++) {
			ll w; cin >> w;
			avaWM.push(make_pair(w,0));
 		}
 		for (int i = 0; i < min(dr, la); i++) {
 			avaD.push(make_pair(0, 0));
 		}

 		//queue keep tracking of next availble machiens 
 		// use this to keep track of current time
 		ll wT = 0;

 		//int d = dr;
 		ll dT = 0;
 		while (la >0) {
 			// one load at a time, keep track of max time for dryers and washing at this point

 			// !!!! some how check the number of machines running !!!!!!
 			pii tem = avaWM.top(); avaWM.pop();
 			pii temDry = avaD.top(); avaD.pop();
 			//update WT
 			//cout << " tem.first " << tem.first << " " << "tem.second " << tem.second <<endl;
 			wT = max(wT, tem.first + tem.second);
 			//cout << "WT " << wT <<endl;
 			// !! somehow ehck the number of dryers running
 			//cout << " d.first " << temDry.first << " " << "d.second " << temDry.second <<endl;
 			//finishing time
 			dT = max(dT, max((tem.first + tem.second), (temDry.first + temDry.second))+ di);
 			//cout << "dT " << dT <<endl;

 			la--;
 			//update the queeu
 			avaWM.push(make_pair(tem.first, tem.first+ tem.second));
 			avaD.push(make_pair(di, max((tem.first + tem.second), (temDry.second + temDry.first))));
 		}

 		ll res= max(wT, dT);
		cout << "Case #" << ts << ": " << res << "\n";
	}
	return 0;
}