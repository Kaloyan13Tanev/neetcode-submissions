class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (int i = 0; i < strs.size(); i++)
        {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            res[curr].push_back(strs[i]);
        }

        vector<vector<string>> toReturn;
        for (auto it = res.begin(); it != res.end(); it++)
        {
            toReturn.push_back(it->second);
        }

        return toReturn;
    }
};