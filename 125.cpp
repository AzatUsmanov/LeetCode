class Solution {
public:
    string str(string& s){
        string ans;
        for(int i=0;i<s.size();i++){
            if ('a' <= s[i] && s[i] <= 'z'){
                ans += s[i];
            } else if ('A' <= s[i] && s[i] <= 'Z'){
                ans += char(int(s[i])+32);
            } else if ('0' <= s[i] && s[i] <= '9'){
                ans += s[i];
            } 
        }
        return ans;
    }
    bool isPalindrome(string s) {
        s = str(s);
        int i = 0, j = s.size()-1;

        while (i <= j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
