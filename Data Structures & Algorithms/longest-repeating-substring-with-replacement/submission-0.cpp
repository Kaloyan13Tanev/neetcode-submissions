class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;
        int letters[26] = {};  // ✅ replaces unordered_map
        letters[s[0] - 'A'] = 1;

        int maxFreq = 0;
        int longestSeq = 0;
        while (end < s.length()) {
            maxFreq = max(maxFreq, letters[s[end] - 'A']);

            int windowLen = end - start + 1;
            if (windowLen - maxFreq <= k) {
                longestSeq = max(longestSeq, windowLen);
                end++;
                if (end < s.length()) letters[s[end] - 'A']++;
            } else {
                letters[s[start] - 'A']--;
                start++;
            }
        }
        return longestSeq;
    }
};