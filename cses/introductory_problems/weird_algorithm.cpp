#include <iostream>
using namespace std;

#define ll long long


int main() {
	ll x;
	cin >> x;
	cout << x << " ";
	while (x != 1) {
		if (x % 2) {
			x = x*3+1;
			cout << x << " ";
		} else {
			x /= 2;
			cout << x << " ";
		}
	}

	return 0;
}
