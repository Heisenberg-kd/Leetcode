class Solution {
public:
    void bfs(vector<vector<char>>&grid,int i , int j , vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for (int delcol=-1;delcol<=1;delcol++)
                {
                     if ((delcol!=delrow && delcol!=-delrow) or delcol==0)
                        {
                            int nrow=i+delrow;
                            int ncol=j+delcol;
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && grid[nrow][ncol]=='1' &&!vis[nrow][ncol])
                            {
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        //BFS
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
        
    }
};