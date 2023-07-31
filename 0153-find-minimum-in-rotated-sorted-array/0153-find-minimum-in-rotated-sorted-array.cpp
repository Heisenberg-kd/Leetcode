class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int r= nums.size()-1;
        int l=-1;
        int res=-1;
        while(l+1<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[nums.size()-1])
                r=mid;
            else
            {
                l=mid;
            }
        }
        return nums[r];
    }
};