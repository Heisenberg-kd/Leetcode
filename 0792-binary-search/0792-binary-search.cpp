class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l=0;
        int r=nums.size();
        while(l+1<r)
        {
            int mid=l+(r-l)/2;
            if (nums[mid]>target)
            r=mid;
            else
            l=mid;
        }
        return nums[l]==target?l:-1;
    }
};