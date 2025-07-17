class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
      while (!isalpha(s[l]) && !isdigit(s[l]) && l < r)
        l++;
      while (!isalpha(s[r]) && !isdigit(s[r]) && l < r)
        r--;

      if (tolower(s[l]) != tolower(s[r]))
        return false;

      l++;
      r--;
    }
    return true;
  }
};
