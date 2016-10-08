#include<bits/stdtr1c++.h>

using namespace std;
int N;
vector<int> xx;
vector<int> yy;
int main() {
	int ts = 0;
	while(cin >>N) {
		ts++;
		if (N == 0) return 0;
		int a, b;
		xx.clear();
		yy.clear();
		for(int i =0 ; i < N; i++) {
		 	cin >> a >>b;
			xx.push_back(a);
			yy.push_back(b);
		}
		sort(xx.begin(),xx.end());
		sort(yy.begin(),yy.end());
		int resx,resy; 
		if (N&1) {
			resx = N/2;
			resy = N/2;
		} else {
			resx =N/2 -1;
			resy = N/2 -1;
		}
		int to = 0;
		for(int i = 0; i < N; i++) {
			to += abs(xx[i] - xx[resx]);
			to += abs(yy[i] - yy[resy]);
		}
		cout <<"Case " << ts <<": ("<< xx[resx] <<"," << yy[resy]<< ") " << to  <<endl;
	}
}
