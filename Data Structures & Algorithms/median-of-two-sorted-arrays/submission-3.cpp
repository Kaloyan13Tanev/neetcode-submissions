class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int before = totalSize / 2;
        vector<int>& shorter = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& longer  = nums1.size() < nums2.size() ? nums2 : nums1;
        
        int m = shorter.size(), n = longer.size();
        int l = 0, r = m - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int target = before - mid;
            
            if (target < 0) { r = mid - 1; continue; }
            if (target > n) { l = mid + 1; continue; }
            
            bool leftOK  = (target == 0) || longer[target - 1] <= shorter[mid];
            bool rightOK = (target == n) || longer[target] >= shorter[mid];
            
            if (leftOK && rightOK) {
                if (totalSize % 2 == 1) return shorter[mid];
                int leftMax;
                if (mid == 0) leftMax = longer[target - 1];
                else if (target == 0) leftMax = shorter[mid - 1];
                else leftMax = max(shorter[mid - 1], longer[target - 1]);
                return (leftMax + shorter[mid]) / 2.0;
            }
            else if (!leftOK) l = mid + 1;
            else r = mid - 1;
        }
        
        // Median not in shorter — read the answer from partition state
        int shorterOnLeft = l;
        int longerOnLeft = before - shorterOnLeft;
        
        int rightVal;
        if (shorterOnLeft == m) rightVal = longer[longerOnLeft];
        else if (longerOnLeft == n) rightVal = shorter[shorterOnLeft];
        else rightVal = min(shorter[shorterOnLeft], longer[longerOnLeft]);
        
        if (totalSize % 2 == 1) return rightVal;
        
        int leftVal;
        if (shorterOnLeft == 0) leftVal = longer[longerOnLeft - 1];
        else if (longerOnLeft == 0) leftVal = shorter[shorterOnLeft - 1];
        else leftVal = max(shorter[shorterOnLeft - 1], longer[longerOnLeft - 1]);
        
        return (leftVal + rightVal) / 2.0;
    }
};