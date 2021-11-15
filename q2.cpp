#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    string sentence;
    int i = 0;

    cout << "Enter a sentence: " << endl;
    getline(cin, sentence);
    
    if (isalpha(sentence[0]) && isalpha(sentence[1]) && isalpha(sentence[2]) && isalpha(sentence[3]) && ((sentence[i+4] == ' ') || (sentence[i+4] == '\0'))) {
        
        if (isupper(sentence[0])) {
            sentence[0] = 'L';
        }
        else {
            sentence[0] = 'l';
        }
        sentence[1] = 'o';
        sentence[2] = 'v';
        sentence[3] = 'e';
    }

    while (sentence[i+3] != '\0') {
    if (isalpha(sentence[i]) && isalpha(sentence[i+1]) && isalpha(sentence[i+2]) && isalpha(sentence[i+3]) && (sentence[i-1] == ' ') && ((sentence[i+4] == ' ') || (sentence[i+4] == '\0'))) {
        
        if (isupper(sentence[i])) {
            sentence[i] = 'L';
        }
        else {
            sentence[i] = 'l';
        }
        sentence[i+1] = 'o';
        sentence[i+2] = 'v';
        sentence[i+3] = 'e';
    }
    i++;
    }

    cout << sentence << endl;

    return 0;
}
