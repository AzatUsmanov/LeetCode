#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        for(auto i :  map){
            auto x = map.find(target - i.first);
            if (x != map.end() && (*x).first != i.first){
                return {i.second[0], (*x).second[0]};
            } else if (x != map.end() && (*x).second.size() > 1){
                 return {i.second[0], (*x).second[1]};
            }
        }
        return {0,0};
    }
};