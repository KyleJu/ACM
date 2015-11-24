// D2UBC&
#include<iostream>
#include<string>
#include<unordered_set>
#include<cstring>

using namespace std;
int arr[105];
bool ok[105];
unordered_set<int> os;

int main() {
  int n; cin >> n;
  for(int i=0; i<=100; i++) {
    arr[i]=i;
    ok[i]=true;
  }
  for (int op=0;op<n;op++) {
    string s; int num;
    cin >> s >> num;
    for(int i=1; i<=100; i++ ) {
      if(!ok[i]) continue;
      
      if (s=="ADD") {
	arr[i]+=num;
	continue;
      }
      if (s=="MULTIPLY") {
	arr[i]*=num;
	continue;
      }
      if (s=="SUBTRACT") {
	if(arr[i]-num < 0) {
	  ok[i] = false;
	} else {
	  arr[i]-=num;
	}
	continue;
	// for (int j=1; j<num; j++) {
	//   os.insert(j);
	// }
      }
      if (s=="DIVIDE") {
	if(arr[i]%num != 0) {
	  ok[i]=false;
	} else {
	  arr[i] /= num;
	}
	// for (int j=1; j<=100; j++) {
	//   if (j%num!=0) {
	//     os.insert(j);
	//   }
	// }
      }

    }
  }
  int ans=0;
  for(int i=1; i<=100; i++) {
    if(!ok[i]) 
      ans++;
  }
  cout << ans << endl;
  // cout << os.size() << e    ndl;
}
