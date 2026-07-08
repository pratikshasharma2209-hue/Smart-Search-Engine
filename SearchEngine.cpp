#include "SearchEngine.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <set>

using namespace std;
string toLower(string word)
{
    for (char &c : word)
    {
        c = tolower(c);
    }

    return word;
}
void SearchEngine::addDocument()
{
    int id;
    string title;
    string content;

    cout << "Enter Document ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Document Title: ";
    getline(cin, title);

    cout << "Enter Document Content: ";
    getline(cin, content);

    Document doc(id, title, content);

    documents.push_back(doc);

    cout << "\nDocument Added Successfully!\n";
}
void SearchEngine::displayDocuments()
{
    if (documents.empty())
    {
        cout << "\nNo Documents Available.\n";
        return;
    }

    cout << "\n===== Documents =====\n";

    for (Document doc : documents)
    {
        cout << "ID      : " << doc.id << endl;
        cout << "Title   : " << doc.title << endl;
        cout << "Content : " << doc.content << endl;
        cout << "---------------------------\n";
    }
}
void SearchEngine::saveDocuments()
{
    ofstream file("documents.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    for (Document doc : documents)
    {
        file << doc.id << endl;
        file << doc.title << endl;
        file << doc.content << endl;
    }

    file.close();

    cout << "\nDocuments Saved Successfully!\n";
}
void SearchEngine::loadDocuments()
{
    ifstream file("documents.txt");

    if (!file)
    {
        return;
    }

    documents.clear();

    int id;
    string title;
    string content;

    while (file >> id)
    {
        file.ignore();

        getline(file, title);
        getline(file, content);

        documents.push_back(Document(id, title, content));
    }

    file.close();
}
void SearchEngine::buildIndex()
{
    // Clear old index
    index.clear();

    // Read every document
    for (Document doc : documents)
    {
        stringstream ss(doc.content);

        string word;

        while (ss >> word)
        {
            // Convert to lowercase
            word = toLower(word);

            // Add to inverted index
            index[word].push_back(doc.id);

            // Insert into Trie
            trie.insert(word);

            // Add to spell checker dictionary
            spellChecker.addWord(word);
        }
    }

    cout << "\nIndex Created Successfully!\n";
}
void SearchEngine::searchWord()
{
    string word;

    cout << "\nEnter word to search: ";
    cin >> word;

    // Convert to lowercase
    word = toLower(word);

    // Save in search history
    history.addSearch(word);

    // Update trending searches
    trending.addSearch(word);

    // Check if the word exists
    if (index.find(word) == index.end())
    {
        cout << "\nNo Document Found!\n";
        return;
    }

    cout << "\n===== Search Results =====\n";

    // Display matching documents
    for (int id : index[word])
    {
        for (Document doc : documents)
        {
            if (doc.id == id)
            {
                cout << "\nID      : " << doc.id << endl;
                cout << "Title   : " << doc.title << endl;
                cout << "Content : " << doc.content << endl;
                cout << "---------------------------\n";
            }
        }
    }
}
void SearchEngine::autoComplete()
{
    string prefix;

    cout << "\nEnter prefix: ";
    cin >> prefix;

    // Convert to lowercase
    prefix = toLower(prefix);

    // Display suggestions from Trie
    trie.autoComplete(prefix);
}
void SearchEngine::displayHistory()
{
    history.displayHistory();
}
void SearchEngine::showTrending()
{
    trending.showTrending();
}
void SearchEngine::spellCheck()
{
    string word;

    cout << "\nEnter word: ";
    cin >> word;

    // Convert to lowercase
    word = toLower(word);

    // Suggest the closest matching word
    spellChecker.suggestWord(word);
}
void SearchEngine::searchMultipleWords()
{
    cin.ignore();

    string input;

    cout << "\nEnter words: ";
    getline(cin, input);

    stringstream ss(input);

    string word;
    vector<string> words;

    while (ss >> word)
    {
        word = toLower(word);
        words.push_back(word);
    }

    if (words.empty())
    {
        cout << "No words entered.\n";
        return;
    }

    set<int> result;

    // Store document IDs of the first word
    if (index.find(words[0]) != index.end())
    {
        for (int id : index[words[0]])
        {
            result.insert(id);
        }
    }
    else
    {
        cout << "No matching documents found.\n";
        return;
    }

    // Find common document IDs
    for (int i = 1; i < words.size(); i++)
    {
        set<int> current;

        if (index.find(words[i]) != index.end())
        {
            for (int id : index[words[i]])
            {
                current.insert(id);
            }
        }

        set<int> intersection;

        for (int id : result)
        {
            if (current.find(id) != current.end())
            {
                intersection.insert(id);
            }
        }

        result = intersection;
    }

    if (result.empty())
    {
        cout << "\nNo matching documents found.\n";
        return;
    }

    cout << "\n===== Matching Documents =====\n";

    for (int id : result)
    {
        for (Document doc : documents)
        {
            if (doc.id == id)
            {
                cout << "\nID      : " << doc.id << endl;
                cout << "Title   : " << doc.title << endl;
                cout << "Content : " << doc.content << endl;
                cout << "---------------------------\n";
            }
        }
    }
}
void SearchEngine::rankedSearch()
{
    string word;

    cout << "\nEnter word to search: ";
    cin >> word;

    word = toLower(word);

    if (index.find(word) == index.end())
    {
        cout << "\nNo Document Found!\n";
        return;
    }

    // Max Heap: (frequency, document ID)
    priority_queue<pair<int, int>> pq;

    for (Document doc : documents)
    {
        stringstream ss(doc.content);

        string temp;
        int count = 0;

        while (ss >> temp)
        {
            temp = toLower(temp);

            if (temp == word)
            {
                count++;
            }
        }

        if (count > 0)
        {
            pq.push({count, doc.id});
        }
    }

    cout << "\n===== Ranked Search Results =====\n";

    while (!pq.empty())
    {
        int frequency = pq.top().first;
        int id = pq.top().second;

        pq.pop();

        for (Document doc : documents)
        {
            if (doc.id == id)
            {
                cout << "\nID      : " << doc.id << endl;
                cout << "Title   : " << doc.title << endl;
                cout << "Content : " << doc.content << endl;
                cout << "Relevance Score : " << frequency << endl;
                cout << "---------------------------\n";
            }
        }
    }
}