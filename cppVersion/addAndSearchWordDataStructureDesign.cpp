#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct TrieNode {
    char content;
    bool isword;
    vector<TrieNode*> children;

    TrieNode(): TrieNode(' ') {}

    TrieNode(char ch): content(ch), isword(false) {}    

    TrieNode* searchChild(char ch) {
        if(children.empty()) return NULL;
        
        for(auto c : children) {
            if(c->content == ch) return c;
        }
        return NULL;
    }

    bool isWord() {
        return isword;
    }
};


class WordDictonary {
private:
    TrieNode* root;

public:

    WordDictonary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        if(search(word)) return;

        TrieNode* curr = root;

        for(auto w : word) {
            TrieNode* t = curr->searchChild(w);
            if(t) {
                curr = t;
            } else {
                TrieNode* newNode = new TrieNode(w);
                curr->children.push_back(newNode);
                curr = newNode;
            }
        }
        curr->isword = true;
    }

    bool search(string word) {
        if(word.empty()) return true;

        deque<TrieNode*> curr = {root};
        for(auto w : word) {
            if(curr.empty()) return false; 
            if(w == '.') {
                deque<TrieNode*> tmp;
                for(auto c : curr) {
                    if(!c->children.empty())
                        tmp.insert(tmp.end(), c->children.begin(), c->children.end());
                }
                curr.erase(curr.begin(), curr.end());
                curr.insert(curr.begin(), tmp.begin(), tmp.end());
            } else if(w != '.') {
                deque<TrieNode*> tmp;
                for(auto c : curr) {
                    TrieNode* t = c->searchChild(w);
                    if(t) tmp.push_back(t);
                }
                curr.erase(curr.begin(), curr.end());
                curr.insert(curr.begin(), tmp.begin(), tmp.end());
            }
        }
        for(auto c : curr) {
            if(c->isWord()) return true;
        }
        return false;
    }

};


int main() {
    WordDictonary test;
    test.addWord("sking");
    cout<<test.search("..ing")<<">"<<endl;
}
