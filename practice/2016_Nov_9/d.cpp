#include <bits/stdtr1c++.h>

using namespace std;

int n;
set<int> seen;

int main() {
  int t; cin >> t;
  while (t--) {
    seen.clear();
    cin >> n;
    bitset<16> bits;
    int cnt = 0;
    int val;
    while (cnt != (1<<n)) {
      val = bits.to_ulong();
      // If this number has not been visited before
      if (seen.find(val) == seen.end()) {
        cout << val << endl;
        seen.insert(val);
        cnt++;
      } 
      // try iterating through every bit, keeping it fixed and flipping all the
      // rest, pick the first transtition that goes to an unvisited number
      bitset<16> tmp;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            // Keep bit i fixed.
            tmp[j] = bits[j];
          } else {
            // Flip all other bits.
            tmp[j] = !bits[j];
          }
        }
        if (seen.find(tmp.to_ulong()) == seen.end()) {
          bits = tmp;
          break;
        }
      }
    }
  }
}
