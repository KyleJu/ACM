#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
pii arr[3];

bool check(int a, int b, int c) {
    return min(a,b) >= c || max(a,b) <= c;
}
int main() {
	int x1, y1;
	for (int i = 0; i < 3; i++) {
			cin >> x1 >> y1;
			arr[i] = make_pair(x1,y1);
	}

	if ((arr[0].first == arr[1].first && arr[1].first == arr[2].first) || (arr[0].second == arr[1].second && arr[1].second == arr[2].second)) {
		cout << "1\n";
		return 0;
	} 
	sort(arr, arr+3);
	bool is2= false;
	do {
		if ((arr[0].first == arr[1].first && check(arr[0].second, arr[1].second,arr[2].second)) || (arr[0].second == arr[1].second && check(arr[0].first, arr[1].first,arr[2].first))){
			is2 = true;
		}
	} while(next_permutation(arr, arr +3));
	if (is2) cout <<"2\n";
	else cout <<"3\n";

}