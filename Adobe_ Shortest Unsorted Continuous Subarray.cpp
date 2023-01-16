class Solution {
public:
    int findUnsortedSubarray(vector<int>&arr)
    {
        int s_start=-1;
        int s_end=-1;
        int n=arr.size();
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        int i=0;
        while(i<n)
        {
            if(arr[i]!=sorted[i])
            {
                if(s_start==-1)
                {
                    s_start=i;
                    while(i<n && arr[i]!=sorted[i])
                        i++;
                    s_end=i-1;
                }
                else
                    s_end=i;
            }
            i++;
        }
        if(s_end==s_start)return 0;
        return s_end-s_start+1;
    }
};
