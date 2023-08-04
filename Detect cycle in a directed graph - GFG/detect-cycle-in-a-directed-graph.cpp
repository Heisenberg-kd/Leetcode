//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) 
    {
        queue<int>q;
        vector<int>indegree(n,0);
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
        return accumulate(indegree.begin(),indegree.end(),0)?true:false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends