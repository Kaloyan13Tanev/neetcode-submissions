class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses);
        vector<vector<int>> connections(numCourses);
        queue<int> free;

        for (auto vec : prerequisites)
        {
            degree[vec[0]]++;
            connections[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0) free.push(i);
        }

        while (!free.empty())
        {
            int curr = free.front();
            free.pop();

            numCourses--;
            for (auto conn : connections[curr])
            {
                degree[conn]--;
                if (degree[conn] == 0) free.push(conn);
            }
        }

        return (numCourses == 0);
    }
};