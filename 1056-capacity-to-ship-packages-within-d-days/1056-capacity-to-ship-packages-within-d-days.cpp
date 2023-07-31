class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        //FFFF'T'TTTT
        int l =0;
        long long int r= 50000*500;
        while(l+1<r)
        {
            long long int mid=l+(r-l)/2;
            if (ok(weights,days, mid))
                r=mid;
            else
                l=mid;
        }
        return r;
    }

    bool ok(vector<int>&piles,long long int h ,long long int mid)
    {
        long long int sum=0;
        int total=1;
        for (long long int i:piles)
        {
            if (i>mid)
                return false;
            if(sum+i>mid)
            {
                total++;
                sum=0;
            }
            sum+=i;
        }
        return total<=h;
    }
};
