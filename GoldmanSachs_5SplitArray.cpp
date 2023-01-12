#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &arr)
    {
        // We need 2 hashmaps->
        // 1.available(to store what elements are available)
        // 2.requirement(to store what elements are required by a previous subsequence)
        unordered_map<int, int> map, req;
        // traverse the elements and store the count in the avail map
        for (auto it : arr)
            map[it]++;
        // traverse the array and check the conditions
        for (auto it : arr)
        {
            if (map[it] == 0) // element is not available to be added in any subseq
                continue;
            map[it]--;
            // check if the element is required by a previous subseq
            if (req[it])
            {
                // add to the prev subseq
                req[it]--;
                req[it + 1]++;
            }
            // check if we can start a new subseq
            else if (map[it + 1] && map[it + 2])
            {
                map[it + 1]--;
                map[it + 2]--;
                req[it + 3]++;
            }
            // valid subsequence is not possible
            else
                return false;
        }
        return true;
    }
};