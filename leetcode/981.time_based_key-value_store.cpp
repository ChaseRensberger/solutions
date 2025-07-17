// Beats 95.64%
class TimeMap {
public:
  unordered_map<string, vector<pair<string, int>>> db;

  TimeMap() { db.clear(); }

  void set(string key, string value, int timestamp) {
    db[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    if (!db.count(key))
      return "";

    auto &values = db[key];
    int left = 0, right = values.size() - 1;
    string result = "";

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (values[mid].second <= timestamp) {
        result = values[mid].first;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return result;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
