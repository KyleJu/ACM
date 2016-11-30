#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;
ll n;

ll memo[(int)1e6+5][16];

ll dp(ll col, ll bm) {
  if (col == 0 && bm == 0)
    return 1;
  if (col == 0 && bm != 0)
    return 0;
  if (memo[col][bm] != -1)
    return memo[col][bm];
  ll res = 0;
  if (bm == 0) {
    res += ((2*(dp(col-1, 0)%MOD))%MOD);
    res = res%MOD;
    res += (dp(col-2, 0)%MOD);
    res = res%MOD;
    for (int i = 0; i < 4; i++) {
      ll mask = 0;
      mask = (mask | (1 << i%4));
      mask = (mask | (1 << (i+1)%4));
      res += (dp(col-1, mask))%MOD;
      res = res%MOD;
    }
  } else {
    res += dp(col-1, 0);
    for (int i = 0; i < 4; i++) {
      bm = bm ^ (1<<i);
    }
    res += dp(col-1, bm)%MOD;
    res=res%MOD;
  }
  res = (res+MOD)%MOD;
  return memo[col][bm] = res;
} 

int main() {
  ios_base::sync_with_stdio(0);
  memset(memo, -1, sizeof memo);
  ll res = dp(100000, 0);
  ll t; cin >> t;
  while (t--) {
    cin >> n;
    cout << dp(n, 0) << endl;
  }
}
