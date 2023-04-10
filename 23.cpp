/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> minus(10000, 0), plus(10000, 0);
        ListNode* ans = NULL;
        ListNode* result = NULL;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != NULL){
                if (head->val >= 0){
                    plus[head->val]++;
                } else{
                    minus[-head->val]++;
                }
                head = head->next;
            }
        }
        for(int i = minus.size()-1; i >= 0; i--){
            for(int j = 0; j < minus[i]; j++){
                if(ans == NULL){
                    ans = new ListNode(-i);
                    result = ans;
                } else {
                    ans->next = new ListNode(-i);
                    ans = ans->next;
                }
            }
        }
        for(int i = 0; i < plus.size(); i++){
            for(int j = 0; j < plus[i]; j++){
                if(ans == NULL){
                    ans = new ListNode(i);
                    result = ans;
                } else {
                    ans->next = new ListNode(i);
                    ans = ans->next;
                }
            }
        }
        return result;
    }
};