#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
int arr[100005];
int memo[100005];

const int& INF = numeric_limits<int>::max();

int dp(int n) {
	//check base case ????
	//not possible to return n <-1 !!!
	//cout << n << endl;
	if (n <= -1) return 0;
	if (memo[n] != -1) return memo[n];
	int res = INF;
	int left = 3;
	int add = 0;
	for (int i = 0; i < 3; i++) {
		///check if 0
		if (n -i -1 == -1) {
			return add + left;
		}

		int di = arr[n - i] - arr[n - 1 -i];
		if ( di <=10 && di >0) {
			left--;
			if (left ==0){ 
				res = min(res, add + dp(n-i-2));
				break;
			}
			continue;
		}
			//either start or add
			// add
		int nee = (di - 1)/10;
		//cerr << nee << " need " << n << endl;
		if (nee >= left || di <=0) {
			//start a new one
			//cerr<< "at  first here " << left << " "<< n << endl;
			res = min(res, add + left + dp(n-i -1));
			break;
		} else {
			res = min(res, add +left + dp(n-i - 1));
			add +=nee;
			//res = min(res, res + 1 + nee);
			left -= (nee +1); 
			//cerr<< "at  second here " <<  add << " "<< n << endl;	
		}

		if (left ==0){ 
			res = min(res, add + dp(n-i-2));
			break;
		}
	}

	return memo[n] = res;

}
int main () {
	int t; cin >> t;
	for (int ts =1; ts <=t; ts++) {
		int n; cin >> n;
		for(int i = 0; i < n;i ++) {
			cin >> arr[i];
		}
		memset(memo, -1, sizeof memo);
		int res = dp(n-1);

		cout << "Case #" << ts << ": " << res << "\n";
	}

	return 0;
}