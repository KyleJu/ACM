#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
string rooms;
vector<int> rm;
int n,k;
bool bs(int mid){
	// do the windows
//	cout << "mid is " << mid << endl;
	int l = 0; 
	int r = k;
	//cout << r << " " << rm.size() << endl;
	while(r <rm.size()){
		vector<int>::iterator re;
	//	if (r == rm.size() -1 ){
	//		re = rm.end();
	//	} else {
			re = rm.begin() +  r + 1;
	//	}
		vector<int>::iterator a1 = upper_bound(rm.begin() + l, re, rm[l]+mid);
		
		a1--;
		
		vector<int>::iterator a2 = lower_bound(rm.begin() + l, re, rm[r]- mid);
//		cout << a1 - rm.begin() << " " << a2 - rm.begin() << endl;
		if (a1-a2 >=0 ){
		
			return true;
		}
	 l++; r++;
	}
	

	return false;
}
int main(){
     cin >>n >> k;
	cin >> rooms;
	rm.clear();
	int r= 100000;
	for(int i = 0; i < n; i++){
		if (rooms[i] == '0'){
			rm.push_back(i);
		//r +=i;
	//	cout << i << " ";
		}
	}
//	cout << "\n";
	// left exclusive right inclusive 
	  int l = 0;
	while(l + 1 < r){
		int mid = (l + r)/2;
		//cout << "debug " << mid <<  " " << l << " " << r <<endl; 
		if (bs(mid)) { 
			r = mid;
		} else {
			l = mid;		
		}
	}
	
	cout << r << "\n";
}
