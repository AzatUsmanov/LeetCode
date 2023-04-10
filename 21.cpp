class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = NULL;
        ListNode* head = NULL;
        int val = 0;
        while (list1 != NULL || list2 != NULL){
            if (list1 == NULL){
                val = list2->val;
                list2 = list2->next;
            } else if(list2 == NULL){
                val = list1->val;
                list1 = list1->next;
            } else if (list1->val < list2->val){
                val = list1->val;
                list1 = list1->next;
            } else {
                val = list2->val;
                list2 = list2->next;
            }

            if (ans == NULL){
                ans = new ListNode(val);
                head = ans;
            } else {
                ans->next = new ListNode(val);
                ans = ans->next;
            }
        }
        return head;
    }
};