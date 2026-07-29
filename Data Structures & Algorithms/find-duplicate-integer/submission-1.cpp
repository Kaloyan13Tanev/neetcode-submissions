class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> nodes;

        int i = 0;
        while (true)
        {
            if (nodes.count(i)) return i;
            
            nodes[i] = nums[i];
            i = nums[i];
        }

        return -1;
    }
};
