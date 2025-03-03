class Solution {
    public:
        bool vis[303][303];
        int m, n;
        
        bool valid(int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n;
        }
    
        void dfs(vector<vector<char>>& grid, int i, int j) {
            vis[i][j] = true;
            
            // Check all four directions
            if (valid(i + 1, j) && grid[i + 1][j] == '1' && !vis[i + 1][j]) {
                dfs(grid, i + 1, j);
            }
            if (valid(i - 1, j) && grid[i - 1][j] == '1' && !vis[i - 1][j]) {
                dfs(grid, i - 1, j);
            }
            if (valid(i, j + 1) && grid[i][j + 1] == '1' && !vis[i][j + 1]) {
                dfs(grid, i, j + 1);
            }
            if (valid(i, j - 1) && grid[i][j - 1] == '1' && !vis[i][j - 1]) {
                dfs(grid, i, j - 1);
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            m = grid.size();
            n = grid[0].size();
            int cnt = 0;
            
            // Loop through all cells
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1' && !vis[i][j]) {
                        cnt++;
                        dfs(grid, i, j);
                    }
                }
            }
            return cnt;
        }
    };
    