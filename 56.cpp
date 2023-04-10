#include <algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> pairs;
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++){
            pairs.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(pairs.begin(), pairs.end());
        pair<int, int> temp = pairs[0];
        for (int i = 1; i < pairs.size(); i++){
            if (pairs[i].first <= temp.second){
                temp.second = max(pairs[i].second, temp.second);
            } else{
                ans.push_back({temp.first, temp.second});
                temp = pairs[i];
            }
        }
        ans.push_back({temp.first, temp.second});
        return ans;
    }
};