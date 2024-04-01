// encrypting a string
#include <iostream>
#include <string>
using namespace std;

int main() {
    string user_input;
    cout << "Enter a string: ";
    getline(cin, user_input);
    // find the smallest letter in string
    int smallest = user_input.length();
    int last = 0;
    int size = 0;
    for (int i = 0; i < user_input.length(); i++) {
        if (user_input[i] == ' ' || user_input[i] == '\n' || i == user_input.length() - 1){
            if(i == user_input.length() - 1){
                size = i - last + 1;
            } else {
            size = i - last;
            last = i + 1;
            }
            if (size < smallest) {
                smallest = size;
            }
        }
    }

    //reverse the string
    string reverse = "";
    for (int i = user_input.length() - 1; i >= 0; i--) {
        if(user_input[i] == ' ' ){
            reverse += to_string(smallest);
            continue;
        }
        reverse += user_input[i];
    }
    
    //append the smallest letter to the start of the string
    string encrypted = to_string(smallest) + reverse;
    cout << "Encrypted: " << encrypted << endl;
    return 0;
}