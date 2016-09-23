#include<iostream>
#include<string>
using namespace std;

int bs(long long x) {
	if (!x) return 0;
	int right = 0x3f3f3f3f;
	for(long long i = 0; i < 1e6 +3; i++) {
		if(i*i -i == 2*x) return i;
	}
	return right;
}
bool check(int& z, int& o, int& a1, int& a2) {
	if(z == 0) {
		if(o == a2+a1) {
			z = 1;
			return true;
			}
	} 

	if(o ==0){
		if(z == a1+a2){
			o = 1;
			return true; 
		}
	}
	if(z ==0 && o ==0) {
		if(a1+a2==1) return true;
	}
	return z*o == a1+a2;
}
int main() {
	int a0,a1,a2,a3; cin >> a0>> a1 >> a2 >> a3;
	int z = bs(a0);
	int o = bs(a3);
	if (z == 0x3f3f3f3f || o  == 0x3f3f3f3f) {
		cout << "Impossible" << "\n";
		return 0;
	}
	//cout << z << " " << o << " " << a2 << " " << a1 << endl;
	if(!check(z,o,a1,a2)) {
		cout << "Impossible" <<"\n";
		return 0;
	}
	if( z== 0 && o == 0) {
		if(a1==0 && a2 == 0) cout << "0" << endl;
		if(a1 == 1) cout <<"01" << endl;
		if(a2 == 1) cout << "10" << endl; 
		return 0;
	}
	char arr[2*(z+o) +5];
	int k = 0;
	for(; k < z; k++) arr[k] = '0';
	for(; k <z+o; k++) arr[k] = '1';
	int shift = 0;
	int ca1 = z*o; int ca2 = 0;
	while(ca2 + o < a2) {
		swap(arr[shift++], arr[k++]);
		ca1 -=o;
		ca2 +=o;
	}
	int tmz = z;
	while(ca2 !=a2) {
		swap(arr[z], arr[z-1]);
		z++;
		ca1--;
		ca2++;
	}
	string res;
	//cout << tmz << " "  << o << endl;
	int os= shift;
	for(; shift<tmz+o+os; ++shift) {
		res += arr[shift];
		//cout << arr[shift] << "here\n";
	}
	cout << res<<"\n";


}
