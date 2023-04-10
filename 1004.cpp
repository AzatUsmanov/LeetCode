class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            if (!nums[i] && k){
                k--;
            } else if (!nums[i]){
                while(nums[j]){
                    j++;
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};