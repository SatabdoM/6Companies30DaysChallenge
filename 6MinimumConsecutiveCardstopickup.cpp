#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, vector<int>>m;
        int ans=1e9;
        for(int i=0; i<cards.size(); i++){
            m[cards[i]].push_back(i);
        }
        for(auto it: m){
            
            if(it.second.size()>1){
                int cnt=1e9;
                for(int j=0; j<it.second.size()-1; j++){
                    cnt=min(cnt, it.second[j+1]-it.second[j]+1);
                }
                ans=min(ans, cnt);
                
            }
        }
        if(ans==1e9){return -1;}
        return ans;
    }
};