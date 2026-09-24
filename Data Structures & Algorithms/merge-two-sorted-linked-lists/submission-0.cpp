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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* d=new ListNode(0);
        ListNode* ans=d;


        while(list1 && list2){
            if(list2->val<=list1->val){
                d->next=list2;
                list2=list2->next;
            }else{
                d->next=list1;
                list1=list1->next;
            }
            d=d->next;
            d->next=NULL;
        }
        if(list1)d->next=list1;
        if(list2)   d->next=list2;
        return ans->next;

    }
};
