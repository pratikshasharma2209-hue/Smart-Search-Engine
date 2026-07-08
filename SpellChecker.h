#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <vector>
#include <string>

using namespace std;

class SpellChecker
{
private:
    vector<string> dictionary;

public:
    void addWord(string word);

    int editDistance(string a, string b);

    void suggestWord(string word);
};

#endif