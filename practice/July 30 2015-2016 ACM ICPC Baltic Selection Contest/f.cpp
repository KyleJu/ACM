#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long l, r; cin >> l >> r;
    double res = (1.0/l) - (1.0/(r+1));
    cout << fixed << setprecision(9) << res << endl;
  }
}
