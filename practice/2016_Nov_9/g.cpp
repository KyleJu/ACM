#include <bits/stdtr1c++.h>

using namespace std;

typedef pair<long long, string> pls;

int m;
vector<pls> v;

int main() {
  ios_base::sync_with_stdio(0);
  int test; cin >> test;
  while (test--) {
    v.clear();
    cin >> m; 
    for (int i = 0; i < (1<<m); i++) {
      string x; int y;
      cin >> x >> y;
      v.push_back({-1*y,x});
    }
    sort(v.begin(), v.end());
    cout << v[0].second << endl;
    cout << v[1].second << endl;
    int i = 2, sz = 1;
    while (i < v.size()) {
      sz *= 2;
      set<string> names;
      for (int j = 0; j < sz; j++) {
        names.insert(v[i+j].second);
      }
      for (const string &s : names)
        cout << s << endl;
      i += sz;
    }
  }  
}
