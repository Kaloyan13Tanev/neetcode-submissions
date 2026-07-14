class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp; // (timestamp, value)
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end() || it->second[0].first > timestamp) return "";

        vector<pair<int, string>>& v = it->second;
        int l = 0, r = v.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first == timestamp) return v[mid].second;
            else if (v[mid].first < timestamp) l = mid + 1;
            else r = mid - 1;
        }

        return v[r].second;
    }
};