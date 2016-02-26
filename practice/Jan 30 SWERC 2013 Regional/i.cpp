#include<iostream>
#include<set>
#include<utility>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
#define pii pair<string, int>
struct cmp{
	bool operator()(const pii& p1, const pii& p2) {
		if (p1.second == p2.second) return p1.first < p2.first;
		return p1.second > p2.second;
		}
};
set<pii,cmp> se;
unordered_map<string, int> map;
vector<vector<string>> days;

int main(){
	string l;
	int n = 0;
	bool isf = true;
	while (cin >>l) {
		if (l == "</text>") continue;
		if (l == "<text>") {
			vector<string> s;
			days.push_back(s);
			n++;
		} else if (l != "<top"){
			//cout << l << endl;
			if (l.size() <=3) continue;
			days[days.size()-1].push_back(l);
		}

		if (l == "<top") {
			int to; string w;
			cin >> to >>w;
			int couter=0;
			while (days.size()> 7) {

				if (!isf&& couter++ <7){
					for (auto st: days[0]){
						se.erase(make_pair(st,map[st]));
						map[st]--;
						if (map[st] == 0) continue;
						se.insert(make_pair(st,map[st]));
					}
				}
				days.erase(days.begin());
			}

			if (isf) {
				//cout <<"go there" <<endl;
				for (auto sv : days) {
					for (auto e: sv) {
						map[e]++;
					}
				}
				for(auto pr:map){
					//cout << pr.first << " " << pr.second << "\n";
						se.insert(make_pair(pr.first, pr.second));
				}
				isf = false; n =0;
			} else {
				//cout << n << " " << days.size() << endl;
				n = min(n, 7);
				while(n) {
					for (auto s1: days[days.size() -n]) {
						se.erase(make_pair(s1, map[s1]));
						map[s1]++;
						se.insert(make_pair(s1,map[s1]));
					}
					n--;
				}
			}
			//print
			cout << "<top " << to << ">" <<"\n";
			int count = 0;
			int la = 0;
			for(auto pr:se){
				count++;
				if (la != pr.second && count > to) break;
				la = pr.second;
				cout << pr.first << " " << pr.second <<"\n";
			}
			cout <<"</top>" <<"\n";
		}
	}
}
