
#include<bits/stdtr1c++.h>
 
using namespace std;
 
int main() {
  string s; cin >> s;
  int rankk = 25;
  int star = 0;
  int cw = 0;
  for(int i = 0; i< s.length() ;i++) {
    if(s[i] == 'W') {
      star++;
      cw++;
      if(cw >=3&& rankk>=6) star++;
      if(rankk >=21) {
        if(star >2) {
          rankk--;
          star = star - 2;
        }
      } else if ( rankk >=16) {
        if(star >3) {
          rankk--;
          star = star - 3; 
        }
      } else if (rankk >=11) {
        if(star > 4) {
          rankk--;
          star = star - 4;
        }
      } else if ( rankk >=1) {
        if( star >5) {
          rankk--;
          star = star - 5;
        }
      }
 
    } else {
      cw= 0;
      if( rankk >20) {}
      else if ( rankk <= 20&& rankk > 0) {
        if(rankk == 20 && star ==0) {
        } else {
          star--;
          if(star < 0) {
            if(rankk >=15) star +=3;
            else if (rankk >=10) star +=4;
            else if (rankk >= 1) star +=5;
            rankk++;
          }
        }
      } else {}
    }
  }
  if(rankk==0) cout << "Legend"<<endl;
    else cout << rankk << endl;
}
