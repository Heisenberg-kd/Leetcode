class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        auto it1=edges[0];
        auto it2=edges[1];
        int i1,i2,i3;

        if (it1[0]==it2[0])
            return it1[0];
        else if (it1[0]==it2[1])
            return it1[0];
        return it1[1];
    }
};