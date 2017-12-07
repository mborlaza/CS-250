#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    bool done = false;

    stack<string> sentence;

    cout << "Enter the next word of the sentence, or UNDO to undo, or DONE to stop." << endl;

    while (!done)
    {
        string word;
        cout << ">> ";
        cin >> word;

        if (word == "UNDO")
        {
            cout << "\t" << "Removed " << sentence.top() << endl;
            sentence.pop();
        }
        else if (word == "DONE")
        {
            break;
        }
        else
        {
            sentence.push(word);
        }
    }

    cout << endl << endl << "Finished sentence: ";

    while (!(sentence.empty()))
    {
        cout << sentence.top() << " ";
        sentence.pop();
    }

    cout << endl;


    system("pause");
    return 0;
}