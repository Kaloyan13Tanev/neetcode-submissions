class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (auto it = nums.begin(); it < nums.end(); ++it)
        {
            if (*it > 0) break;
            if (it > nums.begin() && *it == *(it - 1)) continue;

            auto left = it + 1;
            auto right = nums.end() - 1;

            while (left < right)
            {
                int sum = *left + *right;

                if (sum < -*it) ++left;
                else if (sum > -*it) --right;
                else
                {
                    result.push_back({*it, *left, *right});

                    while (left < right && *left == *(left + 1)) ++left;
                    while (left < right && *right == *(right - 1)) --right;

                    ++left;
                    --right;
                }
            }
        }

        return result;
    }
};