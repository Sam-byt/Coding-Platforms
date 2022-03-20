// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

void createMapping(int in[],unordered_map<int,int>&nodeToIndex,int n)
{
    for(int i=0; i<n; i++)nodeToIndex[in[i]] = i;
}

Node * solve(int in[], int post[], int &postorderindex, int inorderStart, int inorderEnd, int n,unordered_map<int,int>&nodeToIndex){
    if(postorderindex<0 || inorderStart>inorderEnd)return nullptr;
    
    int element = post[postorderindex--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];
    
    
    root->right = solve(in,post,postorderindex,position+1,inorderEnd,n,nodeToIndex);
    root->left = solve(in,post,postorderindex,inorderStart,position-1,n,nodeToIndex);
    
    return root;
}






Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postorderindex = n-1;
    unordered_map<int,int>nodeToIndex;
    createMapping(in,nodeToIndex,n);
    return solve(in,post,postorderindex,0,n-1,n,nodeToIndex);
}
