#include<bits/stdtr1c++.h>
 
using namespace std;
#define PI          3.141592653589793238462643383279502884L /* pi */
int main() {
    int t; cin >> t;
    for(int ts = 0; ts < t; ts++) {
            double x = 0, y = 0;
            int cm; cin >> cm; 
          string cc; int degree = 0;
            double va = 0;
            for(int i = 0;  i < cm; i++) {
                cin >> cc >> va;
                double an = ( (degree *PI)/180);
                if(cc == "fd") {
                    x += (va*cos(an));
                    //cout << "fd " << va  << " " << cos(an) << " " << sin(an) << endl;
                    y += (va*sin(an));
                } else if (cc == "lt") degree += va;
                  else if (cc == "bk") {
                     
                    x -= (va*cos(an));
                    y -= (va*sin(an));  
                } else degree -= va;
                degree = (degree + 360) %360;
                //cout << x << " " <<y << " " << an << endl;
            }
            cout << (int)(sqrt(x*x +y*y)+0.5) << endl;
    }
}
