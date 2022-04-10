class TrieNode{
  public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;
    
    TrieNode(char ch){
        this -> data = ch;
        for(int i=0;i<26;i++)children[i] = nullptr;
        this -> isTerminal = false;
        this -> childCount = 0;
    }
};

void insertUtil(TrieNode *root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    
    int index = word[0] - 'a';
    TrieNode *child;
    
    if(root->children[index]){
        child = root->children[index];
    }
    else{
        child = new TrieNode(word[0]);
        root->children[index] = child;
        (root->childCount)++;
    }
    
    insertUtil(child,word.substr(1));
}


class Trie{
    public:
        TrieNode * root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertTrie(string word){
            insertUtil(root,word);
        }
    
        void lcp(string str, string &ans){
            for(int i = 0;i<str.length();i++){
                char ch = str[i];
                
                if(root->childCount == 1){
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root -> children[index];
                }
                
                else break;
                
                if(root->isTerminal)break;
            }
        }
    
    
    
        
    
        
    
};








class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie();
        for(auto i : strs){
            t->insertTrie(i);
            if (i=="")return "";
        }
        string first = strs[0];
        
        string ans = "";
        
        t->lcp(first,ans);
        
        return ans;
        
    }
};
