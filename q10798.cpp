#include <iostream>
#include <string>
using namespace std;

int main() {
    string* input = new string[5];
    int max_input_length = 0;

    for(int i = 0; i < 5; i++) {
        cin >> input[i];
        if(input[i].length() > max_input_length) {
            max_input_length = input[i].length();
        }
    }

    char** inputArr = new char*[5];
    for(int i = 0; i < 5; i++) {
        inputArr[i] = new char[max_input_length];
        for(int j = 0; j < max_input_length; j++) {
            if(j < input[i].length())
                inputArr[i][j] = input[i][j];
            else
                // put . inside to indicate it is empty
                inputArr[i][j] = '.';
        }
    }

    // print the answer
    for(int j = 0; j < max_input_length; j++)
        for(int i = 0; i < 5; i++)
            if(inputArr[i][j] != '.')
                cout << inputArr[i][j];
    
    // delete input
    delete[] input;

    // delete inputArr
    for(int i = 0; i < 5; i++)
        delete[] inputArr[i];
    delete[] inputArr;
    inputArr = nullptr;

    return 0;
}