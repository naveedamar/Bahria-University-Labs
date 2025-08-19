#include <iostream>
#include <string>
using namespace std;

int main() {
    string message, oldWord, newWord;
    string updatedMessage = "";

    cout << "Enter the message for your greeting card: ";
    getline(cin, message);

    cout << "Enter the word to be replaced: ";
    cin >> oldWord;

    cout << "Enter the new word: ";
    cin >> newWord;

    int i = 0;
    while (i < message.length()) {
        string word = "";
        string punctuation = "";

        while (i < message.length() && message[i] != ' ') {
            if (ispunct(message[i]) && i == message.length() - 1) {
                punctuation = message[i];
                break;
            }
            word += message[i];
            i++;
        }

        if (!word.empty() && ispunct(word.back())) {
            punctuation = word.back();
            word.pop_back();
        }

        if (word == oldWord) {
            updatedMessage += newWord;
        } else {
            updatedMessage += word;
        }

        updatedMessage += punctuation;

        if (i < message.length()) {
            updatedMessage += " ";
        }

        i++;
    }

    cout << "The updated message is: " << updatedMessage << endl;
    return 0;
}