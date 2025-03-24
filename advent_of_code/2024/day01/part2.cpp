#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	vector<int> a;
	unordered_map<int, int> freq;
	int l, r, n=0;
	
	while (cin >> l >> r) {
		a.push_back(l);
		freq[r]++;
		n++;
	}

	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		ans += (a[i] * freq[a[i]]);
	}
	
	cout << ans;
	return 0;
}
