class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> acc(20000);

        for (int i = 0; i < nums.size(); i++)
        {
            acc[nums[i] + 10000]++;
        }

        vector<vector<int>> secondAcc(acc.size());
        for (int i = 0; i < acc.size(); i++)
        {
            secondAcc[acc[i]].push_back(i - 10000);
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