class Solution {
public:
    void printF(int ind,vector<int>&ds, vector<int>&arr,int n,vector<vector<int>>&ans)
    {
    // Base condtion to print when we reach end .
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }
        //take conditon
        ds.push_back(arr[ind]);
        printF(ind+1,ds,arr,n,ans);
        //don't take condition.
        ds.pop_back();
        printF(ind+1,ds,arr,n,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        printF(0,ds,nums,nums.size(),ans);
        return ans;
    }
};