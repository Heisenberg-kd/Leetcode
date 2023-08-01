class Solution {
public:
    void dfs(int node, vector<int> adj[], int vis[])
    {
        vis[node]=1;
        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //Applying DFS
        int vis[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
        }
        int count=0;
        for(int i =0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
        
    }
};