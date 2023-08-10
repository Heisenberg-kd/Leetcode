//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        queue<pair<int,int>>q;
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({src,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            for(int i : adj[node])
            {
                if(d+1<dist[i])
                {
                    dist[i]=d+1;
                    q.push({i,d+1});
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            if (dist[i]==1e9)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends