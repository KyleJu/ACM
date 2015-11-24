#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> safe, broken;

int main() {
  int high, k; cin >> k >> high;
  for (int i=0; i<k; i++) {
    int n; string s; cin >> n >> s;
    if (s=="SAFE") safe.push_back(n);
    if (s=="BROKEN") broken.push_back(n);
  }
  sort(safe.begin(), safe.end());
  sort(broken.begin(), broken.end());
  if (safe.size()!=0) {
    cout << safe[safe.size()-1]+1;
  }
  else {
    cout << 2;
  }
  cout << " ";
  if (broken.size()!=0) {
    cout << broken[0]-1;
  }
  else cout << high-1;
  cout << endl;
}
