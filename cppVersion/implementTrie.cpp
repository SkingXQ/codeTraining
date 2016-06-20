/*
    Link: https://leetcode.com/problems/implement-trie-prefix-tree/
    Discuss: 1. https://leetcode.com/discuss/35136/c-my-solution-easy-to-understand  
             2. https://leetcode.com/discuss/92069/c-52ms-solution-linked-list-children

    Tips: solution 1. indicate that the children will be restore in a vector. some flag to figure out whether is the string in the tree;
          solution 2. using the data structure : TrieNode (next; silding;val; isword(I think the coder is missing this flag))
                      First, I prefer to add a function: searchChild to TrieNode so that the  search, insert and startWith will be more
                      easy understanding.
*/

#include<iostream>
#include<vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool isend;
    char content;
    int shared;//It can be displace with children.size()
    vector<TrieNode*> children;
    
    TrieNode(): TrieNode(' ') {}
    
    TrieNode(char c): content(c), isend(false), shared(0) {}
    
    TrieNode* searchChild(char c) {
        if(!children.empty()) {
            for(auto ch : children){
                if(ch->content == c)
                    return ch;
            }
        }
        return NULL;
    }
    
    ~TrieNode() {
        for(auto ch : children)
            delete ch;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(search(word)) return;
        TrieNode* curr = root;
        for(auto ch : word) {
            TrieNode* child = curr->searchChild(ch);
            if(child) {
                curr = child;
            } else {
                TrieNode* newNode = new TrieNode(ch);
                curr->children.push_back(newNode);
                curr = newNode;
            }
            ++curr->shared;
        }
        curr->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(!word.size()) return true;
        
        TrieNode* curr = root;
        for(auto ch : word){
            curr = curr->searchChild(ch);
            if(!curr)
                return false;
        }
        
        return curr->isend == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(!prefix.size()) return true;
        
        TrieNode* curr = root;
        for(auto ch : prefix){
            curr = curr->searchChild(ch);
            if(!curr)
                return false;
        }
        
        return true;        
    }
    
    ~Trie() {
        delete root;
    }

private:
    TrieNode* root;
};


int main() {
    Trie a;
    a.insert("sking");
    return 0;
}
