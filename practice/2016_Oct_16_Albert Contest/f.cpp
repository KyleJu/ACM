#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

string s;

//int vars[30];
map<char,int> vars;
set<char> undef;

int assignments(int i, bool condition) {
	i++;
	char var = s[i];
	i++;
	int curr = 0;
	int sign = 1;
	while(s[i] != ']') {
		if(s[i] == '+') {
			sign = 1;
			i++;
		}
		if(s[i] == '-') {
			sign = -1;
			i++;
		}
		if(s[i] == '?') {
			undef.insert(var);
		}
		if(s[i] >= '0' && s[i] <= '9') {
			int num = 0;
			while(s[i] >='0' && s[i] <= '9') {
				num = num*10 + s[i]-'0';
				i++;
			}
			if(condition)
			vars[var] = vars[var] + sign*num;
		}
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			char assign = s[i];
			if(condition)
			vars[var] = vars[var] + sign*vars[assign];
		}
		i++;
	}
	i++;
	return i;
}
int conditionals(int i) {
	i++;
	char first = s[i];
	i++;
	char second = s[i];
	i+=2;

	while(s[i] != '}') {
		i = assignments(i, first < second);
	}
	i++;
	return i;
}

bool assertion(int &i) {
	i++;
	char first = s[i];
	i++;
	char second = s[i];
	i++;
	i++;
	return vars[first] ==  vars[second];
}

int main(void) {
	int T; cin >> T;
	cin >> s;
	int i=0;
	bool ans = false;
	while(i<s.size()) {
		if(s[i] == '[') {
			i=assignments(i,true);
		} else if (s[i] == '{') {
			i=conditionals(i);
		} else if (s[i] == '<') {
			ans = ans && assertion(i);
		}
	}
	cout << ans << endl;
	return 0;
}
