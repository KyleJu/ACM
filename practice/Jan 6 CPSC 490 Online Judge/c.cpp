#include<iostream>
#include<utility>
#include<algorithm>
#include<set>
#include<cmath>
#include<iomanip>
#include<limits>
#include<cstring>
using namespace std;

// forget to clear set
// forget to sort before using next_permu
// a.fisrt == b.first
// pair has default comparator
// set<pii, cmp1>::iterator  forgot cmp!!
//	boxes.insert(tem); forget to insert!!!!!!!!!!!!
// look through your codee!!!!!
#define pii pair<double,double>
pii arr[10005];
pii permu[4];
//const double& INF = numeric_limits<double>::max();

bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
struct cmp1 {
bool operator()(const pii& a, const pii& b) const {
		if (a.second == b.second ) return a.first > b.first;
		return a.second > b.second;
	}	
};

set<pii, cmp1> boxes;

double calpt(pii a, pii b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double cald() {
	sort (permu, permu +4);
	double res = 10000.0;
	do {
		double temp = 0.0;
		for (int i = 0; i < 4; i++) {
			temp += calpt(permu[i], permu[(i+1)%4]);
		}
		res = min(res, temp);
	}while(next_permutation(permu, permu + 4));
	return res;
}

int main() {
	int t; cin >>t;
	while(t--) {
		int n; cin >> n;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i< n; i++) {
			double x,y; cin >> x >>y;
			arr[i] = make_pair(x,y);
		}
		//
		sort(arr, arr + n, cmp);
		boxes.clear();
		//start
		for (int i = 0; i< 4; i++) {
			permu[i] = arr[i];
			boxes.insert(arr[i]);
		}
		double res = cald();
		int lp = 0;
		set<pii, cmp1>::iterator bot, top, y, z;
		for (int i = 4; i< n; i++) {
			pii tem = arr[i];
			// erase all points beyond res/2 for x
			while (tem.first - res/2 -1 > arr[lp].first) {
				boxes.erase(arr[lp]);
				lp++;
			}
			if (boxes.size() <3) {
				boxes.insert(tem);
				continue;
			}
			//try all the perumuations
			 bot = boxes.upper_bound(make_pair(tem.first + 2, tem.second - res/2 -1));
			 top = boxes.lower_bound(make_pair(tem.first + 2, tem.second + res/2 +1));
			 for (;top != bot; top++) {
			 	y = top; ++y;
			 	for (; y != bot; y++) {
			 		z = y; ++z;
			 		for (; z != bot; z++) {
			 			permu[0] = tem; permu[1] = *top; permu[2] = *y; permu[3] = *z;
			 			res = min(res, cald());
			 		}
			 	}
			 }
			 boxes.insert(tem);
		}
		cout << fixed;
		cout << setprecision(4) << res << "\n";
	}
	return 0;
}