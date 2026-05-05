class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        int grV = 0;
        while (left < right)
        {
            int V = min(height[left], height[right]) * (right - left);
            grV = max(grV, V);

            if (height[left] > height[right])
            {
                right--;
            }
            else if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                height[left + 1] > height[right - 1] ? left++ : right--;
            }
        }

        return grV;
    }
};