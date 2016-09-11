#include<bits/stdtr1c++.h>
using namespace std;
vector<vector<string>> arr;
int main() {
	int n; cin>>n;
	string cc;
	for(int i = 0; i < n; i++) {
		vector<string> tm;
		for(int j = 0; j <7; j++) {
			cin >>cc;
			tm.push_back(cc);
		}
		arr.push_back(tm);
	}
	vector<set<string>> check;
	if(n == 1) {
		set<string> p;
		for(auto ss: arr[0]) {
			p.insert(ss);
		}
		check.push_back(p);
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = i +1; j < n; j++) {
				set<string> p;
				for(auto s1: arr[i]) p.insert(s1);
				for(auto s2:arr[j]) p.insert(s2);
				check.push_back(p);
			}
		}
	}
	int note; cin >> note;
	vector<string> notes;
	for(int i = 0; i < note; i++) {
		cin >>cc;
		notes.push_back(cc);
	}
	int res = 0;
	int index=0;
	while(index < note) {
		int tp = index;
		for (auto pp: check) {
			int cur = tp;
			while(cur <note && pp.find(notes[cur]) != pp.end()) cur++;
			index = max(cur,index);
		}
		res++;
	}
	cout << res << endl;
	
}
