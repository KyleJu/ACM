#include <bits/stdtr1c++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n, x, m;
  string s, p;
  cin >> n >> x >> s >> m >> p;
  string ans = "";
  ans += s[x-1];
  for (int i = 0; i < m; ++i) {
    if (p[i] == 'R')
      ++x;
    else
      --x;
    ans += s[x-1];
  }
  cout << ans << endl;
}
