class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (char c : s)
        {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                t += tolower(c);
            }
        }

        for (int i = 0; i < t.length() / 2; i++)
        {
            if (t[i] != t[t.length() - i - 1]) return false;
        }

        return true;
    }
};