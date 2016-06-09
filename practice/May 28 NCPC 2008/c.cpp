#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<string, vector<string>> pss;
vector<pss> arr;
vector<vector<int>> arr1;
unordered_map<string, int> ma;
int memo[10005][10005];
string pro(string ss) {
	if (ss == "") return "";
	int left = ss.length();
	string res = "";
	bool psp = false;
	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] == ' ' || ss[i] == '\n') {
		 	if (left == ss.length() || ss[i] =='\n') continue;
			psp = true;
		} else {
			left = min(left, i);
			if (psp) res += " ";
			res += ss[i];
			psp = false;
		}
	}
	return res;
}



int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	int n; cin >>n;
	string nm;
	vector<string> ls;
	string tm;
	string ran;
	ma.max_load_factor(0.8);
	ma.rehash(1000);
	for (int i = 0 ; i <= n; i++) {
		if (i !=n) {
			cin >> nm;
			getline(cin, ran);
		}
		while(true) {
			getline(cin,tm);
			if (tm == "***END***") {
				arr.push_back(make_pair(nm, ls));
				ls.clear();
				break;
			} else {
				string r = pro(tm);
				if (r != "") {
					ls.push_back(r);
				}
			}
		}
	}
	pss snp = arr[n];
	vector<int> ori;
	ls = snp.second;
	for (int i = 0; i <ls.size(); i++) {
		ma[ls[i]]  = i;
	}
	for (int i = 0; i < ls.size(); i++) {
		ori.push_back(ma[ls[i]]);
	}
	vector<int> tmm;
	for (int i =0 ; i < n; i++) {
		ls = arr[i].second;
		tmm.clear();
		for (int j = 0; j < ls.size(); j++) {
			if (ma.find(ls[j]) == ma.end()) {
				tmm.push_back(-100);
			} else {
				//cout << " find  " << ls[j] << " " << ma[ls[j]] <<endl;
				tmm.push_back(ma[ls[j]]);
			}
		}
		arr1.push_back(tmm);
	}
	vector<int> li;
	int maxx = 0;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		li = arr1[i];
		int lmax = 0;
		memset(memo, 0, sizeof memo);
		for (int j = 0; j <li.size(); j++) {
			for(int z = 0; z < ori.size(); z++) {
				if (li[j] == -100 || ori[z] == -100) continue;
				if (j==0 || z ==0) {
					memo[j][z] = ((li[j] == ori[z])? 1 :0);
				} else {
					if( li[j] == ori[z]) memo[j][z] = memo[j-1][z-1] + 1;
				}
				//cout << j << " "  << z << " " << memo[j][z] << "\n";
				lmax = max(lmax, memo[j][z]);
			}
		}

		/*
		for (int i=0;i<n;i++){
        //compare ccode to cfiles[i]
        int match=0; 
        int x=cfiles[i].size();
        int y=ccode.size();
        for (int st=-x;st<y;st++){   ->> basically test all types of alignments !!! smart
            int most=0,curr=0; 
            for (int j=0;j<x;j++){
                //cout<<st<<' '<<j<<endl;
                if ((st+j>=0)&&(st+j<y)){
                    if (cfiles[i][j]==ccode[st+j]) curr++;
                    else{
                        most=max(most,curr); curr=0;
                    }
                }
            }
            most=max(most,curr);
            match=max(match,most);
        }

		*/

		if (maxx < lmax) {
		 res.clear();
		 res.push_back(i);
		} else if (maxx == lmax) {
			res.push_back(i);
		}
		maxx = max(maxx, lmax);
	}
	cout << maxx;
	if(maxx != 0) {
		for (auto ii: res) {
			cout << " " << arr[ii].first;
		}
	}
	cout << "\n";
}
