#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define mk(a,b) make_pair(a,b);
unordered_map<string, pair<string,string>> lm;
unordered_map<string,string> sm;
string dfs(const string& w) {
	if (lm.find(w) != lm.end()) {
		return dfs(lm[w].first) + dfs(lm[w].second);
	} else {
		return sm[w];
	}
	return "";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	lm.max_load_factor(0.8);
	sm.max_load_factor(0.8);
	lm.rehash(5000);
	sm.rehash(5000);
	vector<string> tm;
	int ts; cin >>ts;
	while(ts--) {
	int n; cin >>n;
	string s,w;
	lm.clear();sm.clear();
	getline(cin,s);
	tm.clear();
	for(int i = 0; i < n; i ++) {
		getline(cin,s);
		stringstream ss;
		ss << s;
		while(ss>>w) {
			tm.push_back(w);
		}
		//cout << tm.size() << endl;
		if (tm.size() == 5) {
			lm[tm[0]] = mk(tm[2], tm[4]); 
		} else {
			sm[tm[0]] = tm[2];
		}
		tm.clear();
	}
	string st; cin >>st;
	string pattern; cin >>pattern;
	string word = dfs(st);
	int ind = 0;
	for(int i = 0; i < word.length(); i++) {
		if (word[i] == pattern[ind]) {
			ind++;
			if (ind == pattern.length()) break;
		}
	}
	if (ind == pattern.length()) {
		cout <<"YES" <<"\n";
	} else {
		cout << "NO" <<"\n";
	}
}
}
