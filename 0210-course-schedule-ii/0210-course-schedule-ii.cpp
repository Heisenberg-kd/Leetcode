class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        queue<int>q;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i =0;i<n;i++)
        {
            for (int num:adj[i])
                indegree[num]++;
        }
        //Multisource BFS
        for (int i =0;i<n;i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for (auto num:adj[node])
            {
                indegree[num]--;
                if (indegree[num]==0)
                    q.push(num);
            }
        }
        vector<int>p;
        return accumulate(indegree.begin(),indegree.end(),0)?p:ans;
        
        
    }
};