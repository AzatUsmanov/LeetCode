#include <algorithm>
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<pair<int,int>> a;
        vector<vector<int>> ans;
        for(int i = 0; i < firstList.size();i++){
            a.push_back({firstList[i][0], firstList[i][1]});
        }
        for(int i = 0; i < secondList.size();i++){
            a.push_back({secondList[i][0], secondList[i][1]});
        }
        sort(a.begin(), a.end());
        pair<int, int> temp = a[0];
        for(int i = 1; i < a.size();i++){
            if (a[i].first <= temp.second && temp.second < a[i].second){
                ans.push_back({a[i].first, temp.second});
                temp = a[i];
            } else if (a[i].first <= temp.second && temp.second >= a[i].second){
                ans.push_back({a[i].first, a[i].second});
            } else {
                temp = a[i];
            }
        }
        return ans;
    }
};