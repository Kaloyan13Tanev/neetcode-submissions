class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int mid = (r - l) / 2 + l;
        cout << mid;
        while (l <= r)
        {
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else r = mid - 1;

            mid = (r - l) / 2 + l;
            cout << mid;
        }

        return -1;
    }
};
