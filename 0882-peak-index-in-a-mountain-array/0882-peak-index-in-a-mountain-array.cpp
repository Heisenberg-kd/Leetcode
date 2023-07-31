class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l =-1;
        int r=arr.size()-1;
        while(l+1<r)
        {
            int mid =l+(r-l)/2;
            if (arr[mid+1]<arr[mid])
                r=mid;
            else 
                l=mid;
        }
        return r;
        
    }
};
//FFFFF'T'TTTT