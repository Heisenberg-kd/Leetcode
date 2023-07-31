class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        //FFFF'T'TTTT
        int l =0;
        long long int r= 1e9;
        while(l+1<r)
        {
            long long int mid=l+(r-l)/2;
            if (ok(piles,h, mid))
                r=mid;
            else
                l=mid;
        }
        return r;
    }

    bool ok(vector<int>&piles,long long int h ,long long int mid)
    {
        long long int sum=0;
        for (long long int i:piles)
        {
            sum+=(i+mid-1)/mid;
        }
        return sum<=h;
    }
};