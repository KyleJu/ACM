#include<iostream>
#include<vector>
using namespace std;

int main(){
	long long n,k; cin>> n>>k;
	vector<int> arr;
	for(int i =0; i < n; i++){
		int x; cin>> x;
		arr.push_back(x);
	}
	long long res= 1;
	long long num = 1;
	while(num <=k){
		res++;
		num = (res*(res+1))/2;
	}
	res --;	
	int re = k - (res*(res+1))/2;
	if (re ==0){
		cout << arr[res-1];
		return 0;
	}
	cout << arr[re-1];


}
