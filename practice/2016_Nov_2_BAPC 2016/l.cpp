#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int N = 20005;
int n;
ll arr[N];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n-1; j++) {
      if (arr[i] + arr[j] > arr[j+1]) {
        cout << "possible" << endl;
        return 0;
      }
    }
  }
  cout << "impossible" << endl;
}
