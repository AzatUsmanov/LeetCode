#include <algorithm>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = nums.size();
        for(int i = 0; i < nums.size() && start == nums.size(); i++){
            if (nums[i] == 0){
                start = i;
            }
        }
        for(int i = start,j = start; j < nums.size();j++){
            if (nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};