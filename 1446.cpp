class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for(int i = 0, j = 0; i < s.length(); i++){
            if(s[i] == s[j]){
                ans = max(ans, i - j + 1);
            } else {
                j = i;
            }
        }
        return ans;   
    }
};