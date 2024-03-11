
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

bool isValid(string& messg, char& choice);

int main() {
    //  Author and ID: Bassant Ahmed Talat Mohamed - 2023009

    // List to make Cipher and Decipher
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string cipher[26] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};

    while (true) {
        cout << "\n\nWelcome to Baconian Cipher\n";
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        choice = toupper(choice); // To accept small letter

        string messg;
        cin.ignore();

        while (choice == 'A' || choice == 'B') {    
            cout << "Enter your message: ";
            getline(cin, messg);

            // Error messages if messge is wrong
            if (!isValid(messg, choice) && choice == 'A'){
                cout << "\n** All letters must be capital **\n\n";
                continue;
            }
            else if (!isValid(messg, choice) && choice == 'B'){
                cout << "\n** Letters must be 'a' or 'b' only in groups of five digits **\n\n";
                continue;
            }

            if (choice == 'A') {
                cout << "\nYour cipher message:";
                // To get the character number in the list and get its counterpart in encryption
                for (int i = 0; i < messg.length(); i++) { 
                    for (int g = 0; g < 26; g++)
                        if (messg[i] == letters[g])
                            cout << " " << cipher[g];
                }

            } else if (choice == 'B') {
                string one_word="";  // To save all five letters in it 
                cout << "\nYour Decipher message:";
                // To get the encryption number in the list and get its counterpart in the letters 
                for (int k = 0; k < messg.length(); k++) {
                    one_word += messg[k];
                    if (one_word.length() == 5) {   // To take all five letters together
                        for (int i = 0; i < 26; i++) {
                            if (one_word == cipher[i])
                                cout << " " << letters[i];
                        }
                        one_word.clear();   // Make it empty to take next five letters
                    }
                }
            }
        }
        if (choice == 'C') {
            cout << "\nExiting ...\n";
            break;
        } else if (choice != 'A' && choice != 'B' && choice != 'C')
            cout << "\n** This is an invalid choice **\n ";
    }
    return 0;
}

// chack the letter in message is correct 
bool isValid(string& messg, char& choice) {
    messg.erase(remove_if(messg.begin(), messg.end(), ::isspace), messg.end()); // To remove space 

    for (int h = 0; h < messg.length(); h++) {
        char letter = messg[h];
        if (choice == 'A') {
            // A => 65 and Z => 90 any thing not in [65,90] is not a capilal letter
            if (int(letter) > 90 || int(letter) < 65 )  
                return false;
        }
        if (choice == 'B') {
            // chack all letter is a or b only and all 5 letter reprisent a letter
            if (letter != 'a' && letter != 'b' || messg.length()% 5 != 0) 
                return false;
        }
    }
    return true; 
}