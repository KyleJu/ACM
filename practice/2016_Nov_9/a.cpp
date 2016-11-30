#include <bits/stdtr1c++.h>

using namespace std;

unsigned int c, d;

int main() {
  int t; cin >> t;
  while (t--) {
    cin >> c >> d;
    bitset<32> cb(c);
    bitset<32> db(d);
    bitset<32> ab, bb;
    vector<int> pos;
    bool flag = false;
    for (int i = 0; i < 32; i++) {
      if (cb[i] == 1 && db[i] == 0) {
        flag = true;
        cout << -1 << endl;
        break;
      }
      if (cb[i] == 0 && db[i] == 0) {
        continue;
      } else if (cb[i] == 1 &&  db[i] == 1) {
        ab[i] = bb[i] = 1;
      } else {
        pos.push_back(i);
      }
    }
    if (flag) continue;
    if (pos.size() > 1) {
      for (int i = 0; i < pos.size() - 1; i++) {
        ab[pos[i]] = 1;
      }
    }
    if (!pos.empty()) {
      bb[pos[pos.size()-1]] = 1;
    }
    cout << ab.to_ulong() << " " << bb.to_ulong() << endl;
  }
}
