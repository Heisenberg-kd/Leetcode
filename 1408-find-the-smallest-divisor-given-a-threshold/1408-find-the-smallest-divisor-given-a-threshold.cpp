class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        //FFFFTTTTTT
        int l=0;
        int r=5000000;
        while(l+1<r)
        {
            int mid=l+(r-l)/2;
            if (ok(nums,mid,threshold))
                r=mid;
            else
                l=mid;
        }
        return r;
    }

    bool ok(vector <int> v, int mid , int threshold)
    {
        int sum=0;
        for (int i :v)
        {
            sum+=(i+mid-1)/mid; //to ceil value.
        }
        return sum<=threshold;
    }
};