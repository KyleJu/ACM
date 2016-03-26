#include<bits/stdtr1c++.h>
using namespace std;

struct Point {
    float x, y, z;
    Point() {}
    Point(float a, float b, float c=0) {
        x = a;
        y = b;
        z = c;
    }
};

 

float dist(Point p) {
    float x = p.x;
    float y = p.y;
    float h = (y-x)*(y-x)*(y-x)*(y-x)/((x-y)*(x-y)*2);
    return h;
}

int main() {
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n;
        int top = 0, mid = 0, bot = 0;
        for (int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            Point tmp = Point(x,y,0);
/*
            if (dist(tmp) <= 10) {
                mid++;
            }
  */          
            if (x == y) {
                mid++;
                continue;
            }
            if (y>x) {
                if(dist(tmp)<=100) {
                    mid++;
                } else {
                    top++;
                }
            } else {
                if(dist(tmp)<=100) {
                    mid++;
                }else {
                    bot++;
                }
            }
        }
        cout << "top: " << top << ", mid: " << mid << ", bot: " << bot <<endl;
    }
}
