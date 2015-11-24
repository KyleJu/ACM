#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<string, string> pss;

int main() {
  int n; cin >> n;
  vector<pss> v;
  for (int i=0; i<n; i++) {
    string l,f; cin >> f >> l;
    v.push_back(make_pair(l,f));
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << x.second << " " << x.first << endl;
  }
  cout << endl;
}
