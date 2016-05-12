#include <bits/stdtr1c++.h>
using namespace std;
typedef long long ll;
struct data{
	ll start;
	ll popu;
	ll pq;
};



bool cmp (const data& a, const data & b) {
	if (a.start == b.start) {
		return a.pq > b.pq;
	} 
	return a.start < b.start;
}
vector<data> arr;
int main() {
	int m;
	while (cin >>m){
		arr.clear();
		ll tn; cin >>tn;
		for (int i =0; i <m; i++) {
			ll a,b,c; cin >> a>>b>>c;
			data d1,d2;
			d1.start = b;
			d2.start = c;
			d1.popu = d2.popu = a;
			d1.pq = 0;
			d2.pq = 1;
			arr.push_back(d1);
			arr.push_back(d2);
		}
	ll res = 0;
	ll sum = -10000000;
	ll pop = 0;
	ll curp = 0;
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++){
		ll s = arr[i].start;
		ll pass = 0;
		while(arr[i].start == s) {
			if (arr[i].pq == 0){
				//cout << arr[i].start << " " << pop << " " << endl;
				pop +=arr[i].popu;
				curp =pop * (s-tn); 
			} else{
				//cout << arr[i].start << " " << pop << " " << endl;
				pass += arr[i].popu;
				curp = pop*(s-tn);

			}
			if (curp >= sum) {
				res = arr[i].start;
				sum = curp;
			}
			pop -=pass;
			i++;
		}

		i--;
	}

	cout << res <<endl;
}
}
