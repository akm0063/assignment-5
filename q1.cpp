#include <iostream>
#include <string>

using namespace std;

int main() {
    // sentecne can be up to 100 characters - leave space for newline  
    char sentence[101];
    char output[101];

    // get the user input sentence
    cout << "Enter a sentence: " << endl;
    cin.getline(sentence, 101);
    
    //set all characters to lowercase
    int i = 0;
    while (sentence[i] != '\0') {
        sentence[i] = tolower(sentence[i]);
        i++;
    }

    // set first character to uppercase
    sentence[0] = toupper(sentence[0]);

    // check for double spaces
    int j = 0;
    int k =0;
    while (sentence[j] != '\0') {
       if ((sentence[j] == ' ') && (sentence[j-1] == ' ')) {
               output[k] = sentence[j+1];
               j = j + 2;
               k++;
           }
        else {
            output[k] = sentence[j];
            j++;
            k++;
        }
    }

    //add period to end of sentence
    if (i < 101 && output[k-1] != '.') {
        output[k] = '.';
    }
    
    // output the finished sentence
    cout << "The sentence you entered is: \n" << output << endl;

    return 0;
}