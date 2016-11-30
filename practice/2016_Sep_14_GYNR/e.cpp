#include<bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
int main() {
	int ts; cin >> ts;
	for(int i = 0; i < ts; i++) {
		int k; string ss; cin >> k >> ss;
		ll top, down;
		int j = 0;
		string tm;
		for(; j < ss.length(); j++) {
			if( ss[j] == '/') break;
			tm +=ss[j];
		}
		top = stol(tm);
		tm = "";
		for( j = j+1; j< ss.length(); j++) tm += ss[j];
		down = stol(tm);
		//cout << top << " " << down << endl;
		stack<char> st;
		while(top != 1 || down != 1) {
			if(top >down) {
				st.push('r');
				top = top - down;
			} else {
				st.push('l');
				down = down - top;
			}
		}
		unsigned long long res = 1;
		while(!st.empty()) {
			char cur = st.top(); st.pop();
			if(cur =='r') res = res*2 +1;
			else res = 2* res;
		}
		cout <<k << " " <<res << endl;

	}
}
