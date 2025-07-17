class Solution {
public:
  string foreignDictionary(vector<string> &words) {

    int n = words.size();
    vector < vector<char> rules(n);

    for (int i = 0; i < n; i++) {
    }
  }

  string topologicalSort(vector<vector<char>> graph) {
    string ans = "";
    int n = graph.size();
    unordered_map<char, int> indegrees(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        indegrees[graph[i][j]]++;
      }
    }

    for (pair<char, int> p : indegrees) {
      if (p.second == 0) {
        ans += p.first;
      }
    }
  }
};
