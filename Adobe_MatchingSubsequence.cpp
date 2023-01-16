class Solution {
public:
    int find_uper(vector<int>&arr,int ind)
    {
        int ans=-1;
        int left=0,right=arr.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int num=arr[mid];
            if(num>ind)
            {
                ans=num;//potential answer
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0;
        unordered_map<char,vector<int>>map;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]].push_back(i);
        }
        //iterate over the words
        for(auto it:words)
        {
            int len=it.length();
            int upr_ind=-1;
            int i=0;
            for(i=0;i<len;i++)
            {
                char ch=it[i];
                vec_ind=map[ch];
                upr_ind=find_uper(vec_ind,upr_ind);
                if(upr_ind==-1)//no upper index found
                    break;
            }
            if(i==len)//all the characters are present
                count++;
        }
        return count;
    }
};
