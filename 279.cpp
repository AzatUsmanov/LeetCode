#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < numbers.size(); i++){
            map[numbers[i]].push_back(i);
        }
        for (auto& i : map){
            auto x = map.find(target - i.first);
            if (x != map.end() && (*x).first != i.first){
                return {min(i.second[0] + 1, (*x).second[0] + 1), 
                max(i.second[0] + 1, (*x).second[0] + 1)};
            } else if (x != map.end() && (*x).second.size() > 1){
                return {(*x).second[0] + 1, (*x).second[1] + 1};
            }
        }
        return {0,0};
    }
};