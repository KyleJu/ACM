#include<bits/stdtr1c++.h>

using namespace std;
vector<long long> S1,S2,S3;
int main() {
	S1.push_back(0);
	S2.push_back(0);
	S3.push_back(0);
	for(int i = 1; i <= 20010; ++i) {
		S1.push_back(S1[S1.size()-1] + i);
		if(i&1) {
			S2.push_back(S2[S2.size() -1] +i);
		} else {
			S3.push_back(S3[S3.size()-1] + i);
		}
	}
	int n; cin >>n;
	int k,c;
	for(int i = 0; i < n; i++) {
		cin >> k >>c;
		cout << k << " " << S1[c] << " " << S2[c] << " " << S3[c] << endl;
	}
	

}
