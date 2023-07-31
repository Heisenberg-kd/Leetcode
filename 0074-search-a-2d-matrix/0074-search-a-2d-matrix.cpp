class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int l=0;
        int r=row*col;
        while(l+1<r)
        {
            int mid=l+(r-l)/2;
            if(matrix[mid/col][mid%col]<=target)
                l=mid;
            else
                r=mid;
        }
        return matrix[l/col][l%col]==target?true:false;
        
    }
};