class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) 
    {
        int n =grid.size();
        int m =grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        //{diff,{x,y}};
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!st.empty())
        {
            auto it=*(st.begin());
            int d=it.first;
            auto node=it.second; 

            st.erase(it);
            if (node.first==n-1 && node.second==m-1)
                return d;
            for(int i =0;i<4;i++)
            {
                int r=node.first+drow[i];
                int c=node.second+dcol[i];
                if (r>=0 &&r<n && c>=0 && c<m)
                {
                    int neweffort=max(abs(grid[r][c]-grid[node.first][node.second]),d);
                    if(neweffort<dist[r][c])
                    {   
                        dist[r][c]=neweffort;
                        st.insert({neweffort,{r,c}});
                    }
                }
            }
        }
        return 0;//unreachable
    }
};