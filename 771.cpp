#include <unordered_map>
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> map;
        int ans = 0;
        for (int i = 0; i < jewels.length(); i++){
            map[jewels[i]] = 0;
        }
        for (int i = 0; i < stones.length(); i++){
            if (map.find(stones[i]) != map.end()){
                map[stones[i]]++;
            }
        }
        for (auto& i : map){
            ans += i.second;
        }
        return ans;
    }
};