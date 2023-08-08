//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        set<pair<int,int>>pq;
        vector<int>dist(n,1e9);
        dist[s]=0;
        pq.insert({0,s});
        
        while(!pq.empty())
        {
            auto it =*(pq.begin());
            int d=it.first;
            int node=it.second;
            pq.erase(it);
            
            for(auto i:adj[node])
            {
                int edgewt=i[1];
                int edgenode=i[0];
                
                if(d+edgewt<dist[edgenode])
                {
                    if(dist[edgenode]!=1e9)
                    {
                        pq.erase({dist[edgenode],edgenode});
                    }
                    dist[edgenode]=d+edgewt;
                    pq.insert({d+edgewt,edgenode});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends