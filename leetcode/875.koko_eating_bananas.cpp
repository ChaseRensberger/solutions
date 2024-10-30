// Beast 97%
class Solution {
public:
	long long howLongToEatAllPiles(vector<int>& piles, int speed) {
		long long result = 0;
		for (int pile : piles) {
			result += (pile + speed - 1) / speed;
		}
		return result;
	}
    int minEatingSpeed(vector<int>& piles, int h) {

		int maxPile = -1;
		for (int pile : piles) {
			maxPile = max(maxPile, pile);
		}
		int l = 1, r = maxPile, mid;

		while (l <= r) {
			mid = l+(r-l)/2;
			if (howLongToEatAllPiles(piles, mid) <= h) {
				r = mid-1;
			} else {
				l = mid+1;
			}
		}

		return l;
    }
};
