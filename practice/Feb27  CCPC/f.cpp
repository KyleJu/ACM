#include<bits/stdtr1c++.h> 
using namespace std;
typedef long long ll;
  
int main() {
    int t; cin >> t;
    while (t--) {
        ll r, b; cin >> r >> b;
        double s = sqrt(2)*r;
        if (s <= b) {
            cout << setprecision(3) << fixed << s*s<< endl;
        } else {
            double h = sqrt(4.0*r*r-b*b);
            cout << setprecision(3) << fixed << h*b << endl;
        }
    }
}

