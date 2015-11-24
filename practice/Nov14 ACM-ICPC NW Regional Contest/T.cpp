#include<iostream>
#include<algorithm>

int T1[5], T2[5];


using namespace std;


int main(void) {
  for(int i=0;i<3;i++) {
    cin>>T1[i];
  }
  for(int i=0;i<3;i++) {
    cin>>T2[i];
  }
  sort(T1,T1+3);
  sort(T2,T2+3);
  if(T1[0]!=T2[0]
     || T1[1]!=T2[1]
     || T1[2]!=T2[2] ) {
    cout << "NO" << endl;
    return 0;
  }
  if(T1[0]*T1[0] + T1[1]*T1[1] != T1[2]*T1[2]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
