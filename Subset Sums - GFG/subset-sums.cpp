//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void printF(int ind,vector<int>&ds, vector<int>&arr,int n,vector<int>&ans)
    {
    // Base condtion to print when we reach end .
        if(ind==n)
        {
            ans.push_back(accumulate(ds.begin(),ds.end(),0));
            return;
        }
        //take conditon
        ds.push_back(arr[ind]);
        printF(ind+1,ds,arr,n,ans);
        //don't take condition.
        ds.pop_back();
        printF(ind+1,ds,arr,n,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        vector<int>ds;
        printF(0,ds,arr,N ,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends