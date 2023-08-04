class Solution {
public:
    bool dfs(vector<vector<int>>&graph , vector<int>&vis, vector<int>&pathvis,int node,vector<int>&oncycle)
    {
        vis[node]=1;
        pathvis[node]=1;
        oncycle[node]=1;
        for(int num:graph[node])
        {
            if(!vis[num])
            {
                if (dfs(graph,vis,pathvis,num,oncycle)==true)return true;
            }
            else if (pathvis[num]==1)
            return true;
        }
        oncycle[node]=0;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>oncycle(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,pathvis,i,oncycle);
            }
        }
        for(int i =0;i<n;i++)
        {
            if (oncycle[i]==0)
            ans.push_back(i);
        }
        return ans;
    }
};