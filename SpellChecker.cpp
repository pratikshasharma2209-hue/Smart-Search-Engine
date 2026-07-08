#include "SpellChecker.h"
#include <iostream>
#include <algorithm>

using namespace std;

void SpellChecker::addWord(string word)
{
    dictionary.push_back(word);
}
int SpellChecker::editDistance(string a, string b)
{
    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                });
            }
        }
    }

    return dp[m][n];
}
void SpellChecker::suggestWord(string word)
{
    int bestDistance = 1000;
    string bestWord = "";

    for (string dictWord : dictionary)
    {
        int distance = editDistance(word, dictWord);

        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestWord = dictWord;
        }
    }

    if (bestDistance <= 2)
    {
        cout << "Did you mean: " << bestWord << endl;
    }
    else
    {
        cout << "No suggestion found." << endl;
    }
}