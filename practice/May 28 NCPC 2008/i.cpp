#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int c,n,a;
vector<int> arr;
unordered_map<int, vector<int>> ma;
map<int, int> mm;
int fn (int index, int cur) {
	vector<int> id = ma[index];
	vector<int>::iterator it  = upper_bound(id.begin(), id.end(),cur);
	if (it == id.end()) {
		return 0x3f3f3f3f;
	} 
	return *it;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> c >> n >>a;
	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}
	int tt;
	ma.max_load_factor(0.7);
	ma.rehash(10000);
	for (int i = 0; i < a; i++){
		cin >>tt;
		arr.push_back(tt);
		ma[tt].push_back(i);
	}
	priority_queue<pii,vector<pii>> pq;	
	//start
	pq.push(make_pair(fn(arr[0],0), arr[0]));
	int miss = 1;
	//cout << mm.size() << endl;
	mm[arr[0]] = fn(arr[0],0);
	for (int i = 1; i < a; i++) {
		int cur = arr[i];
		//forgot to update when skipping the cache element!!!
		if (mm.find(cur) != mm.end()) {
			int np = fn(cur,i);
			pq.push(make_pair(np ,cur));
			mm[cur] = np;
			continue;
		}
		if (mm.size() == c) {
			pii kick = pq.top(); pq.pop();
			while(mm.find(kick.second) == mm.end()||mm[kick.second]!=kick.first) {
				kick = pq.top();
				pq.pop();
			}
			mm.erase(kick.second);
			//cout << kick.second << " " << kick.first << endl;
		} 

		int np = fn(cur,i);
	//	cout << np << endl;
		mm[cur] = np;
		pq.push(make_pair(np,cur));
		miss++;
	}
	cout << miss << endl;
}
