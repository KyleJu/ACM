#include<bits/stdtr1c++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  string s; cin >> s;
  int happy = 0, sad = 0;
  for (int i = 0; i < n - 1; ++i) {
    if ((s[i] == ':' && s[i+1] == '(') ||
        (s[i] == ')' && s[i+1] == ':'))
      sad++;
    else if ((s[i] == ':' && s[i+1] == ')') ||
        (s[i] == '(' && s[i+1] == ':'))
      happy++;
  }
  if (sad == happy)
    cout << "BORED" << endl;
  else if (sad > happy)
    cout << "SAD" << endl;
  else
    cout << "HAPPY" << endl;
}
