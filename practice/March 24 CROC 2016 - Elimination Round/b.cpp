#include<iostream>

typedef long long ll;
using namespace std;

int main(){
	ll n, min; cin >>n >> min;
	if (min >= n/2) {
		cout << (n-1)*n/2 << "\n";
		return 0;
	}
	ll res =0;
	for(int i=1 ;i <=min; i++){
		res = res + n - i;
	}
	res += (n-2*min)*min;
	res += ((min -1) *min)/2;
	cout << res << "\n";
}
