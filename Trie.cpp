#include "Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}
void Trie::insert(string word)
{
    TrieNode* current = root;

    for (char c : word)
    {
        if (current->children.find(c) == current->children.end())
        {
            current->children[c] = new TrieNode();
        }

        current = current->children[c];
    }

    current->isEnd = true;
}
bool Trie::search(string word)
{
    TrieNode* current = root;

    for (char c : word)
    {
        if (current->children.find(c) == current->children.end())
        {
            return false;
        }

        current = current->children[c];
    }

    return current->isEnd;
}
void Trie::displayWords(TrieNode* node, string word)
{
    if (node->isEnd)
    {
        cout << word << endl;
    }

    for (auto child : node->children)
    {
        displayWords(child.second, word + child.first);
    }
}
void Trie::autoComplete(string prefix)
{
    TrieNode* current = root;

    for (char c : prefix)
    {
        if (current->children.find(c) == current->children.end())
        {
            cout << "No Suggestions Found!" << endl;
            return;
        }

        current = current->children[c];
    }

    cout << "\nSuggestions:\n";

    displayWords(current, prefix);
}