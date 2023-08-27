//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool valid(vector<int>adj[], vector<int>&color, int i ,int n ,int node)
    {
        for(auto it:adj[node])
        {
            if (i==color[it])
            return false;
        }
        return true;
    }
    
    bool solve(vector<int>adj[], vector<int>&color, int m ,int n ,int node)
    {
        //Base Condition
        if(node==n)
        return true;
        
        //Logice the generale.
        for(int i=1;i<=m;i++)
        {
            if(valid(adj,color,i,n,node))
                {
                    color[node]=i;
                    if(solve(adj,color,m,n,node+1)) return true;
                    color[node]=0;
                }
        }
        return false;
    }
    
    
    
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        vector<int>adj[101];
        for(int  i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                if (graph[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }    
            }
        }
        
        vector<int> color(n,0);
        if(solve(adj,color,m , n,0)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends