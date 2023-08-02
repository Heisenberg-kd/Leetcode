class Solution {
public:
    void bfs(vector<vector<int>>&image,int i , int j,vector<vector<int>>&vis,int color)
    {
        queue <pair<int,int>>q;
        q.push({i,j});
        int n=image.size();
        int m=image[0].size();
        int color_intial=image[i][j];
        while(!q.empty())
        {
            int i =  q.front().first;
            int j=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++ )
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    if ((delcol!=delrow && delcol!=-delrow) or delcol==0)
                    {
                        int row=delrow+i;
                        int col=delcol+j;
                        if(row>=0 && row<n && col>=0 && col < m && !vis[row][col] && image[row][col]==color_intial)
                        {
                            vis[row][col]=1;
                            image[row][col]=color;
                            q.push({row,col});
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        //bfs without for loop to include all components.
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(image, sr,sc,vis, color);
        return image;
    }
};