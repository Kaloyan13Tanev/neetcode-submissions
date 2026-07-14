class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end() ||
        mp[key][0].second > timestamp) return "";

        vector<pair<string, int>>& v = mp[key];
        int l = 0; int r = v.size() - 1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if (v[mid].second == timestamp) return v[mid].first;
            else if (v[mid].second < timestamp)
            { l = mid + 1; }
            else 
            { r = mid - 1; }
        }

        return v[r].first;
    }
};
