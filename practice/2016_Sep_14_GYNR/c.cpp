#include<bits/stdtr1c++.h>

using namespace std;
const int N = 1e9;
vector<long long> ep(long long n) {
	if(n == 1) return {0,1,1,1};
	if(n == 0) return {1,0,0,1};
	vector<long long> res = ep(n/2);
	vector<long long> ne;
	ne.push_back((res[0] *res[0] + res[1] * res[2])%N);
	ne.push_back((res[0] *res[2] + res[1] * res[3])%N);
	ne.push_back((res[2] *res[0] + res[3] * res[2])%N);
	ne.push_back((res[2] *res[1] + res[3] * res[3])%N);
	//cout << ne[0] << " " << ne[1] << " " << ne[2] << " " << ne[3] << " " << n<<endl;
	if(n%2 ==1) {
		vector<long long> nee;
		nee.push_back(ne[2]);
		nee.push_back(ne[3]);
		nee.push_back((ne[0]+ ne[2])%N);
		nee.push_back((ne[1]+ne[3])%N);
		return nee;
	}
	return ne;
}
int main() {
	int n; cin >> n;
	long long k, nn;
	for(int i = 0; i < n; i ++) {
		cin >> k  >> nn;
		if ( nn ==1|| nn ==2) {
			cout << k <<" " << 1 << endl;
			continue;
		}
		vector<long long> res = ep(nn-2);
		cout << k << " " << (res[2]+res[3])%N << endl;
	}
}
