class Solution {
    int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    bool isInside(int x, int y, int maxX, int maxY)
    {
        return x >= 0 && y >= 0 && x < maxX && y < maxY;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        stack<pair<int, int>> s;
        s.push({x, y});
        visited[x][y] = true;

        while (!s.empty())
        {
            x = s.top().first;
            y = s.top().second;
            s.pop();

            for (auto dir : dirs)
            {
                int currX = x + dir[0];
                int currY = y + dir[1];
                if (isInside(currX, currY, grid.size(), grid[0].size())
                 && grid[currX][currY] == '1' && !visited[currX][currY])
                {
                    s.push({currX, currY});
                    visited[currX][currY] = true;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),
         vector<bool>(grid[0].size(), false));

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                cout << (grid[i][j] == '1' && !visited[i][j]) << '\n';
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};
