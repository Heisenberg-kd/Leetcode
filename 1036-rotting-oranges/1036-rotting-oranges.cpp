class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n =grid.size();
        int m=grid[0].size();
        int vis[n][m];
        //{{r,c},t}
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }        
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int max_time=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            max_time=max(t,max_time);
            q.pop();
            for(int i =0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return max_time;
    }
};