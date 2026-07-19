class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0, r = m;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int leftA  = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightA = (i == m) ? INT_MAX : nums1[i];
            int leftB  = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 1) return max(leftA, leftB);
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            else if (leftA > rightB) r = i - 1;
            else l = i + 1;
        }
        return 0.0;
    }
};