#include <queue>
#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        queue<char> q;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if (set.find(s[i]) == set.end()){
                q.push(s[i]);
                set.insert(s[i]);
                ans = max(ans, int(set.size()));
            } else {
                while(!q.empty() && q.front() != s[i]){
                    set.erase(q.front());
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
            }
        }
        return ans;
    }
};