class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, curr = 0;
        int longestSubstr = 0;

        unordered_map<char, int> letters;
        while (start < s.length())
        {
            while (curr < s.length() && 
            (letters.find(s[curr]) == letters.end() || letters[s[curr]] < start))
            {
                letters[s[curr]] = curr;
                curr++;
            }

            longestSubstr = max(longestSubstr, curr - start);
            if (curr == s.length()) break;
            start = letters[s[curr]] + 1;
        }

        return longestSubstr;
    }
};