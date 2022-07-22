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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return nullptr;
        ListNode *temp = head, *tail = nullptr;
        while(temp && temp->val < x){
            tail = temp;
            temp = temp->next;
        }
        
        if(temp){
            bool flag = false;
            if(temp == head)flag = true;
            ListNode *arb = temp->next;
            while(arb){
                if(arb->val < x){
                    
                    temp->next = arb->next;
                    
                    if(flag){
                        arb->next = head;
                        head = arb;
                        flag = false;
                    }
                    else{
                        arb->next = tail->next;
                        tail->next = arb;
                    }
                    
                    tail = arb;
                    arb = temp->next;
                }
                else{
                    temp = arb;
                    arb = arb->next;
                }
                
            }
            
        }
        return head;
        
    }
};
