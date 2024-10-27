#include <iostream>
#include <string>
using namespace std;

#define ll long long

int main() {
	string s;
	cin >> s;
	char curr = 'Z';
	ll count = 1, best = 1;
	for (char c : s) {
		if (c == curr) {
			count++;
		} else {
			curr = c;
			best = max(best, count);
			count = 1;
		}
	}

	best = max(best, count);

	cout << best;
	return 0;
}
