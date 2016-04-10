#include<iostream>
#include<cstring>
using namespace std;
int ma[5005][5005];
int main(){
	int ts; cin >>ts;
	while(ts--){
		int n,m; cin >> n >> m;
		memset(ma, 0, sizeof ma);
		for(int i = 0; i < m; i ++){
			int a,b; cin >> a >> b;
			ma[a][b] = 1;
			ma[b][a] = 1;
		}

		for(int i = 0; i < n; i++){
			for (int j= i+1; j < n; j++){
				if (ma[i][j]) continue;

			}
		}
	}

}
