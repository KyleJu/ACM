#include<iostream>
#include<stack>

using namespace std;
const int MAX = 5e5 + 10;
int n,m,p;
char s[MAX], op[MAX];
int l[MAX], r[MAX], po[MAX];
stack<int> st;


int main(){
	scanf("%d%d%d", &n,&m,&p);
	scanf("%s%s",s,op);
	for (int i = 1; i <=n; i++){
		if (s[i-1] == '(') st.push(i);
		else {
			po[st.top()] = i;
			po[i] = st.top();
			st.pop();
		}
	}
	for(int i = 0; i <=n; i ++){
		l[i] = i - 1;
		r[i] = i+1;
	}
	for(int i = 0; i <m;i++){
		if(op[i] == 'R') p = r[p];
		else if(op[i] == 'L') p= l[p];
		else {
			if (p>po[p]) p = po[p];
			int ll = l[p], rr = r[po[p]];
			r [ll] =rr;
			l[rr] = ll;
			p = rr;
			if (p==n+1) p =ll;
		}
	}

	for(int i =r[0]; i <=n; i =r[i]){
		printf("%c", s[i-1]);
	}

}

