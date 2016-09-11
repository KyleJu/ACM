#include<iostream>
#include<vector>
#include<cstring>
#include<bitset>

using namespace std;
#define ll long long

vector<int> ro;
ll memo[8][1<<21];
int arr[10];
int limit;

ll dp (int n, int bm) {
	if (n == 0) return 1;
	if (memo[n][bm]!= -1) return memo[n][bm];
	int get = 7;
	ll res = 0;
	for (auto v: ro) {
		bool isv = true;
		bool temp = false;
		// none of cells can be 0
		for (int i = 0; i < arr[n]; i++) {
			int ch = ((v >> (3*i)) & get);
			if ( ch== 0 || ch > limit) {temp =true; break;} 
		}
		if (temp) continue;
		if ((v >> (3*arr[n])) != 0) continue;
		for (int i = 0; i < arr[n +1]; i++) {
			int a = ((v >>(3*i)) & get);
			int b = ((bm >> (3*i)) & get);
			// b is bigger than limit
			if ( a > b) {
			 		isv = false;
			 		break;
			 	}
		}
		if (isv) {
			//cout << v  << " " << bitset<9>(v) << " " << n << endl;
			res += dp(n-1,v);
		}
	}
	return memo[n][bm] = res;
}
void conf() {
ro.push_back(1);
ro.push_back(2);
ro.push_back(3);
ro.push_back(4);
ro.push_back(5);
ro.push_back(6);
ro.push_back(7);
ro.push_back(17);
ro.push_back(25);
ro.push_back(26);
ro.push_back(33);
ro.push_back(34);
ro.push_back(35);
ro.push_back(41);
ro.push_back(42);
ro.push_back(43);
ro.push_back(44);
ro.push_back(49);
ro.push_back(50);
ro.push_back(51);
ro.push_back(52);
ro.push_back(53);
ro.push_back(57);
ro.push_back(58);
ro.push_back(59);
ro.push_back(60);
ro.push_back(61);
ro.push_back(62);
ro.push_back(209);
ro.push_back(273);
ro.push_back(281);
ro.push_back(282);
ro.push_back(337);
ro.push_back(345);
ro.push_back(346);
ro.push_back(353);
ro.push_back(354);
ro.push_back(355);
ro.push_back(401);
ro.push_back(409);
ro.push_back(410);
ro.push_back(417);
ro.push_back(418);
ro.push_back(419);
ro.push_back(425);
ro.push_back(426);
ro.push_back(427);
ro.push_back(428);
ro.push_back(465);
ro.push_back(473);
ro.push_back(474);
ro.push_back(481);
ro.push_back(482);
ro.push_back(483);
ro.push_back(489);
ro.push_back(490);
ro.push_back(491);
ro.push_back(492);
ro.push_back(497);
ro.push_back(498);
ro.push_back(499);
ro.push_back(500);
ro.push_back(501);
ro.push_back(2257);
ro.push_back(2769);
ro.push_back(2833);
ro.push_back(2841);
ro.push_back(2842);
ro.push_back(3281);
ro.push_back(3345);
ro.push_back(3353);
ro.push_back(3354);
ro.push_back(3409);
ro.push_back(3417);
ro.push_back(3418);
ro.push_back(3425);
ro.push_back(3426);
ro.push_back(3427);
ro.push_back(3793);
ro.push_back(3857);
ro.push_back(3865);
ro.push_back(3866);
ro.push_back(3921);
ro.push_back(3929);
ro.push_back(3930);
ro.push_back(3937);
ro.push_back(3938);
ro.push_back(3939);
ro.push_back(3985);
ro.push_back(3993);
ro.push_back(3994);
ro.push_back(4001);
ro.push_back(4002);
ro.push_back(4003);
ro.push_back(4009);
ro.push_back(4010);
ro.push_back(4011);
ro.push_back(4012);
ro.push_back(22737);
ro.push_back(26833);
ro.push_back(27345);
ro.push_back(27409);
ro.push_back(27417);
ro.push_back(27418);
ro.push_back(30929);
ro.push_back(31441);
ro.push_back(31505);
ro.push_back(31513);
ro.push_back(31514);
ro.push_back(31953);
ro.push_back(32017);
ro.push_back(32025);
ro.push_back(32026);
ro.push_back(32081);
ro.push_back(32089);
ro.push_back(32090);
ro.push_back(32097);
ro.push_back(32098);
ro.push_back(32099);
ro.push_back(219345);
ro.push_back(252113);
ro.push_back(256209);
ro.push_back(256721);
ro.push_back(256785);
ro.push_back(256793);
ro.push_back(256794);
ro.push_back(2054353);
}

int main() {
	int k;
	conf();
	while (cin >> k) {
		memset(arr, 0, sizeof arr);
		int co = 0;
		for (int i = 0; i <k; i++) {
			int rown; cin >> rown;
			if (i ==0) co = rown;
			for (int x = 1; x <=rown; x++) {
				arr[x]++;
			}
		}

		// for (int i = 0 ; i<= co; i++) {
		// 	cerr << arr[i] << " ";
		// }
		memset(memo, -1, sizeof memo);

		cin >> limit;

		// for starting
		arr[co+1] = arr[co];
		int sp = (1 << 21) -1;
		//cout << arr[k] << " arr[k] is " << sp <<  " " << endl;
		ll res = dp(co, sp);
		cout << res << "\n";

	}
	return 0;
}
