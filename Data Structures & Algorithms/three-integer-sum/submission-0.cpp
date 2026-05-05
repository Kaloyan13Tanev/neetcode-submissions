class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
        }

        vector<int> sortedUnique;
        for (int num : set)
        {
            sortedUnique.push_back(num);
        }
        sort(sortedUnique.begin(), sortedUnique.end());

        unordered_set<int> pastTargets;
        vector<vector<int>> res;
        for (int i = 0; i < sortedUnique.size(); i++)
        {
            if (pastTargets.find(sortedUnique[i]) == pastTargets.end())
            {
                int target = -1 * sortedUnique[i];
                pastTargets.insert(target);
                auto left = lower_bound(nums.begin(), nums.end(), sortedUnique[i]) + 1;
                auto right = nums.end() - 1;

                while (left < right)
                {
                    if (*left + *right == target)
                    {
                        res.push_back({*left, *right, sortedUnique[i]});
                        while (*left == *(left + 1) && left != nums.end() - 2) left++;
                        while (*right == *(right - 1) && right != nums.begin() + 1) right--;
                        left++; right--;
                    }
                    else if (*left + *right < target) left++;
                    else right--;
                }
            }
        }

        return res;
    }
};