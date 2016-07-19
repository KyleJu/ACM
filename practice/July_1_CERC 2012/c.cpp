#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
const int N = 50005;
short memo[N];
string arr[] = {"h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","hf","ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","rf","db","sg","bh","hs","mt","ds","rg","cn","fl","lv","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr"};

unordered_set<string> se;
short dp(const string& ss, int len) {
	if (len == ss.length()) return 1;
	if (memo[len] != -1) return memo[len];
	short res = 0;
	string sss = "";
	sss += ss[len];
	if (se.find(sss)!=se.end()) res = res | dp(ss, len+1);
	if (len != ss.length() -1) {
		sss += ss[len+1];
		if (se.find(sss) != se.end()) res = res | dp(ss, len +2);
	}
	return memo[len] = res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ts; cin >> ts;
	for(int i = 0; i < 200; i++) {
		se.insert(arr[i]);
		if (arr[i] == "lr") break;
	}
	while (ts--) {
		memset(memo, -1, sizeof memo);
		string st; cin>>st;
		short res = dp(st, 0);
	   if (res) cout << "YES" << "\n";
		else cout <<"NO" <<"\n";
	}

}
