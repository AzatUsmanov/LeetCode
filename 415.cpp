#include <vector>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while(head != NULL){
            a.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = a.size() - 1;
        while (i < j){
            if (a[i] != a[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};