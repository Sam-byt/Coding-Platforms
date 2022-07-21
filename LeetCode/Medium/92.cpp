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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *first = head,  *leftPrev = nullptr, *last = head, *rightTail = nullptr;
        for(int i=0;i<left-1; i++){
            leftPrev = first;
            first = first->next;
        }
        
        for(int i=0;i<right-1;i++){
            last = last->next;
        }
        
        rightTail = last->next;
        
        last->next = nullptr;
        // if(leftPrev)leftPrev->next = nullptr;
        
        
        ListNode *p = first, *q = nullptr, *r = nullptr;
        
        while(p){
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        
        if(leftPrev)leftPrev->next = q;
        
        first->next = rightTail;
        
        return left == 1?q:head;
    }
};
