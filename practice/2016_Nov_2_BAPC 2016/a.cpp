#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
string s;
 
void solveSmall(int j) {
  for (int i = j; i < s.size(); i++) {
    if (s[i] == 'R') cout << 'S';
    else if (s[i] == 'B') cout << 'K';
    else if (s[i] == 'L') cout << 'H';
  }
}
 
int main() {
  cin >> s;
  int cur = 0;
  while (cur < s.size()) {
    if (cur+2 < s.size()) {
      set<char> ma;
      ma.insert(s[cur]);
      ma.insert(s[cur+1]);
      ma.insert(s[cur+2]);
      if (ma.size() == 3) {
        cout << 'C';
        cur = cur+3;
      } else {
        if (s[cur] == 'R') cout << 'S';
        else if (s[cur] == 'B') cout << 'K';
        else if (s[cur] == 'L') cout << 'H';
        cur++;
      }
    } else {
      solveSmall(cur);
      return 0;
    }
  }
}
