#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int i = 1;
        vector<int> lps(s.length(),0);
        int len = 0;
        while(i < s.length()){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else {
                if(len!=0){
                    len = lps[len-1];
                }else{
                    i++;
                }
            }
        }


        return s.substr(0,lps[lps.size()-1]);

    }
};