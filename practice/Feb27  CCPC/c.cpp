#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
int memo[34000][2];
int memo2[34000][2][2];
int rightmost, len;

int sz;
int flip(int a, int b, int bm){
	for(int i = a ; i<=b;i ++){
		bm^=1<<(sz-i-1);
	}
	return bm;
}
int dp(int bm, int turn){
	if (memo[bm][turn] != -1) return memo[bm][turn];
	int ans = turn^1;
	for (int i = 0; i < sz; i++){
		for(int j = i ; j< sz; j++){
			if (bm & 1<<(sz-j -1)){
				if (dp(flip(i,j,bm), turn^1) == turn) {
					if (turn ==1){
						if (rightmost <j) {
						rightmost = j;
						len = j-i+1;
						
						}
					}
					return memo[bm][turn] = turn;	
				}
			}
		}		
	}
	return memo[bm][turn] = ans;
}
int main(){
	int T; cin >> T;
	while(T--){
		string s; cin>> s;
		reverse(s.begin(), s.end());
		int start = 0;
		sz = s.size();
		for(int i = 0; i < sz; i++){
			if (s[i] == 'H'){
				start |= 1 << (i);
			}
		}
		rightmost = -1;
		memset(memo,-1,sizeof memo);
		memo[0][0] =1;
		memo[0][1] = 0;
		if (dp(start,1)) {
			cout << "YES" << " " << rightmost +1<<" " << len <<"\n";
		} else {
			cout << "NO" << endl;
		}
	}
}
