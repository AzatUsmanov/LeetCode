#include <algorithm>
class Solution {
public:
    string reverseWords(string s) {
        string temp = "", ans = "";
        s += ' ';
        for (int i = 0; i <  s.length(); i++){
            if (s[i] != ' '){
                temp += s[i];
            } else if (s[i] == ' ' && temp.length()){
                reverse(temp.begin(),temp.end());
                ans = ans + temp;
                ans += s[i];
                temp = "";
            } else {
                ans += s[i];
            }
        }
        return string(ans.begin(), ans.end()-1);
    }
};