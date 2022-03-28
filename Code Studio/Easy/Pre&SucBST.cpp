/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/



pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    //Find the key
    
    BinaryTreeNode<int> * temp = root;
    
    int pre = -1, suc = -1;
    
    while(temp && temp->data != key){
        if(key<temp->data){
            suc = temp->data;
            temp = temp->left;
        }
        else {
            pre = temp->data;
            temp = temp -> right;
        }    
    }
    
    BinaryTreeNode<int> * leftTree = temp->left, * rightTree = temp -> right;
    
    while(leftTree){
        pre = leftTree -> data;
        leftTree = leftTree->right;
    }
    
    
    while(rightTree){
        suc = rightTree -> data;
        rightTree = rightTree->left;
    }
    
    return {pre,suc};
    
    
}
