#include<bits/stdtr1c++.h>

using namespace std;
map<vector<int>,int> q1;
map<int, vector<int>>q2;
short arr[6];
int cur = 0;
void gen(int nn) {
	if (nn ==6) {
		int	to = 0;
		for(int i = 0; i < 6; i++) to +=arr[i];
		if(to == 15) {
			vector<int> k;
			for(int i = 0; i < 6; i++) k.push_back(arr[i]);
			q1[k] = cur;
			q2[cur] = k;
			cur++;
		}
	} else {
		for(int i = 0; i <= 15; i++) {
			arr[nn] = i;
			gen(nn+1);
		}
	
	}

}
int main() {
	char c;
	gen(0);
	int ts = 0;
	while(cin >>c ) {
		ts++;
	if (c == 'e') return 0;
		if (c == 'm') {
			int cc;
			vector<int> cur;
			for(int i = 0; i < 6; i++) {
					cin >> cc;
					cur.push_back(cc);
					}
					cout << "Case " << ts << ": " << q1[cur] << endl;	
		} else {
			int cc; cin >>cc;
			cout << "Case " << ts << ": ";
			for(auto vv: q2[cc]) cout << vv << " ";
			cout <<endl;
		}
	}

}
