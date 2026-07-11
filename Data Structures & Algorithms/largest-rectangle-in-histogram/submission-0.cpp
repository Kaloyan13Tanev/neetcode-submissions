class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monoSt;
        int result = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!monoSt.empty() && heights[monoSt.top()] >= heights[i]) {
                int index = monoSt.top();
                monoSt.pop();
                int prev = monoSt.empty() ? -1 : monoSt.top();
                int area = heights[index] * (i - prev - 1);
                result = max(result, area);
            }
            monoSt.push(i);
        }

        while (!monoSt.empty()) {
            int index = monoSt.top();
            monoSt.pop();
            int prev = monoSt.empty() ? -1 : monoSt.top();
            int area = heights[index] * (n - prev - 1);
            result = max(result, area);
        }

        return result;
    }
};