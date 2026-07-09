class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> comb(position.size());
        for (int i = 0; i < position.size(); i++)
        {
            comb[i] = {position[i], speed[i]};
        }

        sort(comb.begin(), comb.end());

        stack<double> st;
        st.push((double)(target - comb[0].first) / comb[0].second);

        for (int i = 1; i < comb.size(); i++)
        {
            double arrTime = (double)(target - comb[i].first) / comb[i].second;
            cout << arrTime;
            while (!st.empty() && st.top() <= arrTime)
            {
                st.pop();
            }
            st.push(arrTime);
        }

        return st.size();
    }
};
