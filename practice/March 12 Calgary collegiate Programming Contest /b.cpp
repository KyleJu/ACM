#include<iostream>

using namespace std;



int main(void) {
    int n; cin >> n;

    for(int i=0; i<n; i++) {
        char prev, at;
        cin >> prev >> at;
        string ans;
        if(prev == 'N') {
          if(at == 'S')  {
            ans = "U-turn";
          } else if(at == 'E') {
            ans = "right";            
          } else if(at == 'W') {
            ans = "left";
          }
        }else if(prev == 'S') {
           if(at == 'N')  {
 ans = "U-turn";

          } else if(at == 'E') {
            ans = "left";
          } else if(at == 'W') {
            ans = "right";  
          } 
        }else if(prev == 'E') {
          if(at == 'S')  {
            ans = "right";  
          } else if(at == 'N') {
            ans = "left";
          } else if(at == 'W') {
 ans = "U-turn";

          }
        }else {
          if(at == 'S')  {
            ans = "left";
          } else if(at == 'E') {
 ans = "U-turn";

          } else if(at == 'N') {
            ans = "right";  
          }
        }
        cout << ans << endl;
    }

    return 0;
}
