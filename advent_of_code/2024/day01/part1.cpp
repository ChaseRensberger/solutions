#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	vector<int> a, b;
	int l, r, n=0;
	
	while (cin >> l >> r) {
		a.push_back(l);
		b.push_back(r);
		n++;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - b[i]);
	}
	
	cout << ans;
	return 0;
}
