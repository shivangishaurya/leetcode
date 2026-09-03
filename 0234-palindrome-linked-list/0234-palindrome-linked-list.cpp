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
    bool isPalindrome(ListNode* head) {
    ListNode* slow= head;
    ListNode* fast=head;
    if(head->next==NULL)
    return true;
    if(head!=NULL&&head->next!=NULL&&head->next->next==NULL)
    {
        if(head->val==head->next->val)return true;
        else return false;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* prev=NULL;
    ListNode* curr= slow;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
ListNode *a=head;
ListNode *b=prev;
while(b!=NULL){
    if(a->val!=b->val)
    return false;
    a=a->next;
    b=b->next;
}
return true;
}
};