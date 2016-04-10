#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
vector<queue<int>> net;
int ma[202][202];
int pos[202];
int main(){
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	int n; cin>>n;
	memset(ma, -1, sizeof ma);
	net.clear();

	for(int i = 0; i <n-1; i++){
		pos[i] = i+1;
		queue<int> vi;
		for(int j = 0; j < i+1; j++){
			int x ; cin>> x;
			vi.push(x);
		}
		net.push_back(vi);
	}
	pos[n-1] = n;	
	//interation
	for(int i = 1; i <=n-1; i++){
		for(int j = i; j >0; j--){
			int tm = net[n-1-j].front();
			net[n-1-j].pop();
			// think about tm ==0 case for the contradiction
			//cout << n -1 -j << " "  << tm << endl;
			if (tm) {
				if (ma[pos[n-1-j]][pos[n-j]] == -1){
					ma[pos[n-1-j]][pos[n-j]] = 1;
					ma[pos[n-j]][pos[n-j-1]] = 0;
				} else if (ma[pos[n-1-j]][pos[n-j]] == 0) {
					cout << "NO" << "\n";
					return 0;
				}
				swap(pos[n-1-j], pos[n-j]);
			} else {
				if (ma[pos[n-1-j]][pos[n-j]] == -1){
					ma[pos[n-1-j]][pos[n-j]] = 0;
					ma[pos[n-j]][pos[n-j-1]] = 1;
				} else if (ma[pos[n-1-j]][pos[n-j]] == 1) {
					cout << "NO" <<"\n";
					return 0;
				}
			}
		}
	}
	int rr [n];
	for(int i =0;i < n; i ++){
		int tm = pos[i];
		rr[tm] = i+1;	
	}
	cout << "YES" <<"\n";
	for(int i = 1;i <= n; i++){
		cout << rr[i] << " ";
	}
	
}
