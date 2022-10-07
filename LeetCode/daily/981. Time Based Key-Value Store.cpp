class TimeMap {
  public:
    unordered_map<string, vector<pair<int, string>>> tmap;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        tmap[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = upper_bound(begin(tmap[key]), end(tmap[key]),
                              pair<int, string>(timestamp, ""),
                              [](const pair<int, string> &a,
                                 const pair<int, string> &b) {
                                  return a.first < b.first;
                              });
        return it == tmap[key].begin() ? "" : prev(it)->second;
    }
};