class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> incomingEdges(numCourses, 0);
    vector<vector<int>> graph(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) {
      vector<int> current_prerequisite = prerequisites[i];
      incomingEdges[current_prerequisite[0]]++;
      graph[current_prerequisite[1]].push_back(current_prerequisite[0]);
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (incomingEdges[i] == 0)
        q.push(i);
    }

    int completed = 0;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      completed++;

      for (int dependent : graph[course]) {
        incomingEdges[dependent]--;
        if (incomingEdges[dependent] == 0) {
          q.push(dependent);
        }
      }
    }

    return completed == numCourses;
  }
};
