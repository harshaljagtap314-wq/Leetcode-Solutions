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
    ListNode* oddEvenList(ListNode* head) {


        // brute force appraoch


        // ListNode*temp=head;

        // vector<int> arr;

        // while(temp!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next;
        // }

        // vector<int> result;

        // for(int i=0;i<arr.size();i+=2){
        //     result.push_back(arr[i]);
        // }

        // for(int i=1;i<arr.size();i+=2){
        //     result.push_back(arr[i]);
        // }

        // temp=head;

        // for(int i=0;i<result.size();i++){
        //     temp->val=result[i];
        //     temp=temp->next;
        // }

        // return head;



        // optimal solution 

        if(head ==NULL ){
            return NULL;
        }

        if(head->next == NULL){
            return head;
        }

        ListNode* oddptr=head;
        ListNode*evenptr=head->next;
        ListNode* evenhead=head->next;





        while(evenptr != NULL && evenptr->next!=NULL){
            oddptr->next=oddptr->next->next;
            evenptr->next=evenptr->next->next;

            oddptr=oddptr->next;
            evenptr=evenptr->next;
        }

        oddptr->next=evenhead;


        return head;

        

    }
};