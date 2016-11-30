#include<bits/stdtr1c++.h>

using namespace std;
const int N = 10005;
int arr[N];
int bomb[N];
int memo[N][2];
int d;
int dp(int n, bool p) {
  if(n == -1) return 0;
  if(memo[n][p] != -1) return memo[n][p];
  int cost = arr[n];
  if(p) cost -= bomb[n+1];
  // explode before n -1
  long long res = 0x3f3f3f3f;
   res = (cost<=0? 0: ((cost + d-1)/d) + dp(n-1, 1));
  //cout << res << " " << cost << " before " << n-1 << " is bm one" << endl;
  if(n !=0) {
    cost = cost - bomb[n-1];
    cost = cost <=0? 0: cost;
    res = min(res, ((cost + d-1)/d) + dp(n-1,0));
  }
  //cout << res << " " << cost << " after " << n-1 << " is bm 0" << endl;

  memo[n][p] = res;
  return res;
}
int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);
  int ts; cin>>ts;
  for(int i = 0; i < ts; i++) {
    int n; cin >> n >>d;
    for(int bb = 0 ; bb < n ;bb++) {
      cin >> arr[bb];
    }
    for(int bb = 0; bb < n; bb++) {
    
      cin >> bomb[bb]; 
    }
    int res = 0x3f3f3f3f;
      memset(memo, -1, sizeof memo);
      res = min (res,dp(n-1, 0));
     // cout << res << " choose " << bb << " to bmb first " << endl;

    cout << res << endl;


  }

  
}
