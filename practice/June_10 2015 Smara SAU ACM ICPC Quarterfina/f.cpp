#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 5;
int ho[N];
int hoc[N];
int ve[N];
int vec[N];
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	char yard[n+5][m+6];
	for(int i  =0 ; i < n; i ++) {
		cin >>s;
		for(int j = 0; j < m; j++) {
			yard[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < n; i++ ){
		int cur = 0;
		for(int j = 0; j < m; j++) {
			if (yard[i][j] == '+') {
				ho[cur]++;
				cur = 0;
			} else {
				cur++;
			}
		}
		ho[cur]++;
	}	

	for(int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (yard[j][i] == '+' ) {
				ve[cur]++;
				cur = 0;
			} else {
				cur++;
			}
		}
		ve[cur]++;
	}
	/*
	for (int i = 0 ; i <= 4; i++) {
		cout << "ho is: " << ho[i] <<endl;
		cout << "ve is: " << ve[i] <<endl;
	}
	*/
	for(int i = max(m,n); i >0; i--) {
		vec[i] = i * ve[i];
		vec[i] += vec[i+1];
		ve[i] += ve[i+1];
		hoc[i] = i * ho[i];
		hoc[i] += hoc[i+1];
		ho[i] += ho[i+1];
	}
	for (int i = 1; i <= max(m,n); i++) {
		if (i == 1) {
			cout << vec[i] << " ";
		} else {
			//cout << "level" << hoc[i] << " " << vec[i] << " " << ve[i] << " " << ho[i]<< endl;
			cout << hoc[i] + vec[i] - (i-1)*ho[i] - (i-1)*ve[i] << " ";
		}
	}
}
