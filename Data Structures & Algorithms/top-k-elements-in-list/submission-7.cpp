class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxFreq=0;
        for (auto num : nums) {
            mp[num]++;
            if (mp[num] > maxFreq) {
                maxFreq = mp[num];
            }
        }
        vector<vector<int>> secondAcc(maxFreq + 1, vector<int>(0));

        for (auto [num, freq] : mp) {
            secondAcc[freq].push_back(num);
        }

        vector<int> res;
        for (int i = secondAcc.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < secondAcc[i].size() && res.size() < k; j++)
            {
                res.push_back(secondAcc[i][j]);
            }
        }

        return res;
    }
};
