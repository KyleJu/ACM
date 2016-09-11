#include <bits/stdtr1c++.h>

using namespace std;

int main() {
  unsigned long long n, m;
  cin >> n >> m;
  unsigned long long res = 2*n*m + n + m;
  cout << min(n*(m+1), m*(n+1)) << endl;
}
