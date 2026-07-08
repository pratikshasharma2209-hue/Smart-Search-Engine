#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <unordered_map>
#include <string>

#include "Document.h"
#include "Trie.h"
#include "History.h"
#include "Trending.h"
#include "SpellChecker.h"

using namespace std;

class SearchEngine
{
private:
    // Stores all documents
    vector<Document> documents;

    // Inverted Index
    unordered_map<string, vector<int>> index;

    // DSA Components
    Trie trie;
    History history;
    Trending trending;
    SpellChecker spellChecker;

public:
    // Document Management
    void addDocument();
    void displayDocuments();
    void deleteDocument();
    void updateDocument();

    // File Handling
    void saveDocuments();
    void loadDocuments();

    // Indexing
    void buildIndex();

    // Searching
    void searchWord();
    void searchMultipleWords();
    void rankedSearch();

    // Trie
    void autoComplete();

    // Queue
    void displayHistory();

    // Heap
    void showTrending();

    // Dynamic Programming
    void spellCheck();
};

#endif