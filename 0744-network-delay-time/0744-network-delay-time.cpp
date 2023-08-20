class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,int>>st;
        st.insert({0,k});
        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int d=it.first;
            st.erase(it);
            for(auto i: adj[node])
            {
                if (d+i.second<dist[i.first])
                {
                    if(dist[i.first]!=1e9)
                    {
                        st.erase({dist[i.first],i.first});
                    }
                    dist[i.first]=d+i.second;
                    st.insert({dist[i.first],i.first});
                }
            }
        }
        int ans=INT_MIN;
        for (int i =1;i<n+1;i++)
        {
            ans=max(ans,dist[i]);
            cout<<ans;
        }
        return ans==1e9?-1:ans;
    }

};