class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> parenMap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{')
        stk.push(c);
      else if (c == ')' || c == ']' || c == '}')
        if (stk.empty())
          return false;
        else if (parenMap[stk.top()] == c)
          stk.pop();
        else
          return false;
    }

    return stk.empty();
  }
};
