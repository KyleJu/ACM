#include<bits/stdtr1c++.h>

using namespace std;
double sqrsum(double x, double y) {
  return x * x + y * y;
}
int main() {
  double W, H, x[5], y[5];
  cin >> H >> W;
  for (int i = 1; i <= 4; i++) {
    cin >> x[i] >> y[i];
  }
  double AB2 = sqrsum(x[2] - x[1], y[2] - y[1]), e1 = x[1] * (x[2] - x[1]) + y[1] * (y[2] - y[1]);
  double AD2 = sqrsum(x[4] - x[1], y[4] - y[1]), e2 = x[1] * (x[4] - x[1]) + y[1] * (y[4] - y[1]);
  double a1 = x[2] - x[1] - AB2 / W, b1 = y[2] - y[1], c1 = e1;
  double a2 = x[4] - x[1], b2 = y[4] - y[1] - AD2 / H, c2 = e2;
  double X = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
  double Y = (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1);
  cout << X << " " << Y << endl;
  return 0;
}
