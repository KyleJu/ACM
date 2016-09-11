#include<iostream>
#include<cstring>
using namespace std;
int mat[11][11];
int main(){
	memset(mat, 0, sizeof mat);
	int r,c,n,k;
	cin >> r >>c >> n>> k;
	for(int i = 0; i < n; i++) {
		int x,y; cin >>x >>y;
		mat[x-1][y-1] = 1;
	}
	for (int i = 1; i < r;i++) {
		mat[i][0] +=mat[i-1][0]; 
	}
	for(int i = 1; i < c; i++) {
		mat[0][i] += mat[0][i-1];
	}
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			//cout << mat[i][j] <<"\n";
			mat[i][j] = mat[i][j] +mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
		}
	}
	int res  =0;
	for (int i = 0; i <r; i++){
			for (int j = 0; j <c; j++) {
				for (int x = 0; x <=i; x++){
					for (int y = 0; y <=j; y++) {
						int t =0 , l= 0, tl = 0;
						if (y >0) l = mat[i][y-1];
						if (x >0) t = mat[x-1][j];
						if (x > 0 && y > 0) tl = mat[x-1][y-1];
						//cout << mat[i][j] - l - t + tl<<"\n";
						if (mat[i][j] - l - t + tl >=k) res++;
					}

				}
			}
		}

		cout << res << "\n";
}