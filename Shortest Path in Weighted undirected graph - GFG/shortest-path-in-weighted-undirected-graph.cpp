//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        set<pair<int,int>>st;
        st.insert({0,1});
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        vector<int>ans;
        int parent[n+1];
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
        }
        while(!st.empty())
        {
            auto it =*(st.begin());
            int d=it.first;
            int node=it.second;
            st.erase({d,node});
            for(auto i: adj[node])
            {
                if (dist[i.first]>d+i.second)
                {
                    parent[i.first]=node;
                    if (dist[i.first]!=1e9)
                    {
                        st.erase({dist[i.first],i.first});
                    }
                    dist[i.first]=d+i.second;
                    st.insert({d+i.second,i.first});
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        int j=n;
        while(parent[j]!=j)
        {
            ans.push_back(j);
            j=parent[j];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends