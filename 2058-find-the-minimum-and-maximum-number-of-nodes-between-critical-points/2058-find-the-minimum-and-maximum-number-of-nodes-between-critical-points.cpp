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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL|| head->next->next==NULL){
            return {-1, -1};
        }
        vector<int>v;
        vector<int>ans;
        int i=2;
        ListNode* l=head->next;
        ListNode* prev=head;
        while(l->next!=NULL){
            if(l->val > prev->val && l->val > l->next->val)
            v.push_back(i);
            if(l->val < prev->val && l->val < l->next->val)
            v.push_back(i);
            i+=1;
            prev=l;
            l=l->next;
        }
        if(v.size()<2)
        return {-1,-1};
        int min=INT_MAX;
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(min>v[i]-v[i-1]){
                min=v[i]-v[i-1];
            }
        }
        ans.push_back(min);
        ans.push_back(v[v.size()-1]-v[0]);
        return ans;
    }
};