#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//size should be size -1
// for k = left k <= right k++ mistakes
//INF wasnot right
const int & INF = 0x3f3f3f3f;
typedef vector<int> vii;
typedef vector<vii> viii;
viii bks;
vii arr;
int sz;

// i==0 it is pushing a bucket
void findmin(int & min1, int& min2, int &tem) {
		if (tem <= min1){
			min2 = min1;
			min1 =tem;
		} else{
			min2 = min(tem, min2);
		}
}

int query(int i, int j) {
	int min1 = INF;
	int min2 = INF;
	while((i%sz) !=0 && i <=j) {
		// sum += arr[i] ;
		// sum = sum %M;
		findmin(min1,min2, arr[i]);
		i++;
		//cout << sum << " 1\n";
	}
	while(i + sz <=j){
		for (auto tem: bks[i/sz]){
			findmin(min1,min2, tem);
		}
		i += sz;
		//cout << sum << "2 \n";
	}
	while(i <=j) {
		findmin(min1,min2, arr[i]);
		i++;
		//sum = sum % M;
				//cout << sum << " 3\n";
	}
	return min2;
}


void update (int i, int j, int size){
	int min1 = INF;
	int min2 = INF;
	int left = ((int)(i/sz)) *sz;


	int right = min(size-1, left + sz -1);
	arr[i] = j;
	for (int k = left; k <= right; k++){
		int tem  = arr[k];
		findmin(min1, min2, tem);
	}
	vii v;v.push_back(min1); v.push_back(min2);
	bks[i/sz]= v;

}

int main() {
	int t; cin >>t;
	while (t--) {
		int n; cin >>n;
		bks.clear(); arr.clear();
		sz = ceil(sqrt(n)); 
		int min1 = INF;
		int min2 = INF;
		for (int i =0 ; i < n; i++) {
			//put in buckets
			if(((i%sz) == 0) && (i!=0)){
				vii v;
				v.push_back(min1);
				v.push_back(min2);
				bks.push_back(v);
				min1 = INF;
				min2 = INF;
			}
			int tem; cin >> tem;
			arr.push_back(tem);
			findmin(min1,min2,tem);
			//min1 = min(min1,tem);
		}
		//last bucke
		vii v;
		v.push_back(min1);
		v.push_back(min2);
		bks.push_back(v);
		int qs; cin >>qs;
		for (int in = 0 ; in< qs;in++){
			string s; int i,j; cin >> s >>i >>j;
			if (s == "S") {
				//output
				int res = query(i,j);
				cout << res << "\n";
			}else if (s == "C"){
				//update index
				//cout << bks[i/sz]<< " before update\n";
				update(i, j, n);
				//cout << bks[i/sz]<<" update;\n";
				//update sum
			}
		}
	}
	return 0;
}