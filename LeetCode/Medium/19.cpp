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
private:
    int len(ListNode *temp){
        int c = 0;
        while(temp){
            c++;
            temp = temp->next;
        }
        return c;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int p = len(head);
        ListNode *temp = head,*trail =head;
        p-=n;
        
        if(p == 0)return head->next;
        
        while(p--){
            trail = temp;
            temp = temp->next;
        }
        trail->next = temp->next;
        delete(temp);
        
        return head;
    }
};
