//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) 
    {
        vector<pair<int,int>>adj[n];
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e8);
        dist[s]=0;
        for (int i =0;i<n;i++)
        {
            for (int j=0;j<edges.size();j++)
            {
                if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                    dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
            }
        }
        for (int j=0;j<edges.size();j++)
            {
                if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                    return {-1};
            }
        return dist;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends