#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

bool isActive(vector<pair<int, bool>> activeList, int currentMatchIndex) {
	bool isActive = true;
	for (int i = 0; i < activeList.size(); i++) {
		if (currentMatchIndex < activeList[i].first) {
			break;
		}
		isActive = activeList[i].second;
	}
	// cout << "value was marked " << isActive << endl;
	return isActive;
}

int main() {
  freopen("input.txt", "r", stdin);
  regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
  regex doPattern("do\\(\\)");
  regex dontPattern("don't\\(\\)");
  string memory;
  string memoryLine;
  while (cin >> memoryLine) {
    memory += (memoryLine + " ");
  }

  auto memoryDoBegin = sregex_iterator(memory.begin(), memory.end(), doPattern);
  auto memoryDontBegin = sregex_iterator(memory.begin(), memory.end(), dontPattern);
  auto memoryBegin = sregex_iterator(memory.begin(), memory.end(), pattern);
  auto memoryEnd = sregex_iterator();

  vector<pair<int, bool>> activeList;

  for (sregex_iterator i = memoryDoBegin; i != memoryEnd; i++) {
	  smatch match = *i;
	  activeList.push_back({match.position(), true});
  }

  for (sregex_iterator i = memoryDontBegin; i != memoryEnd; i++) {
	  smatch match = *i;
	  activeList.push_back({match.position(), false});
  }

  sort(activeList.begin(), activeList.end(), [](auto& a, auto &b) {
	  return a.first < b.first;
  });

  // for (int i = 0; i < activeList.size(); i++) {
	 //  cout << activeList[i].first << " - " << activeList[i].second << endl;
  // }
  // 20 - false
  // 59 - true

  int ans = 0;
  for (sregex_iterator i = memoryBegin; i != memoryEnd; i++) {
    smatch match = *i;
    string matchStr = match.str();
	// cout << "checking if " << valueToAdd << " is active, it exists at position " << match.position() << endl;
	if (isActive(activeList, match.position())) {
		int valueToAdd = (stoi(match[1].str()) * stoi(match[2].str()));
		ans += valueToAdd;
	}
  }
  cout << ans;
  return 0;
}
