#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef double ld;
typedef vector<ld> vii;
vii arr;
int N;
ld memo[1400][1400];
int main(){ 
	while(cin >> N){
		memset(memo, 0.0, sizeof memo);
		arr.clear();
		arr.push_back(1);
		for (int i = 0; i <N; i ++) {
			ld a; cin>>a;
			arr.push_back(a/100.0);
		}
		sort(arr.begin(), arr.end(), greater<ld>());
		memo[0][0] = 1.0;
		for (int i= 0; i <=N; i++){
			for(int j = 0; j <=N; j++) {
				if (i== 0 && j ==0) continue;
				else if (i==0) memo[i][j] = 0;
				else if (j ==0) memo[i][j] = memo[i-1][j]*(1-arr[i]);
				else if (i < j) memo[i][j] = 0;
				else memo[i][j] = memo[i-1][j]*(1-arr[i]) + memo[i-1][j-1]*arr[i];
			}
		}
		ld res = 0;
		for(int i = 0; i <=N; i ++) {
			double tmp = 0;
			for (int j = 1; j <=N; j++) {
				if (i%2==1 && j >i/2){
					tmp +=memo[i][j];
				}
			}
			res = max(res, tmp);
		}
		cout << fixed << setprecision(5) << res << endl;
	}

}