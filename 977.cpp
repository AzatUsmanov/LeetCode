#include <algorithm>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> minus, plus, ans;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0){
                minus.push_back(nums[i]*nums[i]);
            } else {
                plus.push_back(nums[i]*nums[i]);
            }
        }
        reverse(minus.begin(), minus.end());
        int i = 0, j = 0;
        while (i < plus.size() && j < minus.size()){
            if (minus[j] >= plus[i]){
                ans.push_back(plus[i]);
                i++;
            } else if (minus[j] < plus[i]){
                ans.push_back(minus[j]);
                j++;
            } 
        }
        while (i < plus.size()){
            ans.push_back(plus[i++]);
        }
        while (j < minus.size()){
            ans.push_back(minus[j++]);
        }
        return ans;
    }
};