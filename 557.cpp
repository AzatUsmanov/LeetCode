#include <vector>
#include <algorithm>
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> a(max(num1.length(), num2.length()) + 1, 0);
        string ans = "";
        for (int i = 0; i < num1.length(); i++){
            a[i] += int(num1[i] - '0');
        }
        for (int i = 0; i < num2.length(); i++){
            a[i] += int(num2[i] - '0');
        }
        for(int i = 0; i < a.size(); i++){
            if (a[i] >= 10){
                a[i+1] += a[i]/10;
                a[i] = a[i]%10;
            }
        }
        if (!a[a.size()-1]){
            a.resize(a.size()-1);
        }
        reverse(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++){
            ans += char(a[i] + '0');
        }
        return ans;
    }
};