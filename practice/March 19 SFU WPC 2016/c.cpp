#include<iostream>

using namespace std;

int main(){
	int r;
	while(cin>>r){
	int p; cin>>p;
	r++;
	long long a = r*p - abs(r-p);
	r --;
	p++;
		long long b = r*p - abs(r-p);
		if (a >b) {
			cout << "Technical"<<endl;
		}else if (a<b) {
			cout << "Interpersonal" <<endl;

		} else if (a ==b) {
			cout <<"Either" << endl;
		}

}
}