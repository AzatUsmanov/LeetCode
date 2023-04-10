#include <vector>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* a = NULL;
        vector<int> vec;
        while(head != NULL){
            vec.push_back(head->val);
            head = head->next;
        }
        for (int i = vec.size()-1; i >= 0; i--){
            if (a == NULL){
                a = new ListNode(vec[i]);
                head = a;
            } else {
                a->next = new ListNode(vec[i]);
                a = a->next;
            }
        }
        return head;
    }
};