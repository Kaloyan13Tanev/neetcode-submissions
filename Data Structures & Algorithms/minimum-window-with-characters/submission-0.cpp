class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        int need[128] = {}, have[128] = {};
        int needCount = 0;
        for (char c : t) {
            if (need[c] == 0) needCount++;
            need[c]++;
        }

        int haveCount = 0;
        int start = 0, len = INT_MAX;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            have[c]++;
            if (need[c] > 0 && have[c] == need[c]) haveCount++;

            while (haveCount == needCount) {
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }
                have[s[left]]--;
                if (need[s[left]] > 0 && have[s[left]] < need[s[left]]) haveCount--;
                left++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};