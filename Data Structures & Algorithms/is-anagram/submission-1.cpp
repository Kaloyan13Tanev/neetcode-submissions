class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> check;

        for (int i = 0; i < s.length(); i++) 
        {
            check[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) 
        {
            if (check.find(t[i]) == check.end() || check[t[i]] == 0)
            {
                return false;
            }
            check[t[i]]--;
        }

        return true;
    }
};
