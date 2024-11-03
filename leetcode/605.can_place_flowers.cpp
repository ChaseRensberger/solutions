// Beats 100%
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int m = flowerbed.size();
		int ans = 0;
		if (m == 1) {
			return (flowerbed[0] == 0) ? 1 >= n : 0 >= n;
		}
		for (int i = 0; i < m; i++) {
            // First position
            if (i == 0) {
                if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                    flowerbed[0] = 1;
                    ans++;
                }
            }
            // Last position
            else if (i == m-1) {
                if (flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    ans++;
                }
            }
            // Middle positions
            else if (i > 0 && i < m-1) {
                if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    ans++;
                }
            }
        }
		return ans >= n;
    }
};
