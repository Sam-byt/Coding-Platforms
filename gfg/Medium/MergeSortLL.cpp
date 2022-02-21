// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
    private:
    Node * findMiddle(Node* head)
    {
        Node *fast = head->next;
        Node *slow = head;
            
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
            
        return slow;
    }
    
    Node * merge(Node * left, Node * right)
    {
        if(!left)return right;
        if(!right)return left;
        
        Node *ans = new Node(-1); //dummy!
        Node *temp = ans;
        
        while(left && right)
        {
            if(left->data < right->data)
            {
                temp -> next = left;
                temp = left;
                left = left->next;
                
            }
            
            else{
                
                temp -> next = right;
                temp = right;
                right = right->next;
            }
        }
        
        while(left)
        {
            temp -> next = left;
            temp =left;
            left = left -> next;
        }
        
        while(right)
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        ans = ans -> next;
        
        return ans;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next)return head;
        else{
            Node * mid = findMiddle(head);
            
            Node *left = head;
            Node *right = mid -> next;
            
            mid -> next = nullptr;
            
            left = mergeSort(left);
            right = mergeSort(right);
            
            Node *result = merge(left,right);
            
            return result;
            
        }
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
