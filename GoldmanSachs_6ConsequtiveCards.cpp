#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumCardPickup(vector<int> &arr)
    {
        // hashmap 1 based indexing
        unordered_map<int, int> map;
        int n = arr.size();
        int min_count = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (!map[arr[i]])
            {
                map[arr[i]] = i + 1;
                continue;
            }
            // update the min count
            min_count = min(min_count, i - map[arr[i]] + 2);
            // update the map with the current index
            map[arr[i]] = i + 1;
        }
        if (min_count == 1e9)
            return -1;
        return min_count;
    }
};