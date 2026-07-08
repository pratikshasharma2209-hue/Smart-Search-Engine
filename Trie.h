#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode
{
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode* root;

    void displayWords(TrieNode* node, string word);

public:
    Trie();

    void insert(string word);

    bool search(string word);

    void autoComplete(string prefix);
};

#endif