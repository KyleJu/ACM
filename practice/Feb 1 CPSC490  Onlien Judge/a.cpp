#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
const ll & M = 49031337; 

vii bks;
vii arr;

// i==0 it is pushing a bucket

ll query(int i, int j, int sz) {
	ll sum = 0;
	while((i%sz) !=0 && i <=j) {
		sum += arr[i] ;
		sum = sum %M;
		i++;
		//cout << sum << " 1\n";
	}
	while(i + sz <=j){
		sum+=bks[i/sz];
		i += sz;
		sum = sum % M;
		//cout << sum << "2 \n";
	}
	while(i <=j) {
		sum += arr[i];
		i++;
		sum = sum % M;
				//cout << sum << " 3\n";
	}
	return sum;
}

int main() {
	int t; cin >>t;
	while (t--) {
		int n; cin >>n;
		bks.clear(); arr.clear();
		int sz = ceil(sqrt(n)); 
		ll sum = 0;
		for (int i =0 ; i < n; i++) {
			//put in buckets
			if(((i%sz) == 0) && (i!=0)){
				bks.push_back(sum);
				sum =0;
			}
			ll tem; cin >> tem;
			arr.push_back(tem);
			sum+=tem;
		}
		//last bucke
		bks.push_back(sum); sum = 0;
		int qs; cin >>qs;
		for (int in = 0 ; in< qs;in++){
			string s; int i,j; cin >> s >>i >>j;
			if (s == "S") {
				//output
				ll res = query(i,j,sz);
				cout << res << "\n";
			}else if (s == "C"){
				//update index
				//cout << bks[i/sz]<< " before update\n";
				bks[i/sz] -= arr[i];
				arr[i] = j;
				bks[i/sz] += j;
				//cout << bks[i/sz]<<" update;\n";
				//update sum
			}
		}
	}
	return 0;
}