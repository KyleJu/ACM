#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int d; cin>>d;
	int dd = d/7;
	int r = d%7;
	int res = (r-5>0)?r-5:0;
	//cout << "debug " << dd << " " << r <<  " "  << res <<" "<<endl; 
	cout << dd*2 +res  << " " << dd*2 + min(r,2);

}
