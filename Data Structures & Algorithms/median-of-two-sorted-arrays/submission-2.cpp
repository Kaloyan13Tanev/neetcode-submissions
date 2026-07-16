class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int target = ceil((double)totalSize / 2) - 1;

        int mid = 0, spot = -1;
        int l = 0, r = (int)nums1.size() - 1;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            spot = mid + (lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin());

            if (spot == target) break;
            else if (spot < target) l = mid + 1;
            else r = mid - 1;
        }

        if (spot == target)
        {
            if (totalSize % 2 == 0)
            {
                int lb = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                int nextVal;
                bool hasNext1 = mid + 1 < (int)nums1.size();
                bool hasNext2 = lb < (int)nums2.size();

                if (hasNext1 && hasNext2) nextVal = min(nums1[mid + 1], nums2[lb]);
                else if (hasNext1) nextVal = nums1[mid + 1];
                else nextVal = nums2[lb];

                return (double)(nums1[mid] + nextVal) / 2;
            }
            return nums1[mid];
        }

        l = 0; r = (int)nums2.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            spot = mid + (upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin());

            if (spot == target) break;
            else if (spot < target) l = mid + 1;
            else r = mid - 1;
        }

        if (totalSize % 2 == 0)
        {
            int ub = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
            int nextVal;
            bool hasNext1 = ub < (int)nums1.size();
            bool hasNext2 = mid + 1 < (int)nums2.size();

            if (hasNext1 && hasNext2) nextVal = min(nums1[ub], nums2[mid + 1]);
            else if (hasNext1) nextVal = nums1[ub];
            else nextVal = nums2[mid + 1];

            return (double)(nums2[mid] + nextVal) / 2;
        }

        return nums2[mid];
    }
};