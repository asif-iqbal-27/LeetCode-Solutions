int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();

    int m = grid[0].size();
    int cn = 0;
    bool vis[n + 1][m + 1];
    memset(vis, false, sizeof vis);
    queue<pair<int, int>> q;
    map<pair<int, int>, int> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                cn++;
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = true;
                d[{i, j}] = 0;
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
  //  dbg(cn);
    // dbg(q);
pair<int,int>end;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        //  dbg(u);
        int x = u.first, y = u.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            //   dbg(nx, ny, grid[nx][ny], vis[nx][ny]);
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1 and !vis[nx][ny])
            {
                d[{nx, ny}] = d[{x, y}] + 1;
                vis[nx][ny] = true;
                end.first=nx,end.second=ny;
                cn--;
                q.push({nx, ny});
            }
        }
    }
   // dbg(cn);
    if(cn==0){
       return d[{end.first,end.second}];
    }
    return -1;
}