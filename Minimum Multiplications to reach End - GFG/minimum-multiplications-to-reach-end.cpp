//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) 
    {
        int mod=1e5;
        if (s==e)return 0;
        vector<int> dist(mod,1e9);
        dist[s]=0;
        set<pair<int,int>>st;
        st.insert({0,s});
        while(!st.empty())
        {
            auto tp=*(st.begin());
            int node=tp.second;
            int d=tp.first;
            st.erase(tp);
            for(auto it:arr)
            {
                int mult=(it*node)%mod;
                if(dist[mult]>d+1)
                {
                    dist[mult]=d+1;
                    if (mult==e)
                        return d+1;
                    st.insert({d+1,mult});
                }
            }
        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends