#include <unordered_set>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i = 0; i <= n; i++){
            set.insert(i);
        }
        for(int i = 0; i < n; i++){
            set.erase(nums[i]);
        }
        return (*set.begin());
    }
};