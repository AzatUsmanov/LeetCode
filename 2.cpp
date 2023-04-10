#include <algorithm>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<long long> a, b, c;
        while (l1 != NULL){
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL){
            b.push_back(l2->val);
            l2 = l2->next;
        }
        int n = max(int(a.size()), int(b.size()));
        c.resize(n + 1, 0);
        for (int i = 0; i < n; i++){
            if (i < a.size()){
                c[i] += a[i];
            }
            if (i < b.size()){
                c[i] += b[i];
            }
            c[i+1] += c[i]/10;
            c[i] = c[i]%10;
        }
        if (c[n]){
            n++;
        }
        ListNode* res = NULL;
        ListNode* ans = NULL;
        for(int i = 0; i < n; i++){
            if (res == NULL){
                res = new ListNode(c[i]);
                ans = res;
            } else { 
                res->next = new ListNode(c[i]);
                res = res->next;
            }
        }
       return ans; 
    }
};