class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        queue<int>q;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
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
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for (auto num:adj[node])
            {
                indegree[num]--;
                if (indegree[num]==0)
                    q.push(num);
            }
        }
        return accumulate(indegree.begin(),indegree.end(),0)?false:true;
    }
};