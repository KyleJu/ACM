#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool arr[1005];
vector<int> a;
int main(){
	int t; cin >>t;
	while (t-- ){
		memset(arr, 0, sizeof arr);
		a.clear();
		int m; cin>>m;
		int u ; cin >>u;
		for (int i = 0; i < m-1; i++) {
			int tm; cin>>tm;
			a.push_back(tm);
		}
		u += a[m-2];
		int ans =0;
		for (int i = m-3; i >=0; i--){
			if (arr[i]) continue;
			//int tem = -1;
			for (int j = i-1; j>=0; j--){
				if ((a[i] + a[j] < u) && !arr[j]) {
					//cout << i << " " << j  <<  " "<< a[j]  << " " << a[i]<< " " << u<<endl;
					arr[j] = true;
					ans++;
					break;
				}
			}
		}

		cout << m/2 - ans << endl;
	}
}