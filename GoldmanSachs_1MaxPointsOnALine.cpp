#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double find_slope(int x1, int y1, int x2, int y2)
    {
        if (x2 == x1)
            return 1e9;
        double slope = (double)(y2 - y1) / (double)(x2 - x1);
        return slope;
    }
    int maxPoints(vector<vector<int>> &arr)
    {
        int size = arr.size();
        if (size <= 2)
            return size;
        // count variable to store the largest count
        int max_count = 1;
        for (int i = 0; i < size - 1; i++)
        {
            // first point:
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            // map: slope->count
            unordered_map<double, int> map;
            for (int j = i + 1; j < size; j++)
            {
                // second point:
                int x2 = arr[j][0];
                int y2 = arr[j][1];
                double slope = find_slope(x1, y1, x2, y2);
                map[slope]++;
                max_count = max(max_count, map[slope]);
            }
        }
        return max_count + 1;
    }
};