#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    bool capitalize = true;
    
    for (int i = 0; i < sentence.length(); i++) {
        if (capitalize && isalpha(sentence[i])) {
            sentence[i] = toupper(sentence[i]);
            capitalize = false;
        } else {
            sentence[i] = tolower(sentence[i]);
        }

        if (sentence[i] == ' ') {
            capitalize = true;
        }
    }

    cout << "Modified sentence: " << sentence << endl;
}