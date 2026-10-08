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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int n = 1;
        ListNode* old_tail = head;

        while (old_tail->next != NULL) {
            old_tail = old_tail->next;
            n++;
        }

        k = k % n;

        // if(k == 0)return head;
        int newtail_index = n - k;

        ListNode* new_tail = new ListNode(-1);
        new_tail->next=head;

        while (newtail_index) {
            new_tail = new_tail->next;
            newtail_index--;
        }

        

        old_tail->next=head;
        head=new_tail->next;
        new_tail->next=NULL;

        return head;
    }
};