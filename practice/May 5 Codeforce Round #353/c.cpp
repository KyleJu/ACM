#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> mm;
int xx[200042];
int main(){
	mm.max_load_factor(0.4);
	mm.rehash(200042);
	int n,x; cin>>n;
	for(int i = 0; i <n;i++){
		cin>>x;
		mm[x]++;
	}
	int m; cin>>m;
	for(int i = 0; i <m; i++){
		scanf("%d", &xx[i]);
	}
	int res = -1;
	int mmax = -1;
	int smax = -1;
	int y;
	for(int i =0; i <m; i++){
		cin >> y;
		int xxx = mm[xx[i]];
		int yyy = mm[y];
		if (xxx>mmax || (xxx == mmax&&yyy >=smax)){
			mmax = xxx;
			res = i+1;
			smax = yyy;
		} 
	}
	cout << res;
}
