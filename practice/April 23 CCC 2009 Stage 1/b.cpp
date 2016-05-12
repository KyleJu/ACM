#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
	int r ,npl; cin >> r >> npl;
	vector<int> nums;
	for(int i =0; i < r; i++){
		int num = 0;
		for(int j = npl-1; j >=0; j--){
			int tm; cin>> tm;
			num = (num | tm << j);
			//cout << num << " ";
		}
		//cout << num << " ";
		nums.push_back(num);
	}
	vector<int>res;
	if (r == 1){
		cout << 1;
		return 0;
	}
	res.push_back(nums[0]);
	for(int i = 1; i < r;i++){
		res.push_back(nums[i]);
		for(int j =0; j < res.size()-1; j++){
			res[j] = res[j]^nums[i];
		//	cout << res[j] << " " << j << " " << r << endl;
		}
	}
	unordered_set<int> rr;
	for(auto tm: res) rr.insert(tm);
	cout << rr.size();
}
