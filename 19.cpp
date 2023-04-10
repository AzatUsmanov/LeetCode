#include <vector>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> a;
        ListNode* ans = NULL;
        while (head != NULL){
            a.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < a.size(); i++){
            if (i != a.size() - n && ans == NULL){
                ans = new ListNode(a[i]);
                head = ans;
            } else if (i != a.size() - n){
                ans->next = new ListNode(a[i]);
                ans = ans->next;
            }
        }
        return head;
    }
};