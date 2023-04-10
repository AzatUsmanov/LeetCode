#include <string>
class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        vector<string> ans;
        chars.push_back('%');
        for(int i = 0; i <chars.size(); i++){
            if (i != j && chars[i] != chars[i-1] && i == j + 1){
                ans.push_back(string(1,chars[j]));
                j = i;
            } else if (i != j && chars[i] != chars[i-1]){
                ans.push_back(string(1, chars[j]) + to_string(i-j));
                j = i;
            }
        }
        chars.clear();
        for(int i = 0; i < ans.size(); i++){
            for(int k = 0; k < ans[i].size();k++){
                chars.push_back(ans[i][k]);
            }
        }
        return chars.size();
    }
};