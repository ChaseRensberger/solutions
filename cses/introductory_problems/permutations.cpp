#include <iostream>
using namespace std;

#define ll long long

int main() {
	ll n;
	cin >> n;

	if (n==1) {
		cout << 1;
		return 0;
	} else if (n==2||n==3) {
		cout << "NO SOLUTION";
		return 0;
	}

	for (int i=2;i<=n;i+=2){
		cout << i << " ";
	}

	for (int i=1;i<=n;i+=2){
		cout << i << " ";
	}

	return 0;
}
