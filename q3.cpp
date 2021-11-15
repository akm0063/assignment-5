#include <fstream>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

void sort(ifstream &input1, ifstream &input2, ofstream &output) {   

    int num1, num2;
    bool more = true;
    bool num1Written = true;
    bool num2Written = true;

    if(input1.eof() || input2.eof()) {
        more = false;
    }

    while(more) {
        
        if(num1Written == true) {
            input1 >> num1;
            num1Written = false;      
        }
    
        if(num2Written == true) {
            input2 >> num2;
            num2Written = false;
        }
    
        if(num1 < num2) {
            output << num1 << " ";
            num1Written = true; 
        }
        else { 
            output << num2 << " ";
            num2Written = true;
        }

        if(input1.eof() || input2.eof()) { 
            more = false;
        }
    }
    
    do {
        if(num1Written == false) {
            if(!input1.eof()) {
                do {
                    output << num1 << " ";
                    input1 >> num1; 
                } while(!input1.eof());
                output << num1 << " ";
                num1Written = true;
            }
            else {
                input2 >> num2;
                if(num1 < num2) {
                    output << num1 << " ";
                    num1Written = true;
                    num2Written = false;
                }
                else {
                    output << num2 << " ";
                    num1Written = false;
                    num2Written = true;
                }
            }
        }

        if(num2Written == false) {
            if(!input2.eof()) {
                do {
                    output << num2 << " ";
                    input2 >> num2; 
                } while(!input2.eof());
                output << num2 << " ";
                num2Written = true;
            }
            else {
                input1 >> num1;
                if(num1 > num2) {
                    output << num2 << " ";
                    num2Written = true;
                    num1Written = false;
                }
                else {
                    output << num1 << " ";
                    num2Written = false;
                    num1Written = true;
                }
            }
        }
    } while(!input1.eof() || !input2.eof());

    if(num1Written == false) { 
        output << num1;
    }

    if(num2Written == false) {
        output << num2;
    }
}

int main() {

    ifstream input1, input2;
    ofstream output;
    
    input1.open("file1.txt");
    input2.open("file2.txt");
    output.open("file3.txt");
    
    sort(input1, input2, output);
    
    input1.close();
    input2.close();
    output.close();
    
    return 0;
}