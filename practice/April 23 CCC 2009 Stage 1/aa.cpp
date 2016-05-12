#include<iostream>
#include<vector>
using namespace std;
vector<int> s = {1,64,729,4096,15625,46656,117649,262144,531441,1000000,1771561,2985984,4826809,7529536,11390625,16777216,24137569,34012224,47045881,64000000,85766121};
int main(){
	int a ,b; cin>> a>>b;
	int res = 0;
	for(int i = 0; i < 21;i++){
		if (s[i] >= a && s[i] <=b) res++;
	}
	cout << res;
}
