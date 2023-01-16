#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>&arr) 
    {
        int size=arr.size();
        int count=0;
        int peak=-1;//this is the index of the smallest of the peak elements
        for(int i=1;i<size;i++)
        {
            if(arr[i]<=arr[i-1])
            {
                if(peak!=-1 && arr[peak-1]<arr[i] && arr[peak]>arr[i])
                    peak=i;
                continue;
            } 
            else  //we see a peak
            {
                if(peak==-1)//this is the first peak
                {
                    peak=i;
                    count=2;
                }
                else
                {
                    //we have discovered a peak before
                    if(arr[peak-1]<arr[i-1])return true;
                    if(arr[i]>arr[peak])
                        return true;
                    else
                    {
                        peak=i;
                    }
                }
            }
        }
        return false;
        
    }
};
