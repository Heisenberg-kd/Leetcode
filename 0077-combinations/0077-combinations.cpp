class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) 
    {
        vector <int>ans;
        solve(1,n,k,ans);
        return res;
    }

    void solve(int n, int tot, int k , vector<int>&ans)
    {
        if(ans.size()==k)
        {
            res.push_back(ans);
            return;
        }
        for (int i =n;i<=tot;i++)
        {
            ans.push_back(i);
            solve(i+1,tot,k , ans);
            ans.pop_back();
        }
    }
};