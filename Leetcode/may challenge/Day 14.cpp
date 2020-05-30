// This is a standard implementation of Tries

class TrieNode {
public:
    int val;
    TrieNode* children[26];
    
    TrieNode(){
        val=0;
        for(int i=0;i<26;++i)
            children[i] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie(){
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();++i){
            int index = word[i]-'a';
            if(!temp->children[index])
                temp->children[index] = new TrieNode();
            temp = temp->children[index];
        }
        temp->val = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();++i){
            int index = word[i]-'a';
            if(!temp->children[index])
                return false;
            temp = temp->children[index];
        }
        return (temp!=NULL && temp->val != 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
                TrieNode* temp = root;
        for(int i=0;i<prefix.length();++i){
            int index = prefix[i]-'a';
            if(!temp->children[index])
                return false;
            temp = temp->children[index];
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
