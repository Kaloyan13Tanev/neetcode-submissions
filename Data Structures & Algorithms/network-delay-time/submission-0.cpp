class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] > d)
            {
                dist[u] = d;
                for (auto& p : adj[u])
                {
                    pq.push({p.second + d, p.first});
                }
            }
        }

        int result = INT_MIN;
        for (int i = 1; i < dist.size(); i++)
        {
            if (dist[i] == INT_MAX) return -1;

            result = max(result, dist[i]);
        }

        return result;
    }
};