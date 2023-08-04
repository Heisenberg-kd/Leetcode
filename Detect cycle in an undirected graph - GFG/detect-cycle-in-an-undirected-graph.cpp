//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int curr, vector<int>adj[],int vis[],int parent)
    {
        vis[curr]=1;
        for(auto i:adj[curr])
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis,curr)==true)return true;
            }
            else if (parent!=i)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        //DFS
        int vis[V]={0};
        for(int i =0;i<V;i++)
        {
            if(!vis[i])
            {
                bool ans=detect(i,adj,vis,-1);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends