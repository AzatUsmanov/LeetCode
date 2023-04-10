class Solution {
public:
string func(string& s, int x){
    int start = 0, end = 0, a, b;
    for(int i = x, j = x; i < s.length() && j >= 0; i++){
        if (s[i] == s[j]){
            start = j--;
            end = i;
        } else break;
    }
    a = start; b = end;
    for(int i = x, j = x + 1; i < s.length() && j >= 0; i++){
        if (s[i] == s[j]){
            start = j--;
            end = i;
        } else break;
    }
    if (b - a > end - start){
        return string(s.begin() + a, s.begin() + b + 1);
    } else {
        return string(s.begin() + start, s.begin() + end + 1);
    }
}
    
    string longestPalindrome(string s) {
        string ans = "", temp;
        for (int i = 0; i < s.length(); i++){
            temp = func(s, i);
            if (temp.length() > ans.length()){
                ans = temp;
            }
        }
        return ans;
    }
};