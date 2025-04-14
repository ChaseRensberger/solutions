// Beats 100%
class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> m = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
    stack<char> stk;
    for (char c : s) {
      if (c == ']' || c == '}' || c == ')') {
        if (stk.size() < 1 || m[stk.top()] != c) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    return stk.size() < 1;
  }
};
