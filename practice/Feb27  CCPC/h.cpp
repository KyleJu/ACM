#include<bits/stdtr1c++.h>
using namespace std;
typedef long long ll;
#define cv(s) atoi(s.c_str())
map<ll, string> m;

ll mp(string ip) {
	ll ips[3]; int nn = 0;
	for (int i = 0; i < ip.size(); i++){
		if (ip[i] == '.') ips[nn++] = i;
	}
	return (((ll)cv(ip.substr(0,ips[0]))) << 24) + (((ll)cv(ip.substr(ips[0] +1, ips[1]-ips[0]-1))) << 16) + (((ll)cv(ip.substr(ips[1]+1, ips[2]-ips[1]-1))) << 8) + cv(ip.substr(ips[2] +1)); 
}
int main(){
	int ts; cin>>ts;
	while(ts--) {
		m.clear();
		int ss; cin >>ss;
		string t; getline(cin,t);
		for (int i =0; i < ss; i++) {
			string s;
			getline(cin, s);
			istringstream iss{s};
    		vector<string> wrds{istream_iterator<string>{iss},istream_iterator<string>{}};
    		cerr << wrds[0] << " " << wrds[1] << " " ; 
    		m[mp(wrds[1])] = wrds[0];
    		if (wrds.size() >2){
    			cerr << wrds[2];
    			if (wrds[2] != " ") m[mp(wrds[2])] = wrds[0];
    		}
    		cerr << "\n";

		}
		int q; cin >>q;
		getline(cin,t);
		//index problems
		for (int j = 0; j < q; j++) {
			string s; getline(cin, s);
			for (int i= 0; i < s.size(); i++) {

				if (( (int) (s[i] - '0') >= 0 && (int)(s[i] - '0') < 10) || s[i] == '.') {
					int left = i;
					while(( (int)(s[i] - '0') >= 0 && (int)(s[i] - '0') < 10) || s[i] == '.') {
						i++;
					}
					i--;
					ll ke = mp(s.substr(left, i - left + 1));
					cerr << s.substr(left , i - left + 1) << " string testing **" << endl;
					
					//if (m.find(ke) != m.end()){
					if (m.find(ke) != m.end()) {
						cout << m[ke];
					} else {
						auto it = m.upper_bound(ke);
                        if (it == m.end() || it == m.begin()) {
							cout << s.substr(left, i - left + 1);
                            continue;
                        }
						string tmp = it->second;
						it--;
						string tmp2 = it->second;
						if (tmp == tmp2)
							cout << tmp;
						else
							cout << s.substr(left, i - left + 1);
					}

				} else {
					cout << s[i];
				}
			}
			cout << "\n";
		}




	}
}
