#include <vector>
#include <unordered_map>
class Solution {
public:

    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> map;
        int ans = 100000000;
        for (int i = 0; i < s.length(); i++){
            map[s[i]].push_back(i);
        }
        for(auto& i : map){
            if (i.second.size() == 1){
                ans = min(ans, i.second[0]);
            }
        }
        if (ans == 100000000){
            return -1;
        } else{
            return ans;
        }
    }
};