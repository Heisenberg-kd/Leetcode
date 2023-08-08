class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int p1=0;
        int p2=0;
        int t=0;
        while(t!=haystack.size() && p2<haystack.size())
        {
            
            if (needle[p2]==haystack[p1])
            {
                p2++;
                p1++;
                if(p2==needle.size())
                return t;
            }
            else
            {
                t++;
                p2=0;
                p1=t;
                
            }
        }
        return -1;
        
    }
};