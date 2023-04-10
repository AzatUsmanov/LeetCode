#include<algorithm>
#include<vector>
class Solution {
public:
    bool check(string& s1, string& s2, int start, int end, vector<char>& vec1){
        vector<char> vec;
        for(int i = start;  i <= end; i++){
            vec.push_back(s2[i]);
        }
        sort(vec.begin(), vec.end());
        return vec == vec1;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }
        int sum1 = 0, sum2 = 0;
        vector<char> vec;
        for(int  i = 0; i < s1.length(); i++){
            sum1 += int(s1[i]);
            vec.push_back(s1[i]);
        }
        sort(vec.begin(), vec.end());
        for(int  i = 0; i < s1.length(); i++){
            sum2 += int(s2[i]);
        }
        if (sum1 == sum2 && check(s1, s2, 0, s1.size()-1, vec)){
            return true;
        }
        for(int i = s1.size(); i < s2.size(); i++){
            sum2 = sum2 + int(s2[i]) - int(s2[i - s1.size()]);
            if (sum1 == sum2 && check(s1, s2, i - s1.size() + 1, i, vec)){
                return true;
            }
        }
        return false;
    }
};