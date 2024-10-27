#include <iostream>
using namespace std;

#define ll long long

int main() {
	ll n, curr, count=0, prev;
	cin >> n;
	cin >> prev;
	for (ll i = 1; i < n; i++) {
		cin >> curr;
		if (curr < prev) {
			count += prev - curr;

		} else {
			prev = curr;
		}
	}
	cout << count;
	return 0;
}
