class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) 
    {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        vector<int> ans(n,0);
        for(auto i :edges)
        {
            mat[i[0]][i[1]]=i[2];
            mat[i[1]][i[0]]=i[2];
        }

        for (int i =0;i<n;i++)
        {
            mat[i][i]=0;
        }

        for(int k=0;k<n;k++)
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int cnt=n;
        int no=-1;
        for (int i =0;i<n;i++)
        {
            
            for(int j =0;j<n;j++)
            {
                if (mat[i][j]<=dt)
                    ans[i]++;
            }
            if(ans[i]<=cnt)
            {
                cnt=ans[i];
                no=i;
            }
        }
        return no;
        
        
    }
};