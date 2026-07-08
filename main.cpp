#include <iostream>
#include "SearchEngine.h"

using namespace std;

int main()
{
    SearchEngine engine;

    engine.loadDocuments();
    engine.buildIndex();

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n      SMART SEARCH ENGINE";
        cout << "\n====================================";
        cout << "\n1. Add Document";
        cout << "\n2. Display Documents";
        cout << "\n3. Build Index";
        cout << "\n4. Search Word";
        cout << "\n5. Search Multiple Words";
        cout << "\n6. Ranked Search";
        cout << "\n7. Auto Complete";
        cout << "\n8. Display Search History";
        cout << "\n9. Trending Searches";
        cout << "\n10. Spell Checker";
        cout << "\n11. Save Documents";
        cout << "\n12. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            engine.addDocument();
            break;

        case 2:
            engine.displayDocuments();
            break;

        case 3:
            engine.buildIndex();
            break;

        case 4:
            engine.searchWord();
            break;

        case 5:
            engine.searchMultipleWords();
            break;

        case 6:
            engine.rankedSearch();
            break;

        case 7:
            engine.autoComplete();
            break;

        case 8:
            engine.displayHistory();
            break;

        case 9:
            engine.showTrending();
            break;

        case 10:
            engine.spellCheck();
            break;

        case 11:
            engine.saveDocuments();
            break;

        case 12:
            engine.saveDocuments();
            cout << "\nThank you for using Smart Search Engine!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 12);

    return 0;
}
