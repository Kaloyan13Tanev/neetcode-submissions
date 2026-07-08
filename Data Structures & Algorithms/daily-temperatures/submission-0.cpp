class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> monoSt;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!monoSt.empty() && monoSt.top().first < temperatures[i])
            {
                result[monoSt.top().second] = i - monoSt.top().second;
                monoSt.pop();
            }

            monoSt.push({temperatures[i], i});
        }

        while (!monoSt.empty())
        {
            result[monoSt.top().second] = 0;
            monoSt.pop();
        }

        return result;
    }
};
