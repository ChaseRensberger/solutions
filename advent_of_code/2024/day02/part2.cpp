#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(vector<int> reactorReport) {
  bool increasing = (reactorReport[1] > reactorReport[0]);
  for (int i = 1; i < reactorReport.size(); i++) {
    if (abs(reactorReport[i] - reactorReport[i - 1]) > 3 ||
        reactorReport[i] == reactorReport[i - 1] ||
        (increasing && reactorReport[i] < reactorReport[i - 1]) ||
        (!increasing && reactorReport[i] > reactorReport[i - 1])) {
      return false;
    }
  }
  return true;
}

bool isSafeWithProblemDampener(vector<int> reactorReport) {
  if (isSafe(reactorReport)) {
    return true;
  }
  for (int i = 0; i < reactorReport.size(); i++) {
    vector<int> reactorReportCopy(reactorReport.begin(), reactorReport.end());
    reactorReportCopy.erase(reactorReportCopy.begin() + i);
    if (isSafe(reactorReportCopy)) {
      return true;
    }
  }

  return false;
}

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
    if (isSafeWithProblemDampener(reactorReport)) {
      ans++;
    }
    reactorReport.clear();
  }

  cout << ans;
  return 0;
}
