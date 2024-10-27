#include <iostream>
using namespace std;

#define ll long long

int main() {
	ll n, rs=0, input;
	cin >> n;
	ll ns = n*(n+1)/2;

	for (int i = 0; i < n-1; i++) {
		cin >> input;	
		rs+=input;
	}
	cout << ns-rs;
		

	return 0;
}
