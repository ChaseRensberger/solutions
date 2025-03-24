#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  string line;
  vector<int> reactorReport;
  string currValue = "";
  int ans = 0;
  while (getline(cin, line)) {
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') {
        currValue += line[i];
      } else if (!currValue.empty()) {
        reactorReport.push_back(stoi(currValue));
        currValue = "";
      }
    }
    if (!currValue.empty()) {
      reactorReport.push_back(stoi(currValue));
      currValue = "";
    }
    bool increasing = (reactorReport[1] > reactorReport[0]);
    // cout << reactorReport[0] << " ";
    for (int i = 1; i < reactorReport.size(); i++) {
      // cout << reactorReport[i] << " ";
      if (abs(reactorReport[i] - reactorReport[i - 1]) > 3 ||
          reactorReport[i] == reactorReport[i - 1] ||
          (increasing && reactorReport[i] < reactorReport[i - 1]) ||
          (!increasing && reactorReport[i] > reactorReport[i - 1])) {
        ans--;
        // cout << "NOT SAFE ";
        break;
      }
    }
    // cout << endl;
    ans++;
    reactorReport.clear();
  }

  cout << ans;
  return 0;
}
