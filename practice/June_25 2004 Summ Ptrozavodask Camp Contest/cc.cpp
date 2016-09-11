#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pait<short,short> pss;
vector<int> arr;
map<pss, short> mm;
unordered_map<int,vector<short>> exist;
bool bs(int l, int r, short ind) {
	
}
int main() {
	int n,tm; cin>>n;
	for(short i = 0; i < n; i++) {
		cin>>tm;
		arr.push_back(tm);
		exist[tm].push_back(i);
	}
	short res = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = i+1 j < n; j++) {
			int l = arr[i];
			int r = arr[j];
			if (mm.find(make_pair(r-l,l)) != mm.end()) {
				//get the highest one uisng multip map 	
			} else {
				mm[make_pair(l,r)] = 0;
			}
		}
	}
}
