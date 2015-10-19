#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double pi = atan(1.0)*4.0;

int main() {
  int n; cin >> n;
  while (n--) {
    int d,r; cin >> r >> d;
    double sphere = (4.0/3.0)*pi*r*r*r;
    double h=r-d;
    double cap=((pi*h*h)*(3*r-h))/3.0;
    cout << fixed << setprecision(2) << sphere-cap <<'\n';
  }
}
