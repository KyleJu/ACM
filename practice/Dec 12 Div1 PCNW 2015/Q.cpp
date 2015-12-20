#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
using namespace std;
const int INF=numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> v;
  for (int i=0; i<n; i++) {
    int x; cin >> x; v.push_back(x);
  }
  sort(v.begin(), v.end());
  int ret=INF;
  for (int i=0, j=n-1; i<j; i++, j--) {
    ret=min(ret, v[i]+v[j]);
  }
  cout << ret << endl;
}
