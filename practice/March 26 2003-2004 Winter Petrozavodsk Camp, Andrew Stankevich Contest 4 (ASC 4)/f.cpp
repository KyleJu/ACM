#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ar;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("positive.in","r",stdin);
    freopen("positive.out","w",stdout);
	int n; cin>>n;
	int mmin=0;
	int tmm = 0;
	int res = 0;
	for(int i = 0;i <n; i++){
		int tm; cin >>tm;
		res +=tm;
	}
	cout <<max(0, res)<<endl;

}
