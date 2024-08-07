#include <string>
#include <array>

using namespace std;

class Trie {
public:
    array<Trie*, 26> childNode;
    bool terminal;
    string val = "";

    Trie() {
        childNode = {};
        terminal = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->childNode[word[i]-'a']) {
                curr->childNode[word[i]-'a'] = new Trie();
            }
            curr = curr->childNode[word[i]-'a'];
        }
        curr->val = word;
        curr->terminal = true;
    }
    
    bool search(string word) {
        int i = 0;
        Trie* curr = this;
        while (i < word.size()) {
            if (!curr->childNode[word[i]-'a']) {
                return false;
            }
            curr = curr->childNode[word[i]-'a'];
            ++i;
        }
        return curr->val == word;
    }
    
    bool startsWith(string prefix) {
        int i = 0;
        Trie* curr = this;
        while (i < prefix.size()) {
            if (!curr->childNode[prefix[i]-'a']) {
                return false;
            }
            curr = curr->childNode[prefix[i]-'a'];
            ++i;
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