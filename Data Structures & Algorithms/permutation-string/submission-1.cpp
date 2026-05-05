class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int mp1[26] = {}, mp2[26] = {};
        for (char c : s1) mp1[c - 'a']++;

        int left = 0, right = 0;
        while (right < s2.length()) {
            char curr = s2[right];
            mp2[curr - 'a']++;

            if (mp1[curr - 'a'] == 0) {
                right++;
                left = right;
                for (int i = 0; i < 26; i++) mp2[i] = 0;
            } else if (mp2[curr - 'a'] > mp1[curr - 'a']) {
                mp2[s2[left] - 'a']--;
                left++;
                mp2[curr - 'a']--;
                right = max(left, right);
            } else {
                if (right - left + 1 == (int)s1.length()) return true;
                right++;
            }
        }
        return false;
    }
};