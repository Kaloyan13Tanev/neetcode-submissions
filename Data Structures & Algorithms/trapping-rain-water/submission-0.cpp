class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        int incrL = 1, incrR = height.size() - 2;
        int sum = 0;

        while (incrL < height.size())
        {
            int barsL = 0;
            while (incrL < height.size() && height[left] > height[incrL])
            {
                barsL += height[left] - height[incrL];
                incrL++;
            }

            if (incrL < height.size())
            {
                left = incrL;
                incrL++;
                sum += barsL;
            }
        }

        while (incrR > left)
        {
            int barsR = 0;
            while (incrR > left && height[right] > height[incrR])
            {
                barsR += height[right] - height[incrR];
                incrR--;
            }

            if (incrR > left)
            {
                right = incrR;
                incrR--;
                sum += barsR;
            }
        }

        for (int i = left + 1; i < right; i++)
        {
            sum += height[right] - height[i];
        }

        return sum;
    }
};