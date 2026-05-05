class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> consec;

        for (int i = 0; i < nums.size(); i++)
        {
            consec.insert(nums[i]);
        }

        int longestSeq = 0;
        for (int num : consec)
        {
            if (consec.find(num - 1) == consec.end())
            {
                int count = 1;
                while (consec.find(num + count) != consec.end())
                {
                    count++;
                }

                longestSeq = max(count, longestSeq);
            }
        }

        return longestSeq;
    }
};