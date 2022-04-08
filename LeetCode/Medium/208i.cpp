class TrieNode{
  public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        this -> data = ch;
        for(int i=0;i<26;i++)children[i] = nullptr;
        this -> isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        int index;
        TrieNode *child = root;
        
        for(auto i : word){
            index = i - 'a';
            if(child->children[index]){
                child = child ->children[index];
            }
            else{
                TrieNode *temp = new TrieNode(i);
                child->children[index] = temp;
                child = temp;
            }
        }
        
        child ->isTerminal = true;
    }
    
    bool search(string word) {
        
        int index;
        TrieNode *child = root;
        
        for(auto i : word){
            index = i - 'a';
            if(child -> children[index]){
                child = child->children[index];
            }
            else return false;
        }
        
        return child -> isTerminal;
        
        
        
    }
    
    bool startsWith(string prefix) {
        
        int index;
        TrieNode *child = root;
        
        for(auto i : prefix){
            index = i - 'a';
            if(child -> children[index])
                child = child->children[index];
            else return false;
            
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
