class Solution {
    void addToDeque(int n, deque<int>& d)
    {
        while (!d.empty() && d.front() < n)
        {
            d.pop_front();
        }
        d.push_front(n);
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        for (int i = 0; i < k; i++)
        {
            addToDeque(nums[i], d);
        }

        vector<int> result;
        result.push_back(d.back());

        int left = 1; int right = k;
        while (right < nums.size())
        {
            if (nums[left - 1] == d.back()) d.pop_back();
            addToDeque(nums[right], d);
            result.push_back(d.back());
            left++; right++;
        }

        return result;
    }
};