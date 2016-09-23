#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
const int M = 1e9 +7;
vector<int> arr1;
vector<int> arr2;
map<int,int> mm;
int a,b;
bool pr(int su, int bm2) {
	int bm1 = mm[su];
	long double sum1 = 0;
	int s1 = 0,s2 =0;
	vector<int> v1,v2;
	for(int i = 0; i <a; i++) {
		if(bm1 &(1<<i)) {
			sum1 += log(arr1[i]);
			s1++;
			v1.push_back(arr1[i]);
			}
	}
	for(int i = 0; i < b; i++) {
		if(bm2 & (1 <<i)){
		sum1 -= log(arr2[i]);
		s2++;
		v2.push_back(arr2[i]);
		}
	}
	if(sum1 > -2 && sum1<2) {
		cout << "Y" <<endl;
		cout << s1 << " " <<s2 <<endl;
		for(auto ss: v1) cout << ss << " ";
		cout << "\n";
		for(auto ss:v2) cout << ss << " ";
		return true;
	}
	return false;

}
int main() {
	cin>> a >>b;
	int tm;
	for(int i = 0; i < a; i++) {
		cin >>tm; 	
		arr1.push_back(tm);
	}
	for(int i = 0; i < b; i++) {
		cin >>tm;
		arr2.push_back(tm);
	}
	int bm = 1<<a;
	long long sum = 1;
	for(int i = 1; i <bm; i++) {
		sum = 1;
		for(int j =0; j < a; j++) {
			if(i&(1<<j)) sum = (sum*arr1[j])%M; 
		}
		mm[sum] = i;
	}
	bm = 1<<b;
	bool f = false;
	for(int i = 1; i < bm; i++) {
		sum = 1;
		for(int j = 0; j < b; j++) {
			if(i&(1<<j)) sum = (sum*arr2[j])%M;
		}
		if(mm.find(sum) != mm.end()) {
			f = pr(sum, i);	
			if(f) break;
		}
	}
	if(!f) cout << "N" <<endl;

}
