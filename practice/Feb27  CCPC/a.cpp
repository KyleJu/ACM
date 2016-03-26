#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
	int ts; cin>> ts;
	while(ts--) {
		ll arr[4];
		string s1; cin >>s1;
		int ii = 0;
		while(s1[ii] != 'N') {
			ii++;
		}
		if(s1[ii-1] == '^') {
			arr[0] = 3;
		} else if (s1[ii+1] == ')') {
			arr[0] = 0;
		} else if (s1[ii+1] == '!') {
			arr[0] = 4;
		} else if (s1[ii+1] =='^')  {
			arr[0] = (ll)s1[ii+2] - '1';
		}
		//cout << arr[0] << "\n";

		for (int i =1; i<=3; i++){
			ll s; cin >>s;
			arr[i] = 	s;
		}
		long double pc = (100000000 *arr[3])/arr[2];
		bool pas;
		if (arr[0] <=2) {
			ll temp = 1;
			for (int i = 0; i <= arr[0]; i++) {
					temp *= arr[1]; 
			}
			if (temp <= pc) {
				pas = true;
			} else {
				pas = false;
			}

		} else if (arr[0] == 3) {
			if (log2(pc) <= (long double)arr[1]) {
				pas = false;
			} else {
				pas = true;
			}

		} else {
			long double temp = 0;
			for (int i = 1; i <= arr[1]; i++) {
				temp += log2(i);
			}
			if (temp <= log2(pc)) {
				pas = true;
			} else {
				pas = false;
			}
		}

			if (pas) {
				cout << "May Pass." <<"\n";

			} else {
				cout << "TLE!" << "\n";
			}
	}
}
