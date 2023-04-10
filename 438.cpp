class Solution {
public:
    vector<char> sort(vector<char> a){
        vector<char> ans;
        vector<int> vec(26,0);
        for(int i = 0; i < a.size(); i++){
            vec[a[i]-int('a')]++;
        }
        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < vec[i]; j++){
                ans.push_back(char(i + int('a')));
            }
        }
        return ans;
    }
     bool check(string& s1, string& s2, int start, int end, vector<char>& vec1){
        vector<char> vec;
        for(int i = start;  i <= end; i++){
            vec.push_back(s2[i]);
        }
        vec = sort(vec);
        return vec == vec1;
    }
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ans;
        if (s1.size() > s2.size()){
            return ans;
        }
        int sum1 = 0, sum2 = 0;
        vector<char> vec;
        for(int  i = 0; i < s1.length(); i++){
            sum1 += int(s1[i]);
            vec.push_back(s1[i]);
        }
        vec = sort(vec);
        for(int  i = 0; i < s1.length(); i++){
            sum2 += int(s2[i]);
        }
        if (sum1 == sum2 && check(s1, s2, 0, s1.size()-1, vec)){
            ans.push_back(0);
        }
        for(int i = s1.size(); i < s2.size(); i++){
            sum2 = sum2 + int(s2[i]) - int(s2[i - s1.size()]);
            if (sum1 == sum2 && check(s1, s2, i - s1.size() + 1, i, vec)){
                ans.push_back(i - s1.size() + 1);
            }
        }
        return ans;
    }
};