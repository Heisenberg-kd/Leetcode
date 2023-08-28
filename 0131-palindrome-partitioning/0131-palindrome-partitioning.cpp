class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
    }

    void solve(int ind, string s, vector<vector<string>>&ans, vector<string>&temp)
    {
        //Base
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        //Logic
        for(int i=ind;i<s.size();i++)
        {
            if(valid(s,i, ind))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }  
    
    }

    bool valid(string s, int i ,int j)
    {
        while(i>=j)
        {
            if(s[j++]!=s[i--])
                return false;
            
        }
        return true;
    }

};