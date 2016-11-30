#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
      int w; cin >> w;
      ll tmp = 0;
      for (int j = 0; j < w; j++) {
        int x; cin >> x;
        tmp += x;
      }
      v[i] = tmp;
    }
    sort(v.begin(), v.end());
    vector<ll> w(n);
    w[0] = v[0];
    for (int i = 1; i < n; i++) {
      w[i] = w[i-1] + v[i];
    }
    ld res = 0;
    for (const ll &x : w)
      res += x;
    res /= n;
    cout << fixed << setprecision(10) << res << endl;
  }
}
