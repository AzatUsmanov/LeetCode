#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1);
        unordered_map<int, vector<int>> map;
        int result = 0;
        map[0].push_back(0);
        for(int i = 1; i < sum.size(); i++){
            sum[i] = sum[i-1] + nums[i-1];
            if (map.find(sum[i] - k) != map.end()){
                result += map[sum[i] - k].size();
            }
            map[sum[i]].push_back(i);
        }
        return result;
    }
};