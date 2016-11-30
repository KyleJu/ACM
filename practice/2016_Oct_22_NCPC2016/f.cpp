#include <bits/stdtr1c++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
  ld num, po; cin >> num >> po;
  ld ans = 0;
  ld tmp = po/(num+1);
  ans = max(ans, tmp);
  for (int x = 2; x <= 1000000; x++) {
    tmp = tmp * ((x*(num+x-po)) / ((num+x)*(x-1)));
    // cout << "tmp: " << tmp << endl;
    ans = max(ans, tmp);
  }
  cout << fixed << setprecision(10) << ans << endl;
}
