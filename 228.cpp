#include <string> 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(100000000);
        vector<pair<long, long>> ans;
        vector<string> result;
        long i = 0;
        for(long j = 0; j < nums.size(); j++){
            if (i != j && nums[j] - 1 != nums[j-1]){
                ans.push_back({i, j - 1});
                i = j;
            }
        }
        for(long j = 0; j < ans.size(); j++){
            if (ans[j].first == ans[j].second){
                result.push_back(to_string(nums[ans[j].first]));
            } else {
                result.push_back(to_string(nums[ans[j].first])+ "->" + to_string(nums[ans[j].second]));
            }
        }
        return result;
    }
};