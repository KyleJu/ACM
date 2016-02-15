#include<iostream>
#include<cstring>
using namespace std;
int arr[101][101];
int n;
void pro() {
	for (int i = 1; i<n; i++) {
		arr[0][i] += arr[0][i-1];
		arr[i][0] += arr[i-1][0];  
	}
	for (int i = 1; i <n; i++) {
		for (int j = 1; j <n; j++) {
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}

	// 	for (int i = 0; i <n; i++) {
	// 	for (int j = 0; j <n; j++) {
	// 		//arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
	// 		cerr << arr[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }


}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	//cerr << "run here" <<endl;
	while(t--) {
		//cerr << "d???" <<endl;
		cin>>n;
		memset(arr, 0, sizeof arr);
		for (int i =0; i < n;i ++) {
			for (int j = 0; j < n; j++) {
				cin >>arr[i][j];
			}
		}
		//cerr << "here" <<endl;
		pro();
		int sum = 0;
		//cerr << "run" << endl;
		for (int i = 0; i <n; i++){
			for (int j = 0; j <n; j++) {
				for (int x = 0; x <=i; x++){
					for (int y = 0; y <=j; y++) {
						int t =0 , l= 0, tl = 0;
						if (y >0) l = arr[i][y-1];
						if (x >0) t = arr[x-1][j];
						if (x > 0 && y > 0) tl = arr[x-1][y-1];
						sum = max(sum, arr[i][j] - l - t + tl);
					}

				}
			}
		}
		cout << sum << "\n";
	}	
}