#include <algorithm>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for (int i; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        for(auto i : map){
            ans.push_back(i.second);
        }
        return ans;
    }
};