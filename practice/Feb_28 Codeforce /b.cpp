#include<iostream>
#include<cstring>
using namespace std;
int a1[200003];
int a2[200003];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	memset(a1, 0, sizeof a1);
	memset(a2, 0, sizeof a2);
	int n; cin >>n;
	for (int i = 0; i < n-1; i ++) {
		int tmp; cin >>tmp;
		if (tmp ==0) {i--;continue;}
		a1[i] = tmp;
		//cerr << a1[i] << " ";
	}
	//cerr << " \n";
	for (int i = 0; i < n-1;i ++) {
		int tmp; cin>>tmp;
		if (tmp ==0) {
			i--;
			continue;
		}
		a2[i] = tmp;
		//cerr << a2[i] << " ";
	}
	//cerr <<"\n";


	if (n <= 3){
		cout << "YES" <<"\n";
		return 0;
	}

	int st = a2[n-2];
	int ii =0;
	//cerr << st << "\n";
	while(a1[ii] !=st) ii++;
	//cerr << ii << '\n';
	for (int i = 0; i < n-2; i++) {
		//cerr << i << " " << a2[i] << " " << (ii +i + 1)%(n-1)  << " " << a1[ii +i] << "\n";
 		if (a2[i] != a1[(ii +i +1)%(n-1)]) {
			cout <<"NO" <<"\n";
			return 0;
		}
	}
		cout << "YES" <<"\n";
}