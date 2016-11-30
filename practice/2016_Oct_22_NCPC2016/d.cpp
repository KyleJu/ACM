#include <bits/stdtr1c++.h>
 
using namespace std;
 
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  int d; cin >> d;
  vector<int> v(d);
  for (int i = 0; i < d; i++)
    cin >> v[i];
  bool buy = true;
  int amt = 100;
  int shares = 0;
  for (int i = 0; i < d; i++) {
    if (buy) {
      if (i != d-1 && v[i+1] > v[i]) {
        buy = false;
        int num_shares = min(100000-shares, amt/v[i]);
        if (num_shares == 0) {
          buy = true;
          continue;
        }
        shares += num_shares;
        amt -= (v[i] * num_shares);
      }
    } else {
      if (shares > 0 && (i == d-1 || v[i+1] < v[i])) {
        buy = true;
        amt += (shares * v[i]);
        shares = 0;
      }
    }
  }
  cout << amt << endl;
}
