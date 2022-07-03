class TrieNode {
public:
    TrieNode* next[26];
    bool isWordEnd;
    TrieNode() {
        for(int i=0;i<26;i++) next[i] = NULL;
        isWordEnd = false;
    }
    void setWordEnd(){
        isWordEnd = true;
    }
    bool hasWordEnd(){
        return isWordEnd;
    }
};

class Trie {
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(!curr->next[idx]) {
                curr->next[idx] = new TrieNode();
            }
            curr = curr->next[idx];
        }
        curr->setWordEnd();
    }
    
    bool search(string word) {
        TrieNode* curr = find(word);
        return curr != NULL && curr->hasWordEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = find(prefix);
        return curr != NULL;
    }
    private:
    TrieNode* find(string key){
        TrieNode* curr = root;
        for(int i=0;i<key.length();i++){
            int idx = key[i] - 'a';
            if(!curr->next[idx]) {
                curr = curr->next[idx];
                break;
            }
            curr = curr->next[idx];
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */