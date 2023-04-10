#include <algorithm>
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(0);
        vector<int> a;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                a.push_back(count);
                a.push_back(0);
                count = 0;
            } else if (nums[i] == 1){
                count++;
            }
        }
        if (a.size() == 2){
            return max(0, a[0]-1);
        } 
        int Max = 0;
        for (int i = 2; i < a.size(); i++){
            Max = max(Max, a[i-2] + a[i-1] +a[i]);
        }
        return Max;
    }
};