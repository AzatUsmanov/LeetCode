#include <stack>
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> pairs, newpairs, ans;
        pairs.push_back("");
        for (int i = 0; i < 2*n; i++){
            for(int j = 0; j < pairs.size(); j++){
                newpairs.push_back(pairs[j] + ")");
                newpairs.push_back(pairs[j] + "(");
            }
            pairs = newpairs;
            newpairs = vector<string>();
        }
        for (int i = 0; i < pairs.size(); i++){
            if (check(pairs[i])){
                ans.push_back(pairs[i]);
            }
        }
        return ans;
    }
    bool check(string pairs){
        stack<char> q;
        for(int i = 0; i < pairs.size(); i++){
            if (!q.empty() && pairs[i] == ')' && q.top() == '('){
                q.pop();
            } else if (pairs[i] == '('){
                q.push('(');
            } else return false;
        }
        return q.empty() && true;
    }
};