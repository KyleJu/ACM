#include<iostream>
#include<cmath>

using namespace std;

int main() {
	long long a, b;
	cin >> a >>b;
	if (pow ((long long)2,b +1) -1 >= a) {
		cout << "yes";
	} else {
		cout << "no";
	}

}
