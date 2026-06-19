public class Solution {
    public bool IsValidPos(int x, int y, int length, int width)
    {
        return x >= 0 && x < length && y >= 0 && y < width;
    }
    
    public void DFS(int x, int y, char[][] grid, bool[,] visited)
    {
        Stack<(int, int)> s = new Stack<(int, int)>();
        s.Push((x, y));
        visited[x, y] = true;

        int[][] directions = new int[][] {[1, 0], [-1, 0], [0, 1], [0, -1]};

        while(s.Count() > 0)
        {
            (int a, int b) = s.Pop();

            foreach (var dir in directions)
            {
                int a1 = a + dir[0];
                int b1 = b + dir[1];
                if (IsValidPos(a1, b1, grid.Length, grid[0].Length) &&
                 !visited[a1, b1] && grid[a1][b1] == '1')
                {
                    s.Push((a1, b1));
                    visited[a1, b1] = true;
                }
            }
        }
    }

    public int NumIslands(char[][] grid)
    {
        bool[,] visited = new bool[grid.Length, grid[0].Length];

        int count = 0;
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < grid[0].Length; j++)
            {
                if (grid[i][j] == '1' && !visited[i, j])
                {
                    count++;
                    DFS(i, j, grid, visited);
                }
            }
        }

        return count;
    }
}
