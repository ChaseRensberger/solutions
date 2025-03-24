#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
  string memory;
  string memoryLine;
  while (cin >> memoryLine) {
    memory += (memoryLine + " ");
  }

  auto memoryBegin = sregex_iterator(memory.begin(), memory.end(), pattern);
  auto memoryEnd = sregex_iterator();

  int ans = 0;
  for (sregex_iterator i = memoryBegin; i != memoryEnd; i++) {
    smatch match = *i;
    string matchStr = match.str();
    ans += (stoi(match[1].str()) * stoi(match[2].str()));
  }

  cout << ans;

  return 0;
}
