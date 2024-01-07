#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode('\0');
    }
    void insertWord(string s)
    {
        if (s.length() == 0)
        {
            root->isTerminal = true;
        }
        int index = s[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(s[0]);
            root->children[index] = child;
        }
        insertWord(s.substr(1));
    }
    bool search(string s)
    {
        if (s.length() == 0)
        {
            return root->isTerminal;
        }
        int index = s[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        search(s.substr(1));
    }
};
int main()
{
    Trie *t;
    t->insertWord("neha");
    t->insertWord("garg");
    return 0;
}