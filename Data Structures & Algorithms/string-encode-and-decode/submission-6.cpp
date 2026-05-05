class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "" + to_string(strs.size()) + "";
        for (int i = 0; i < strs.size(); i++)
        {
            res += " " + to_string(strs[i].length()) + " " + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res(0);
        int pos = s.find(" ") + 1;
        int count = stoi(s.substr(0, pos - 1));

        for (int i = 0; i < count; i++)
        {
            int shift = s.find(" ", pos);
            int currLen = stoi(s.substr(pos, shift - pos));

            pos = shift + 1;
            res.push_back(s.substr(pos, currLen));

            pos += currLen + 1;
        }

        return res;
    }
};
