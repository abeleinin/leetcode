#include <string>
#include <array>

using namespace std;

class Trie {
public:
    array<Trie*, 26> child;
    bool terminal;
    string val;

    Trie() {
        child = {};
        terminal = false;
    }
};

bool sub_search(const string& word, int i, Trie* trie);

bool dfs(const string& word, array<Trie*, 26> children) {
    bool res = false;
    for (int i = 0; i < 26; i++) {
        if (!(children[i] == nullptr)) {
            res = sub_search(word, 0, children[i]);
            if (res) return res;
        }
    }
    return false;
}

bool sub_search(const string& word, int i, Trie* trie) {
    Trie* curr = trie;
    char c;
    while (i < word.size()) {
        c = word[i];
        if (c == '.') {
            ++i;
            return dfs(word.substr(i, word.size()-i), curr->child);
        } else if (curr->child[c-'a'] == nullptr) {
            return false;
        }
        curr = curr->child[c-'a'];
        ++i;
    }

    return curr->terminal;
}

class WordDictionary {
public:
    Trie* root;

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->child[word[i]-'a']) {
                curr->child[word[i]-'a'] = new Trie();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->val = word;
        curr->terminal = true;
    }
    
    bool search(string word) {
        return sub_search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */