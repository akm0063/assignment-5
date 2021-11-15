#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input;
    string answer;
    string question;
    char another;
    
    input.open("answers.txt");

    cout << "Enter a question: " << endl;
    cin >> question;
    getline(input, answer);
    cout << answer << endl;
    
    cout << "Do you want to ask another question? (Y or N): ";
    cin >> another;
    
    while (another == 'Y') {
        cout << "Enter a question: " << endl;
        cin >> question;
        if (!input.eof()) {
            getline(input, answer);
        }
        else {
            input.close();
            input.open("answers.txt");
            getline(input, answer);
        }
        cout << answer << endl;
        cout << "Do you want to ask another question? (Y or N): " << endl;
        cin >> another;
    }
    
    return 0;
}